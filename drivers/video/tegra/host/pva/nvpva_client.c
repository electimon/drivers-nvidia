/*
 * Copyright (c) 2021, NVIDIA CORPORATION. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "nvhost_buffer.h"
#include "pva.h"
#include "nvpva_client.h"
#include <linux/slab.h>
/* Maximum contexts KMD creates per engine */
#define NVPVA_CLIENT_MAX_CONTEXTS_PER_ENG (MAX_PVA_CLIENTS)

/* Allocate a buffer pool
 * The function does below things;
 *
 * 1. checks if number of Qs opened exceeds the limit
 *
 * 2. checks if there is pool array already created, (succeeds for first
 * request)
 *
 * 3. If current active and max Qs nums are same, then a new pool need to be
 * allocated.
 */
static int client_context_pool_alloc_locked(struct pva *dev,
					    struct nvpva_client_context *client,
					    pid_t pid)
{
	int32_t err = 0;

	if (client->buffers == NULL) { /* First time creation */
		client->buffers = nvhost_buffer_init(dev->pdev);
		if (IS_ERR(client->buffers)) {
			err = PTR_ERR(client->buffers);
			dev_err(&dev->pdev->dev,
				"failed to init nvhost buffer for client");
			goto err_alloc_buffer;
		}

		/* Create an array with max limit for buffer pool pointers */
	}

	client->active_queue_requests++;
err_alloc_buffer:
	return err;
}

/* Search if the pid already have a context
 * The function does below things;
 * 1. loop through each clients in the client array and validates pid.
 * 2. Also tracks the first free client in the array
 */
static struct nvpva_client_context *
client_context_search_locked(struct pva *dev, pid_t pid)
{
	struct nvpva_client_context *c_node = NULL;
	struct nvpva_client_context *c_free = NULL;
	uint32_t i;

	for (i = 0U; i < NVPVA_CLIENT_MAX_CONTEXTS_PER_ENG; i++) {
		c_node = &dev->clients[i];
		if (c_node->active_queue_requests != 0U) { /* In use */
			if (c_node->pid == pid)
				break;
		} else {
			if (c_free == NULL) {
				c_free = c_node;
				c_free->pid = pid;
			}
		}
		c_node = NULL;
	}

	return (c_node != NULL) ? c_node : c_free;
}

/* Allocate a client context from the client array
 * The function does below things;
 * 1. Search for an existing client context, if not found then a free client
 * 2. Allocate a buffer pool if needed
 */
struct nvpva_client_context *nvpva_client_context_alloc(struct pva *dev,
							pid_t pid)
{
	struct nvpva_client_context *client = NULL;
	int32_t err = 0;

	mutex_lock(&dev->clients_lock);
	client = client_context_search_locked(dev, pid);
	if (client != NULL) {
		err = client_context_pool_alloc_locked(dev, client, pid);
		if (err)
			client = NULL;
	}
	mutex_unlock(&dev->clients_lock);

	return client;
}

/* Free a client context from the client array */
static void
nvpva_client_context_free_locked(struct pva *dev,
				 struct nvpva_client_context *client)
{
	nvhost_buffer_release(client->buffers);
	client->buffers = NULL;
	pva_unload_all_apps(&client->elf_ctx);
}

/* Release the client context
 * The function does below things;
 * 1. Reduce the active Q count
 * 2. Initiate freeing if the count is 0
 */
void nvpva_client_context_free(struct pva *dev,
			       struct nvpva_client_context *client)
{
	mutex_lock(&dev->clients_lock);
	dev_info(&dev->pdev->dev, "client refcount: %d\n",
		 client->active_queue_requests);
	client->active_queue_requests--;
	if (client->active_queue_requests == 0U)
		nvpva_client_context_free_locked(dev, client);
	mutex_unlock(&dev->clients_lock);
}

/* De-initialize the client array for the device
 * The function does below things;
 * 1. Free all the remaining buffer pools if any
 * 2. Release the memory
 */
void nvpva_client_context_deinit(struct pva *dev)
{
	struct nvpva_client_context *client;
	uint32_t max_clients;
	uint32_t i;

	max_clients = NVPVA_CLIENT_MAX_CONTEXTS_PER_ENG;
	if (dev->clients != NULL) {
		mutex_lock(&dev->clients_lock);
		for (i = 0U; i < max_clients; i++) {
			client = &dev->clients[i];
			pva_vpu_deinit(&client->elf_ctx);
		}
		mutex_unlock(&dev->clients_lock);
		mutex_destroy(&dev->clients_lock);
		kfree(dev->clients);
		dev->clients = NULL;
	}
}

/* Initialize a set of clients for the device
 * The function does below things;
 * 1. Allocate memory for maximum number of clients
 * 2. Assign stream ID for each client contexts
 */
int nvpva_client_context_init(struct pva *pva)
{
	struct nvpva_client_context *clients = NULL;
	uint32_t max_clients;
	uint32_t j = 0U;
	int err = 0;

	max_clients = NVPVA_CLIENT_MAX_CONTEXTS_PER_ENG;
	clients = kcalloc(max_clients, sizeof(struct nvpva_client_context),
			  GFP_KERNEL);
	if (clients == NULL) {
		err = -ENOMEM;
		goto done;
	}
	mutex_init(&pva->clients_lock);
	for (j = 0U; j < NVPVA_CLIENT_MAX_CONTEXTS_PER_ENG; j++) {
		err = pva_vpu_init(pva, &clients[j].elf_ctx);
		if (err < 0) {
			dev_err(&pva->pdev->dev,
				"No memory for allocating VPU parsing");
			goto vpu_init_fail;
		}
	}

	pva->clients = clients;
	return err;

vpu_init_fail:
	while (j--)
		pva_vpu_deinit(&clients[j].elf_ctx);

	kfree(clients);
	mutex_destroy(&pva->clients_lock);
done:
	return err;
}

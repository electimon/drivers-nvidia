/*
 * drivers/video/tegra/nvmap/nvmap.h
 *
 * GPU memory management driver for Tegra
 *
 * Copyright (c) 2009-2014, NVIDIA CORPORATION. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *'
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __VIDEO_TEGRA_NVMAP_NVMAP_H
#define __VIDEO_TEGRA_NVMAP_NVMAP_H

#include <linux/list.h>
#include <linux/mm.h>
#include <linux/mutex.h>
#include <linux/rbtree.h>
#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/atomic.h>
#include <linux/dma-buf.h>
#include <linux/syscalls.h>
#include <linux/nvmap.h>

#include <linux/workqueue.h>
#include <linux/dma-mapping.h>
#include <linux/dma-direction.h>
#include <linux/platform_device.h>

#include <asm/cacheflush.h>
#include <asm/tlbflush.h>
#ifndef CONFIG_ARM64
#include <asm/outercache.h>
#endif
#include "nvmap_heap.h"

#ifdef CONFIG_NVMAP_HIGHMEM_ONLY
#define __GFP_NVMAP     __GFP_HIGHMEM
#else
#define __GFP_NVMAP     (GFP_KERNEL | __GFP_HIGHMEM)
#endif

#ifdef CONFIG_NVMAP_FORCE_ZEROED_USER_PAGES
#define NVMAP_ZEROED_PAGES     __GFP_ZERO
#else
#define NVMAP_ZEROED_PAGES     0
#endif

#define GFP_NVMAP              (__GFP_NVMAP | __GFP_NOWARN | NVMAP_ZEROED_PAGES)

#define NVMAP_NUM_PTES		64

#ifdef CONFIG_64BIT
#define NVMAP_LAZY_VFREE
#endif

struct page;

extern const struct file_operations nvmap_fd_fops;
void _nvmap_handle_free(struct nvmap_handle *h);
/* holds max number of handles allocted per process at any time */
extern u32 nvmap_max_handle_count;
extern size_t cache_maint_inner_threshold;

extern struct platform_device *nvmap_pdev;

#if defined(CONFIG_TEGRA_NVMAP)
#define CACHE_MAINT_IMMEDIATE		0
#define CACHE_MAINT_ALLOW_DEFERRED	1

#ifdef CONFIG_ARM64
#define PG_PROT_KERNEL PAGE_KERNEL
#define FLUSH_TLB_PAGE(addr) flush_tlb_kernel_range(addr, PAGE_SIZE)
#define FLUSH_DCACHE_AREA __flush_dcache_area
#define outer_flush_range(s, e)
#define outer_inv_range(s, e)
#define outer_clean_range(s, e)
#define outer_flush_all()
extern void __flush_dcache_page(struct page *);
#else
#define PG_PROT_KERNEL pgprot_kernel
#define FLUSH_TLB_PAGE(addr) flush_tlb_kernel_page(addr)
#define FLUSH_DCACHE_AREA __cpuc_flush_dcache_area
extern void __flush_dcache_page(struct address_space *, struct page *);
#endif

/* handles allocated using shared system memory (either IOVMM- or high-order
 * page allocations */
struct nvmap_pgalloc {
	struct page **pages;
	bool contig;			/* contiguous system memory */
	u32 iovm_addr;	/* is non-zero, if client need specific iova mapping */
};

struct nvmap_handle {
	struct rb_node node;	/* entry on global handle tree */
	atomic_t ref;		/* reference count (i.e., # of duplications) */
	atomic_t pin;		/* pin count */
	unsigned long flags;    /* caching flags */
	size_t size;		/* padded (as-allocated) size */
	size_t orig_size;	/* original (as-requested) size */
	size_t align;
	u8 kind;                /* memory kind (0=pitch, !0 -> blocklinear) */
	struct nvmap_client *owner;

	/*
	 * dma_buf necessities. An attachment is made on dma_buf allocation to
	 * facilitate the nvmap_pin* APIs.
	 */
	struct dma_buf *dmabuf;
	struct dma_buf_attachment *attachment;

	union {
		struct nvmap_pgalloc pgalloc;
		struct nvmap_heap_block *carveout;
	};
	bool global;		/* handle may be duplicated by other clients */
	bool heap_pgalloc;	/* handle is page allocated (sysmem / iovmm) */
	bool alloc;		/* handle has memory allocated */
	unsigned int userflags;	/* flags passed from userspace */
	void *vaddr;		/* mapping used inside kernel */
	struct mutex lock;
	void *nvhost_priv;	/* nvhost private data */
	void (*nvhost_priv_delete)(void *priv);
};

/* handle_ref objects are client-local references to an nvmap_handle;
 * they are distinct objects so that handles can be unpinned and
 * unreferenced the correct number of times when a client abnormally
 * terminates */
struct nvmap_handle_ref {
	struct nvmap_handle *handle;
	struct rb_node	node;
	atomic_t	dupes;	/* number of times to free on file close */
	atomic_t	pin;	/* number of times to unpin on free */
};

#ifdef CONFIG_NVMAP_PAGE_POOLS

struct nvmap_page_pool {
	struct mutex lock;
	u32 alloc;  /* Alloc index. */
	u32 fill;   /* Fill index. */
	u32 count;  /* Number of pages in the table. */
	u32 length; /* Length of the pages array. */
	struct page **page_array;

#ifdef CONFIG_NVMAP_PAGE_POOL_DEBUG
	u64 allocs;
	u64 fills;
	u64 hits;
	u64 misses;
#endif
};

#define pp_empty(pp)				\
	((pp)->fill == (pp)->alloc && !(pp)->page_array[(pp)->alloc])
#define pp_full(pp)				\
	((pp)->fill == (pp)->alloc && (pp)->page_array[(pp)->alloc])

#define nvmap_pp_alloc_inc(pp) nvmap_pp_inc_index((pp), &(pp)->alloc)
#define nvmap_pp_fill_inc(pp)  nvmap_pp_inc_index((pp), &(pp)->fill)

/* Handle wrap around. */
static inline void nvmap_pp_inc_index(struct nvmap_page_pool *pp, u32 *ind)
{
	*ind += 1;

	/* Wrap condition. */
	if (*ind >= pp->length)
		*ind = 0;
}

static inline void nvmap_page_pool_lock(struct nvmap_page_pool *pool)
{
	mutex_lock(&pool->lock);
}

static inline void nvmap_page_pool_unlock(struct nvmap_page_pool *pool)
{
	mutex_unlock(&pool->lock);
}

int nvmap_page_pool_init(struct nvmap_device *dev);
struct page *nvmap_page_pool_alloc(struct nvmap_page_pool *pool);
bool nvmap_page_pool_fill(struct nvmap_page_pool *pool, struct page *page);
int __nvmap_page_pool_alloc_lots_locked(struct nvmap_page_pool *pool,
					struct page **pages, u32 nr);
int __nvmap_page_pool_fill_lots_locked(struct nvmap_page_pool *pool,
				       struct page **pages, u32 nr);
#endif

struct nvmap_carveout_commit {
	size_t commit;
	struct list_head list;
};

struct nvmap_client {
	const char			*name;
	struct rb_root			handle_refs;
	atomic_t			iovm_commit;
	struct mutex			ref_lock;
	bool				kernel_client;
	atomic_t			count;
	struct task_struct		*task;
	struct list_head		list;
	u32				handle_count;
	struct nvmap_carveout_commit	carveout_commit[0];
};

struct nvmap_vma_priv {
	struct nvmap_handle *handle;
	size_t		offs;
	atomic_t	count;	/* number of processes cloning the VMA */
};

#include <linux/mm.h>
#include <linux/miscdevice.h>

struct nvmap_device {
	struct vm_struct *vm_rgn;
	pte_t		*ptes[NVMAP_NUM_PTES];
	unsigned long	ptebits[NVMAP_NUM_PTES / BITS_PER_LONG];
	unsigned int	lastpte;
	spinlock_t	ptelock;

	struct rb_root	handles;
	spinlock_t	handle_lock;
	wait_queue_head_t pte_wait;
	struct miscdevice dev_user;
	struct nvmap_carveout_node *heaps;
	int nr_carveouts;
#ifdef CONFIG_NVMAP_PAGE_POOLS
	struct nvmap_page_pool pool;
#endif
	struct list_head clients;
	spinlock_t	clients_lock;
};

enum nvmap_stats_t {
	NS_ALLOC = 0,
	NS_RELEASE,
	NS_UALLOC,
	NS_URELEASE,
	NS_KALLOC,
	NS_KRELEASE,
	NS_CFLUSH_RQ,
	NS_CFLUSH_DONE,
	NS_UCFLUSH_RQ,
	NS_UCFLUSH_DONE,
	NS_KCFLUSH_RQ,
	NS_KCFLUSH_DONE,
	NS_TOTAL,
	NS_NUM,
};

struct nvmap_stats {
	atomic64_t stats[NS_NUM];
	atomic64_t collect;
};

extern struct nvmap_stats nvmap_stats;

void nvmap_stats_inc(enum nvmap_stats_t, size_t size);
void nvmap_stats_dec(enum nvmap_stats_t, size_t size);
u64 nvmap_stats_read(enum nvmap_stats_t);

static inline void nvmap_ref_lock(struct nvmap_client *priv)
{
	mutex_lock(&priv->ref_lock);
}

static inline void nvmap_ref_unlock(struct nvmap_client *priv)
{
	mutex_unlock(&priv->ref_lock);
}

/*
 * NOTE: this does not ensure the continued existence of the underlying
 * dma_buf. If you want ensure the existence of the dma_buf you must get an
 * nvmap_handle_ref as that is what tracks the dma_buf refs.
 */
static inline struct nvmap_handle *nvmap_handle_get(struct nvmap_handle *h)
{
	if (unlikely(atomic_inc_return(&h->ref) <= 1)) {
		pr_err("%s: %s attempt to get a freed handle\n",
			__func__, current->group_leader->comm);
		atomic_dec(&h->ref);
		return NULL;
	}
	return h;
}

static inline pgprot_t nvmap_pgprot(struct nvmap_handle *h, pgprot_t prot)
{
	if (h->flags == NVMAP_HANDLE_UNCACHEABLE)
		return pgprot_noncached(prot);
	else if (h->flags == NVMAP_HANDLE_WRITE_COMBINE)
		return pgprot_writecombine(prot);
	return prot;
}

#else /* CONFIG_TEGRA_NVMAP */
struct nvmap_handle *nvmap_handle_get(struct nvmap_handle *h);
void nvmap_handle_put(struct nvmap_handle *h);
pgprot_t nvmap_pgprot(struct nvmap_handle *h, pgprot_t prot);

#endif /* !CONFIG_TEGRA_NVMAP */

struct device *nvmap_client_to_device(struct nvmap_client *client);

pte_t **nvmap_alloc_pte(struct nvmap_device *dev, void **vaddr);

pte_t **nvmap_alloc_pte_irq(struct nvmap_device *dev, void **vaddr);

void nvmap_free_pte(struct nvmap_device *dev, pte_t **pte);

pte_t **nvmap_vaddr_to_pte(struct nvmap_device *dev, unsigned long vaddr);

struct nvmap_heap_block *nvmap_carveout_alloc(struct nvmap_client *dev,
					      struct nvmap_handle *handle,
					      unsigned long type);

unsigned long nvmap_carveout_usage(struct nvmap_client *c,
				   struct nvmap_heap_block *b);

struct nvmap_carveout_node;
void nvmap_carveout_commit_add(struct nvmap_client *client,
			       struct nvmap_carveout_node *node, size_t len);

void nvmap_carveout_commit_subtract(struct nvmap_client *client,
				    struct nvmap_carveout_node *node,
				    size_t len);

int nvmap_find_cache_maint_op(struct nvmap_device *dev,
		struct nvmap_handle *h);

void nvmap_handle_put(struct nvmap_handle *h);

struct nvmap_handle_ref *__nvmap_validate_locked(struct nvmap_client *priv,
						 struct nvmap_handle *h);

struct nvmap_handle_ref *nvmap_create_handle(struct nvmap_client *client,
					     size_t size);

struct nvmap_handle_ref *nvmap_duplicate_handle(struct nvmap_client *client,
					struct nvmap_handle *h, bool skip_val);

struct nvmap_handle_ref *nvmap_create_handle_from_fd(
			struct nvmap_client *client, int fd);

int nvmap_alloc_handle(struct nvmap_client *client,
		       struct nvmap_handle *h, unsigned int heap_mask,
		       size_t align, u8 kind,
		       unsigned int flags);

void nvmap_free_handle(struct nvmap_client *c, struct nvmap_handle *h);

void nvmap_free_handle_user_id(struct nvmap_client *c, unsigned long user_id);

int nvmap_pin_ids(struct nvmap_client *client,
		  unsigned int nr, struct nvmap_handle * const *ids);

void nvmap_unpin_ids(struct nvmap_client *priv,
		     unsigned int nr, struct nvmap_handle * const *ids);

int nvmap_handle_remove(struct nvmap_device *dev, struct nvmap_handle *h);

void nvmap_handle_add(struct nvmap_device *dev, struct nvmap_handle *h);

int is_nvmap_vma(struct vm_area_struct *vma);

int nvmap_get_dmabuf_fd(struct nvmap_client *client, struct nvmap_handle *h);
struct nvmap_handle *nvmap_get_id_from_dmabuf_fd(struct nvmap_client *client,
						 int fd);

int nvmap_get_handle_param(struct nvmap_client *client,
		struct nvmap_handle_ref *ref, u32 param, u64 *result);

struct nvmap_client *nvmap_client_get(struct nvmap_client *client);

void nvmap_client_put(struct nvmap_client *c);

struct nvmap_handle *unmarshal_user_id(u32 id);

static inline void nvmap_flush_tlb_kernel_page(unsigned long kaddr)
{
#ifdef CONFIG_ARM_ERRATA_798181
	flush_tlb_kernel_page_skip_errata_798181(kaddr);
#else
	FLUSH_TLB_PAGE(kaddr);
#endif
}

/* MM definitions. */
extern size_t cache_maint_outer_threshold;
extern int inner_cache_maint_threshold;

extern void v7_flush_kern_cache_all(void);
extern void v7_clean_kern_cache_all(void *);
extern void __flush_dcache_all(void *arg);

void inner_flush_cache_all(void);
void inner_clean_cache_all(void);
void nvmap_flush_cache(struct page **pages, int numpages);

int nvmap_flush_cache_list(struct nvmap_handle **handles, int nr);

/* Internal API to support dmabuf */
struct dma_buf *__nvmap_dmabuf_export(struct nvmap_client *client,
				 struct nvmap_handle *handle);
struct dma_buf *__nvmap_make_dmabuf(struct nvmap_client *client,
				    struct nvmap_handle *handle);
struct sg_table *__nvmap_sg_table(struct nvmap_client *client,
				  struct nvmap_handle *h);
void __nvmap_free_sg_table(struct nvmap_client *client,
			   struct nvmap_handle *h, struct sg_table *sgt);
void *__nvmap_kmap(struct nvmap_handle *h, unsigned int pagenum);
void __nvmap_kunmap(struct nvmap_handle *h, unsigned int pagenum, void *addr);
void *__nvmap_mmap(struct nvmap_handle *h);
void __nvmap_munmap(struct nvmap_handle *h, void *addr);
int __nvmap_map(struct nvmap_handle *h, struct vm_area_struct *vma);
int __nvmap_get_handle_param(struct nvmap_client *client,
			     struct nvmap_handle *h, u32 param, u64 *result);
int __nvmap_do_cache_maint(struct nvmap_client *client, struct nvmap_handle *h,
			   unsigned long start, unsigned long end,
			   unsigned int op, unsigned int allow_deferred);
struct nvmap_client *__nvmap_create_client(struct nvmap_device *dev,
					   const char *name);
struct dma_buf *__nvmap_dmabuf_export_from_ref(struct nvmap_handle_ref *ref);
struct nvmap_handle *__nvmap_ref_to_id(struct nvmap_handle_ref *ref);
int __nvmap_pin(struct nvmap_handle_ref *ref, phys_addr_t *phys);
void __nvmap_unpin(struct nvmap_handle_ref *ref);
int __nvmap_dmabuf_fd(struct dma_buf *dmabuf, int flags);

void nvmap_dmabuf_debugfs_init(struct dentry *nvmap_root);
int nvmap_dmabuf_stash_init(void);

#endif /* __VIDEO_TEGRA_NVMAP_NVMAP_H */

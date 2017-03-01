/*
 * Copyright (c) 2016-2017, NVIDIA Corporation.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

struct nvhost_streamid_mapping {
	u32 host1x_offset;
	u32 client_offset;
	u32 client_limit;
};

static struct nvhost_streamid_mapping __attribute__((__unused__))
	t19x_host1x_streamid_mapping[] = {
	/* HOST1X_THOST_COMMON_SE1_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001ac8, 0x00000090, 0x00000090},
	/* HOST1X_THOST_COMMON_SE2_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001ad0, 0x00000090, 0x00000090},
	/* HOST1X_THOST_COMMON_SE3_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001ad8, 0x00000090, 0x00000090},
	/* HOST1X_THOST_COMMON_SE4_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001ae0, 0x00000090, 0x00000090},
	/* HOST1X_THOST_COMMON_ISP_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001ae8, 0x00000050, 0x00000050},
	/* HOST1X_THOST_COMMON_VIC_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001af0, 0x00000030, 0x00000034},
	/* HOST1X_THOST_COMMON_NVENC_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001af8, 0x00000030, 0x00000034},
	/* HOST1X_THOST_COMMON_NVDEC_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001b00, 0x00000030, 0x00000034},
	/* HOST1X_THOST_COMMON_NVJPG_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001b08, 0x00000030, 0x00000034},
	/* HOST1X_THOST_COMMON_TSEC_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001b10, 0x00000030, 0x00000034},
	/* HOST1X_THOST_COMMON_TSECB_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001b18, 0x00000030, 0x00000034},
	/* HOST1X_THOST_COMMON_VI_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001b80, 0x00010000, 0x00010000},
	/* HOST1X_THOST_COMMON_PVA0_CLUSTER_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001b88, 0x00000000, 0x00000000 },
	/* HOST1X_THOST_COMMON_PVA1_CLUSTER_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001b90, 0x00000000, 0x00000000 },
	/* HOST1X_THOST_COMMON_NVDLA0_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001b98, 0x00000030, 0x00000034 },
	/* HOST1X_THOST_COMMON_NVDLA1_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001ba0, 0x00000030, 0x00000034 },
	/* HOST1X_THOST_COMMON_NVENC1_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001ba8, 0x00000030, 0x00000034 },
	/* HOST1X_THOST_COMMON_NVDEC1_STRMID_0_OFFSET_BASE_0 */
	{ 0x00001bb0, 0x00000030, 0x00000034 },
	{}
};

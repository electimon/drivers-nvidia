/*
 * tegra210_admaif_alt.h - Tegra ADMAIF registers
 *
 * Copyright (c) 2014-2019 NVIDIA CORPORATION.  All rights reserved.
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

#ifndef __TEGRA_ADMAIF_ALT_H__
#define __TEGRA_ADMAIF_ALT_H__

#define TEGRA_ADMAIF_CHANNEL_REG_STRIDE		0x40

#define TEGRA210_ADMAIF_LAST_REG		0x75f
#define TEGRA186_ADMAIF_LAST_REG		0xd5f

#define TEGRA210_ADMAIF_CHANNEL_COUNT		10
#define TEGRA186_ADMAIF_CHANNEL_COUNT		20

#define TEGRA210_ADMAIF_XBAR_RX_BASE		0x0
#define TEGRA210_ADMAIF_XBAR_TX_BASE		0x300
#define TEGRA210_ADMAIF_GLOBAL_BASE		0x700

#define TEGRA186_ADMAIF_XBAR_RX_BASE		0x0
#define TEGRA186_ADMAIF_XBAR_TX_BASE		0x500
#define TEGRA186_ADMAIF_GLOBAL_BASE		0xd00

#define TEGRA_ADMAIF_XBAR_RX_ENABLE		0x0
#define TEGRA_ADMAIF_XBAR_RX_SOFT_RESET		0x4
#define TEGRA_ADMAIF_XBAR_RX_STATUS		0xc
#define TEGRA_ADMAIF_XBAR_RX_INT_STATUS		0x10
#define TEGRA_ADMAIF_XBAR_RX_INT_MASK		0x14
#define TEGRA_ADMAIF_XBAR_RX_INT_SET		0x18
#define TEGRA_ADMAIF_XBAR_RX_INT_CLEAR		0x1c
#define TEGRA_ADMAIF_CHAN_ACIF_RX_CTRL		0x20
#define TEGRA_ADMAIF_XBAR_RX_FIFO_CTRL		0x28
#define TEGRA_ADMAIF_XBAR_RX_FIFO_READ		0x2c
#define TEGRA_ADMAIF_GLOBAL_ENABLE		0x0
#define TEGRA_ADMAIF_GLOBAL_CG_0		0x8
#define TEGRA_ADMAIF_GLOBAL_STATUS		0x10
#define TEGRA_ADMAIF_GLOBAL_RX_ENABLE_STATUS	0x20
#define TEGRA_ADMAIF_GLOBAL_TX_ENABLE_STATUS	0x24

#define TEGRA_ADMAIF_XBAR_TX_ENABLE		0x0
#define TEGRA_ADMAIF_XBAR_TX_SOFT_RESET		0x4
#define TEGRA_ADMAIF_XBAR_TX_STATUS		0xc
#define TEGRA_ADMAIF_XBAR_TX_INT_STATUS		0x10
#define TEGRA_ADMAIF_XBAR_TX_INT_MASK		0x14
#define TEGRA_ADMAIF_XBAR_TX_INT_SET		0x18
#define TEGRA_ADMAIF_XBAR_TX_INT_CLEAR		0x1c
#define TEGRA_ADMAIF_CHAN_ACIF_TX_CTRL		0x20
#define TEGRA_ADMAIF_XBAR_TX_FIFO_CTRL		0x28
#define TEGRA_ADMAIF_XBAR_TX_FIFO_WRITE		0x2c

#define TEGRA_ADMAIF_CHAN_ACIF_CTRL_PACK8_EN_SHIFT		31
#define TEGRA_ADMAIF_CHAN_ACIF_CTRL_PACK8_EN_MASK		\
			(1 << TEGRA_ADMAIF_CHAN_ACIF_CTRL_PACK8_EN_SHIFT)
#define TEGRA_ADMAIF_CHAN_ACIF_CTRL_PACK8_EN			\
			(1 << TEGRA_ADMAIF_CHAN_ACIF_CTRL_PACK8_EN_SHIFT)
#define TEGRA_ADMAIF_CHAN_ACIF_CTRL_PACK16_EN_SHIFT		30
#define TEGRA_ADMAIF_CHAN_ACIF_CTRL_PACK16_EN_MASK		\
			(1 << TEGRA_ADMAIF_CHAN_ACIF_CTRL_PACK16_EN_SHIFT)
#define TEGRA_ADMAIF_CHAN_ACIF_CTRL_PACK16_EN			\
			(1 << TEGRA_ADMAIF_CHAN_ACIF_CTRL_PACK16_EN_SHIFT)

#define TEGRA_ADMAIF_XBAR_TX_ENABLE_SHIFT	0
#define TEGRA_ADMAIF_XBAR_TX_EN			\
			(1 << TEGRA_ADMAIF_XBAR_TX_ENABLE_SHIFT)
#define TEGRA_ADMAIF_XBAR_TX_ENABLE_MASK	\
			(1 << TEGRA_ADMAIF_XBAR_TX_ENABLE_SHIFT)

#define TEGRA_ADMAIF_XBAR_RX_ENABLE_SHIFT	0
#define TEGRA_ADMAIF_XBAR_RX_EN			\
			(1 << TEGRA_ADMAIF_XBAR_RX_ENABLE_SHIFT)
#define TEGRA_ADMAIF_XBAR_RX_ENABLE_MASK	\
			(1 << TEGRA_ADMAIF_XBAR_RX_ENABLE_SHIFT)

#define TEGRA210_ADMAIF_RX1_FIFO_CTRL_REG_DEFAULT 0x00000300
#define TEGRA210_ADMAIF_RX2_FIFO_CTRL_REG_DEFAULT 0x00000304
#define TEGRA210_ADMAIF_RX3_FIFO_CTRL_REG_DEFAULT 0x00000208
#define TEGRA210_ADMAIF_RX4_FIFO_CTRL_REG_DEFAULT 0x0000020b
#define TEGRA210_ADMAIF_RX5_FIFO_CTRL_REG_DEFAULT 0x0000020e
#define TEGRA210_ADMAIF_RX6_FIFO_CTRL_REG_DEFAULT 0x00000211
#define TEGRA210_ADMAIF_RX7_FIFO_CTRL_REG_DEFAULT 0x00000214
#define TEGRA210_ADMAIF_RX8_FIFO_CTRL_REG_DEFAULT 0x00000217
#define TEGRA210_ADMAIF_RX9_FIFO_CTRL_REG_DEFAULT 0x0000021a
#define TEGRA210_ADMAIF_RX10_FIFO_CTRL_REG_DEFAULT 0x0000021d

#define TEGRA210_ADMAIF_TX1_FIFO_CTRL_REG_DEFAULT 0x02000300
#define TEGRA210_ADMAIF_TX2_FIFO_CTRL_REG_DEFAULT 0x02000304
#define TEGRA210_ADMAIF_TX3_FIFO_CTRL_REG_DEFAULT 0x01800208
#define TEGRA210_ADMAIF_TX4_FIFO_CTRL_REG_DEFAULT 0x0180020b
#define TEGRA210_ADMAIF_TX5_FIFO_CTRL_REG_DEFAULT 0x0180020e
#define TEGRA210_ADMAIF_TX6_FIFO_CTRL_REG_DEFAULT 0x01800211
#define TEGRA210_ADMAIF_TX7_FIFO_CTRL_REG_DEFAULT 0x01800214
#define TEGRA210_ADMAIF_TX8_FIFO_CTRL_REG_DEFAULT 0x01800217
#define TEGRA210_ADMAIF_TX9_FIFO_CTRL_REG_DEFAULT 0x0180021a
#define TEGRA210_ADMAIF_TX10_FIFO_CTRL_REG_DEFAULT 0x0180021d

#define TEGRA186_ADMAIF_RX1_FIFO_CTRL_REG_DEFAULT 0x00000300
#define TEGRA186_ADMAIF_RX2_FIFO_CTRL_REG_DEFAULT 0x00000304
#define TEGRA186_ADMAIF_RX3_FIFO_CTRL_REG_DEFAULT 0x00000308
#define TEGRA186_ADMAIF_RX4_FIFO_CTRL_REG_DEFAULT 0x0000030c
#define TEGRA186_ADMAIF_RX5_FIFO_CTRL_REG_DEFAULT 0x00000210
#define TEGRA186_ADMAIF_RX6_FIFO_CTRL_REG_DEFAULT 0x00000213
#define TEGRA186_ADMAIF_RX7_FIFO_CTRL_REG_DEFAULT 0x00000216
#define TEGRA186_ADMAIF_RX8_FIFO_CTRL_REG_DEFAULT 0x00000219
#define TEGRA186_ADMAIF_RX9_FIFO_CTRL_REG_DEFAULT 0x0000021c
#define TEGRA186_ADMAIF_RX10_FIFO_CTRL_REG_DEFAULT 0x0000021f
#define TEGRA186_ADMAIF_RX11_FIFO_CTRL_REG_DEFAULT 0x00000222
#define TEGRA186_ADMAIF_RX12_FIFO_CTRL_REG_DEFAULT 0x00000225
#define TEGRA186_ADMAIF_RX13_FIFO_CTRL_REG_DEFAULT 0x00000228
#define TEGRA186_ADMAIF_RX14_FIFO_CTRL_REG_DEFAULT 0x0000022b
#define TEGRA186_ADMAIF_RX15_FIFO_CTRL_REG_DEFAULT 0x0000022e
#define TEGRA186_ADMAIF_RX16_FIFO_CTRL_REG_DEFAULT 0x00000231
#define TEGRA186_ADMAIF_RX17_FIFO_CTRL_REG_DEFAULT 0x00000234
#define TEGRA186_ADMAIF_RX18_FIFO_CTRL_REG_DEFAULT 0x00000237
#define TEGRA186_ADMAIF_RX19_FIFO_CTRL_REG_DEFAULT 0x0000023a
#define TEGRA186_ADMAIF_RX20_FIFO_CTRL_REG_DEFAULT 0x0000023d

#define TEGRA186_ADMAIF_TX1_FIFO_CTRL_REG_DEFAULT 0x02000300
#define TEGRA186_ADMAIF_TX2_FIFO_CTRL_REG_DEFAULT 0x02000304
#define TEGRA186_ADMAIF_TX3_FIFO_CTRL_REG_DEFAULT 0x02000308
#define TEGRA186_ADMAIF_TX4_FIFO_CTRL_REG_DEFAULT 0x0200030c
#define TEGRA186_ADMAIF_TX5_FIFO_CTRL_REG_DEFAULT 0x01800210
#define TEGRA186_ADMAIF_TX6_FIFO_CTRL_REG_DEFAULT 0x01800213
#define TEGRA186_ADMAIF_TX7_FIFO_CTRL_REG_DEFAULT 0x01800216
#define TEGRA186_ADMAIF_TX8_FIFO_CTRL_REG_DEFAULT 0x01800219
#define TEGRA186_ADMAIF_TX9_FIFO_CTRL_REG_DEFAULT 0x0180021c
#define TEGRA186_ADMAIF_TX10_FIFO_CTRL_REG_DEFAULT 0x0180021f
#define TEGRA186_ADMAIF_TX11_FIFO_CTRL_REG_DEFAULT 0x01800222
#define TEGRA186_ADMAIF_TX12_FIFO_CTRL_REG_DEFAULT 0x01800225
#define TEGRA186_ADMAIF_TX13_FIFO_CTRL_REG_DEFAULT 0x01800228
#define TEGRA186_ADMAIF_TX14_FIFO_CTRL_REG_DEFAULT 0x0180022b
#define TEGRA186_ADMAIF_TX15_FIFO_CTRL_REG_DEFAULT 0x0180022e
#define TEGRA186_ADMAIF_TX16_FIFO_CTRL_REG_DEFAULT 0x01800231
#define TEGRA186_ADMAIF_TX17_FIFO_CTRL_REG_DEFAULT 0x01800234
#define TEGRA186_ADMAIF_TX18_FIFO_CTRL_REG_DEFAULT 0x01800237
#define TEGRA186_ADMAIF_TX19_FIFO_CTRL_REG_DEFAULT 0x0180023a
#define TEGRA186_ADMAIF_TX20_FIFO_CTRL_REG_DEFAULT 0x0180023d

enum {
	DATA_8BIT,
	DATA_16BIT,
	DATA_32BIT
};


struct tegra_admaif_soc_data {
	unsigned int num_ch;
	struct snd_soc_dai_driver *codec_dais;
	struct snd_soc_codec_driver *admaif_codec;
	const struct regmap_config *regmap_conf;
	bool is_isomgr_client;
	unsigned int global_base;
	unsigned int tx_base;
	unsigned int rx_base;
};

struct tegra_admaif {
	/* regmap for admaif */
	struct regmap *regmap;
	struct device *dev;
	struct tegra_alt_pcm_dma_params *capture_dma_data;
	struct tegra_alt_pcm_dma_params *playback_dma_data;
	const struct tegra_admaif_soc_data *soc_data;
	int *override_channels;
	int *tx_mono_to_stereo;
	int *rx_stereo_to_mono;
	bool is_shutdown;
	int reg_dump_flag;
	void __iomem *base_addr;
};

extern void tegra_adma_dump_ch_reg(void);

#endif

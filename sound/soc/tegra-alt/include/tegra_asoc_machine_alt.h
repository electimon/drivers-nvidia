/*
 * tegra_asoc_machine_alt.h
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

#ifndef __TEGRA_ASOC_MACHINE_ALT_H__
#define __TEGRA_ASOC_MACHINE_ALT_H__

enum tegra210_xbar_dai_link {
	TEGRA210_DAI_LINK_ADMAIF1,
	TEGRA210_DAI_LINK_ADMAIF2,
	TEGRA210_DAI_LINK_ADMAIF3,
	TEGRA210_DAI_LINK_ADMAIF4,
	TEGRA210_DAI_LINK_ADMAIF5,
	TEGRA210_DAI_LINK_ADMAIF6,
	TEGRA210_DAI_LINK_ADMAIF7,
	TEGRA210_DAI_LINK_ADMAIF8,
	TEGRA210_DAI_LINK_ADMAIF9,
	TEGRA210_DAI_LINK_ADMAIF10,
#if IS_ENABLED(CONFIG_SND_SOC_TEGRA210_AMX_ALT)
	TEGRA210_DAI_LINK_AMX1_1,
	TEGRA210_DAI_LINK_AMX1_2,
	TEGRA210_DAI_LINK_AMX1_3,
	TEGRA210_DAI_LINK_AMX1_4,
	TEGRA210_DAI_LINK_AMX1,
	TEGRA210_DAI_LINK_AMX2_1,
	TEGRA210_DAI_LINK_AMX2_2,
	TEGRA210_DAI_LINK_AMX2_3,
	TEGRA210_DAI_LINK_AMX2_4,
	TEGRA210_DAI_LINK_AMX2,
#endif
#if IS_ENABLED(CONFIG_SND_SOC_TEGRA210_ADX_ALT)
	TEGRA210_DAI_LINK_ADX1,
	TEGRA210_DAI_LINK_ADX1_1,
	TEGRA210_DAI_LINK_ADX1_2,
	TEGRA210_DAI_LINK_ADX1_3,
	TEGRA210_DAI_LINK_ADX1_4,
	TEGRA210_DAI_LINK_ADX2,
	TEGRA210_DAI_LINK_ADX2_1,
	TEGRA210_DAI_LINK_ADX2_2,
	TEGRA210_DAI_LINK_ADX2_3,
	TEGRA210_DAI_LINK_ADX2_4,
#endif
#if IS_ENABLED(CONFIG_SND_SOC_TEGRA210_MIXER_ALT)
	TEGRA210_DAI_LINK_MIXER1_RX1,
	TEGRA210_DAI_LINK_MIXER1_RX2,
	TEGRA210_DAI_LINK_MIXER1_RX3,
	TEGRA210_DAI_LINK_MIXER1_RX4,
	TEGRA210_DAI_LINK_MIXER1_RX5,
	TEGRA210_DAI_LINK_MIXER1_RX6,
	TEGRA210_DAI_LINK_MIXER1_RX7,
	TEGRA210_DAI_LINK_MIXER1_RX8,
	TEGRA210_DAI_LINK_MIXER1_RX9,
	TEGRA210_DAI_LINK_MIXER1_RX10,
	TEGRA210_DAI_LINK_MIXER1_TX1,
	TEGRA210_DAI_LINK_MIXER1_TX2,
	TEGRA210_DAI_LINK_MIXER1_TX3,
	TEGRA210_DAI_LINK_MIXER1_TX4,
	TEGRA210_DAI_LINK_MIXER1_TX5,
#endif
#if IS_ENABLED(CONFIG_SND_SOC_TEGRA210_SFC_ALT)
	TEGRA210_DAI_LINK_SFC1_RX,
	TEGRA210_DAI_LINK_SFC1_TX,
	TEGRA210_DAI_LINK_SFC2_RX,
	TEGRA210_DAI_LINK_SFC2_TX,
	TEGRA210_DAI_LINK_SFC3_RX,
	TEGRA210_DAI_LINK_SFC3_TX,
	TEGRA210_DAI_LINK_SFC4_RX,
	TEGRA210_DAI_LINK_SFC4_TX,
#endif
#if IS_ENABLED(CONFIG_SND_SOC_TEGRA210_MVC_ALT)
	TEGRA210_DAI_LINK_MVC1_RX,
	TEGRA210_DAI_LINK_MVC1_TX,
	TEGRA210_DAI_LINK_MVC2_RX,
	TEGRA210_DAI_LINK_MVC2_TX,
#endif
#if IS_ENABLED(CONFIG_SND_SOC_TEGRA210_OPE_ALT)
	TEGRA210_DAI_LINK_OPE1_RX,
	TEGRA210_DAI_LINK_OPE1_TX,
	TEGRA210_DAI_LINK_OPE2_RX,
	TEGRA210_DAI_LINK_OPE2_TX,
#endif
#if IS_ENABLED(CONFIG_SND_SOC_TEGRA210_AFC_ALT)
	TEGRA210_DAI_LINK_AFC1_RX,
	TEGRA210_DAI_LINK_AFC1_TX,
	TEGRA210_DAI_LINK_AFC2_RX,
	TEGRA210_DAI_LINK_AFC2_TX,
	TEGRA210_DAI_LINK_AFC3_RX,
	TEGRA210_DAI_LINK_AFC3_TX,
	TEGRA210_DAI_LINK_AFC4_RX,
	TEGRA210_DAI_LINK_AFC4_TX,
	TEGRA210_DAI_LINK_AFC5_RX,
	TEGRA210_DAI_LINK_AFC5_TX,
	TEGRA210_DAI_LINK_AFC6_RX,
	TEGRA210_DAI_LINK_AFC6_TX,
#endif
	TEGRA210_DAI_LINK_ADMAIF1_CODEC,
	TEGRA210_DAI_LINK_ADMAIF2_CODEC,
	TEGRA210_DAI_LINK_ADMAIF3_CODEC,
	TEGRA210_DAI_LINK_ADMAIF4_CODEC,
	TEGRA210_DAI_LINK_ADMAIF5_CODEC,
	TEGRA210_DAI_LINK_ADMAIF6_CODEC,
	TEGRA210_DAI_LINK_ADMAIF7_CODEC,
	TEGRA210_DAI_LINK_ADMAIF8_CODEC,
	TEGRA210_DAI_LINK_ADMAIF9_CODEC,
	TEGRA210_DAI_LINK_ADMAIF10_CODEC,
#if IS_ENABLED(CONFIG_SND_SOC_TEGRA210_ADSP_ALT)
	TEGRA210_DAI_LINK_ADSP_ADMAIF1,
	TEGRA210_DAI_LINK_ADSP_ADMAIF2,
	TEGRA210_DAI_LINK_ADSP_ADMAIF3,
	TEGRA210_DAI_LINK_ADSP_ADMAIF4,
	TEGRA210_DAI_LINK_ADSP_ADMAIF5,
	TEGRA210_DAI_LINK_ADSP_ADMAIF6,
	TEGRA210_DAI_LINK_ADSP_ADMAIF7,
	TEGRA210_DAI_LINK_ADSP_ADMAIF8,
	TEGRA210_DAI_LINK_ADSP_ADMAIF9,
	TEGRA210_DAI_LINK_ADSP_ADMAIF10,
	TEGRA210_DAI_LINK_ADSP_PCM1,
	TEGRA210_DAI_LINK_ADSP_PCM2,
	TEGRA210_DAI_LINK_ADSP_COMPR1,
	TEGRA210_DAI_LINK_ADSP_COMPR2,
#endif
	TEGRA210_XBAR_DAI_LINKS, /* Total number of xbar dai links */
};

enum tegra210_xbar_codec_conf {
	TEGRA210_CODEC_AMX1_CONF,
	TEGRA210_CODEC_AMX2_CONF,
	TEGRA210_CODEC_ADX1_CONF,
	TEGRA210_CODEC_ADX2_CONF,
	TEGRA210_CODEC_SFC1_CONF,
	TEGRA210_CODEC_SFC2_CONF,
	TEGRA210_CODEC_SFC3_CONF,
	TEGRA210_CODEC_SFC4_CONF,
	TEGRA210_CODEC_MVC1_CONF,
	TEGRA210_CODEC_MVC2_CONF,
	TEGRA210_CODEC_OPE1_CONF,
	TEGRA210_CODEC_OPE2_CONF,
	TEGRA210_CODEC_AFC1_CONF,
	TEGRA210_CODEC_AFC2_CONF,
	TEGRA210_CODEC_AFC3_CONF,
	TEGRA210_CODEC_AFC4_CONF,
	TEGRA210_CODEC_AFC5_CONF,
	TEGRA210_CODEC_AFC6_CONF,
	TEGRA210_CODEC_I2S1_CONF,
	TEGRA210_CODEC_I2S2_CONF,
	TEGRA210_CODEC_I2S3_CONF,
	TEGRA210_CODEC_I2S4_CONF,
	TEGRA210_CODEC_I2S5_CONF,
	TEGRA210_CODEC_DMIC1_CONF,
	TEGRA210_CODEC_DMIC2_CONF,
	TEGRA210_CODEC_DMIC3_CONF,
	TEGRA210_XBAR_CODEC_CONF, /* Total number of xbar codec conf */
};

enum tegra186_xbar_dai_link {
	TEGRA186_DAI_LINK_ADMAIF1,
	TEGRA186_DAI_LINK_ADMAIF2,
	TEGRA186_DAI_LINK_ADMAIF3,
	TEGRA186_DAI_LINK_ADMAIF4,
	TEGRA186_DAI_LINK_ADMAIF5,
	TEGRA186_DAI_LINK_ADMAIF6,
	TEGRA186_DAI_LINK_ADMAIF7,
	TEGRA186_DAI_LINK_ADMAIF8,
	TEGRA186_DAI_LINK_ADMAIF9,
	TEGRA186_DAI_LINK_ADMAIF10,
	TEGRA186_DAI_LINK_ADMAIF11,
	TEGRA186_DAI_LINK_ADMAIF12,
	TEGRA186_DAI_LINK_ADMAIF13,
	TEGRA186_DAI_LINK_ADMAIF14,
	TEGRA186_DAI_LINK_ADMAIF15,
	TEGRA186_DAI_LINK_ADMAIF16,
	TEGRA186_DAI_LINK_ADMAIF17,
	TEGRA186_DAI_LINK_ADMAIF18,
	TEGRA186_DAI_LINK_ADMAIF19,
	TEGRA186_DAI_LINK_ADMAIF20,
	TEGRA186_DAI_LINK_ADMAIF1_CODEC,
	TEGRA186_DAI_LINK_ADMAIF2_CODEC,
	TEGRA186_DAI_LINK_ADMAIF3_CODEC,
	TEGRA186_DAI_LINK_ADMAIF4_CODEC,
	TEGRA186_DAI_LINK_ADMAIF5_CODEC,
	TEGRA186_DAI_LINK_ADMAIF6_CODEC,
	TEGRA186_DAI_LINK_ADMAIF7_CODEC,
	TEGRA186_DAI_LINK_ADMAIF8_CODEC,
	TEGRA186_DAI_LINK_ADMAIF9_CODEC,
	TEGRA186_DAI_LINK_ADMAIF10_CODEC,
	TEGRA186_DAI_LINK_ADMAIF11_CODEC,
	TEGRA186_DAI_LINK_ADMAIF12_CODEC,
	TEGRA186_DAI_LINK_ADMAIF13_CODEC,
	TEGRA186_DAI_LINK_ADMAIF14_CODEC,
	TEGRA186_DAI_LINK_ADMAIF15_CODEC,
	TEGRA186_DAI_LINK_ADMAIF16_CODEC,
	TEGRA186_DAI_LINK_ADMAIF17_CODEC,
	TEGRA186_DAI_LINK_ADMAIF18_CODEC,
	TEGRA186_DAI_LINK_ADMAIF19_CODEC,
	TEGRA186_DAI_LINK_ADMAIF20_CODEC,
	TEGRA186_DAI_LINK_AMX1_1,
	TEGRA186_DAI_LINK_AMX1_2,
	TEGRA186_DAI_LINK_AMX1_3,
	TEGRA186_DAI_LINK_AMX1_4,
	TEGRA186_DAI_LINK_AMX1,
	TEGRA186_DAI_LINK_AMX2_1,
	TEGRA186_DAI_LINK_AMX2_2,
	TEGRA186_DAI_LINK_AMX2_3,
	TEGRA186_DAI_LINK_AMX2_4,
	TEGRA186_DAI_LINK_AMX2,
	TEGRA186_DAI_LINK_AMX3_1,
	TEGRA186_DAI_LINK_AMX3_2,
	TEGRA186_DAI_LINK_AMX3_3,
	TEGRA186_DAI_LINK_AMX3_4,
	TEGRA186_DAI_LINK_AMX3,
	TEGRA186_DAI_LINK_AMX4_1,
	TEGRA186_DAI_LINK_AMX4_2,
	TEGRA186_DAI_LINK_AMX4_3,
	TEGRA186_DAI_LINK_AMX4_4,
	TEGRA186_DAI_LINK_AMX4,
	TEGRA186_DAI_LINK_ADX1,
	TEGRA186_DAI_LINK_ADX1_1,
	TEGRA186_DAI_LINK_ADX1_2,
	TEGRA186_DAI_LINK_ADX1_3,
	TEGRA186_DAI_LINK_ADX1_4,
	TEGRA186_DAI_LINK_ADX2,
	TEGRA186_DAI_LINK_ADX2_1,
	TEGRA186_DAI_LINK_ADX2_2,
	TEGRA186_DAI_LINK_ADX2_3,
	TEGRA186_DAI_LINK_ADX2_4,
	TEGRA186_DAI_LINK_ADX3,
	TEGRA186_DAI_LINK_ADX3_1,
	TEGRA186_DAI_LINK_ADX3_2,
	TEGRA186_DAI_LINK_ADX3_3,
	TEGRA186_DAI_LINK_ADX3_4,
	TEGRA186_DAI_LINK_ADX4,
	TEGRA186_DAI_LINK_ADX4_1,
	TEGRA186_DAI_LINK_ADX4_2,
	TEGRA186_DAI_LINK_ADX4_3,
	TEGRA186_DAI_LINK_ADX4_4,
	TEGRA186_DAI_LINK_MIXER1_RX1,
	TEGRA186_DAI_LINK_MIXER1_RX2,
	TEGRA186_DAI_LINK_MIXER1_RX3,
	TEGRA186_DAI_LINK_MIXER1_RX4,
	TEGRA186_DAI_LINK_MIXER1_RX5,
	TEGRA186_DAI_LINK_MIXER1_RX6,
	TEGRA186_DAI_LINK_MIXER1_RX7,
	TEGRA186_DAI_LINK_MIXER1_RX8,
	TEGRA186_DAI_LINK_MIXER1_RX9,
	TEGRA186_DAI_LINK_MIXER1_RX10,
	TEGRA186_DAI_LINK_MIXER1_TX1,
	TEGRA186_DAI_LINK_MIXER1_TX2,
	TEGRA186_DAI_LINK_MIXER1_TX3,
	TEGRA186_DAI_LINK_MIXER1_TX4,
	TEGRA186_DAI_LINK_MIXER1_TX5,
	TEGRA186_DAI_LINK_SFC1_RX,
	TEGRA186_DAI_LINK_SFC1_TX,
	TEGRA186_DAI_LINK_SFC2_RX,
	TEGRA186_DAI_LINK_SFC2_TX,
	TEGRA186_DAI_LINK_SFC3_RX,
	TEGRA186_DAI_LINK_SFC3_TX,
	TEGRA186_DAI_LINK_SFC4_RX,
	TEGRA186_DAI_LINK_SFC4_TX,
	TEGRA186_DAI_LINK_MVC1_RX,
	TEGRA186_DAI_LINK_MVC1_TX,
	TEGRA186_DAI_LINK_MVC2_RX,
	TEGRA186_DAI_LINK_MVC2_TX,
	TEGRA186_DAI_LINK_OPE1_RX,
	TEGRA186_DAI_LINK_OPE1_TX,
	TEGRA186_DAI_LINK_AFC1_RX,
	TEGRA186_DAI_LINK_AFC1_TX,
	TEGRA186_DAI_LINK_AFC2_RX,
	TEGRA186_DAI_LINK_AFC2_TX,
	TEGRA186_DAI_LINK_AFC3_RX,
	TEGRA186_DAI_LINK_AFC3_TX,
	TEGRA186_DAI_LINK_AFC4_RX,
	TEGRA186_DAI_LINK_AFC4_TX,
	TEGRA186_DAI_LINK_AFC5_RX,
	TEGRA186_DAI_LINK_AFC5_TX,
	TEGRA186_DAI_LINK_AFC6_RX,
	TEGRA186_DAI_LINK_AFC6_TX,
	TEGRA186_DAI_LINK_ASRC1_RX1,
	TEGRA186_DAI_LINK_ASRC1_RX2,
	TEGRA186_DAI_LINK_ASRC1_RX3,
	TEGRA186_DAI_LINK_ASRC1_RX4,
	TEGRA186_DAI_LINK_ASRC1_RX5,
	TEGRA186_DAI_LINK_ASRC1_RX6,
	TEGRA186_DAI_LINK_ASRC1_RX7,
	TEGRA186_DAI_LINK_ASRC1_TX1,
	TEGRA186_DAI_LINK_ASRC1_TX2,
	TEGRA186_DAI_LINK_ASRC1_TX3,
	TEGRA186_DAI_LINK_ASRC1_TX4,
	TEGRA186_DAI_LINK_ASRC1_TX5,
	TEGRA186_DAI_LINK_ASRC1_TX6,
#if IS_ENABLED(CONFIG_SND_SOC_TEGRA210_ADSP_ALT)
	TEGRA186_DAI_LINK_ADSP_ADMAIF1,
	TEGRA186_DAI_LINK_ADSP_ADMAIF2,
	TEGRA186_DAI_LINK_ADSP_ADMAIF3,
	TEGRA186_DAI_LINK_ADSP_ADMAIF4,
	TEGRA186_DAI_LINK_ADSP_ADMAIF5,
	TEGRA186_DAI_LINK_ADSP_ADMAIF6,
	TEGRA186_DAI_LINK_ADSP_ADMAIF7,
	TEGRA186_DAI_LINK_ADSP_ADMAIF8,
	TEGRA186_DAI_LINK_ADSP_ADMAIF9,
	TEGRA186_DAI_LINK_ADSP_ADMAIF10,
	TEGRA186_DAI_LINK_ADSP_ADMAIF11,
	TEGRA186_DAI_LINK_ADSP_ADMAIF12,
	TEGRA186_DAI_LINK_ADSP_ADMAIF13,
	TEGRA186_DAI_LINK_ADSP_ADMAIF14,
	TEGRA186_DAI_LINK_ADSP_ADMAIF15,
	TEGRA186_DAI_LINK_ADSP_ADMAIF16,
	TEGRA186_DAI_LINK_ADSP_ADMAIF17,
	TEGRA186_DAI_LINK_ADSP_ADMAIF18,
	TEGRA186_DAI_LINK_ADSP_ADMAIF19,
	TEGRA186_DAI_LINK_ADSP_ADMAIF20,
	TEGRA186_DAI_LINK_ADSP_PCM1,
	TEGRA186_DAI_LINK_ADSP_PCM2,
	TEGRA186_DAI_LINK_ADSP_COMPR1,
	TEGRA186_DAI_LINK_ADSP_COMPR2,
#endif

	TEGRA186_DAI_LINK_ARAD,
	TEGRA186_XBAR_DAI_LINKS, /* Total number of xbar dai links */
};

enum tegra186_xbar_codec_conf {
	TEGRA186_CODEC_AMX1_CONF,
	TEGRA186_CODEC_AMX2_CONF,
	TEGRA186_CODEC_AMX3_CONF,
	TEGRA186_CODEC_AMX4_CONF,
	TEGRA186_CODEC_ADX1_CONF,
	TEGRA186_CODEC_ADX2_CONF,
	TEGRA186_CODEC_ADX3_CONF,
	TEGRA186_CODEC_ADX4_CONF,
	TEGRA186_CODEC_SFC1_CONF,
	TEGRA186_CODEC_SFC2_CONF,
	TEGRA186_CODEC_SFC3_CONF,
	TEGRA186_CODEC_SFC4_CONF,
	TEGRA186_CODEC_MVC1_CONF,
	TEGRA186_CODEC_MVC2_CONF,
	TEGRA186_CODEC_OPE1_CONF,
	TEGRA186_CODEC_AFC1_CONF,
	TEGRA186_CODEC_AFC2_CONF,
	TEGRA186_CODEC_AFC3_CONF,
	TEGRA186_CODEC_AFC4_CONF,
	TEGRA186_CODEC_AFC5_CONF,
	TEGRA186_CODEC_AFC6_CONF,
	TEGRA186_CODEC_I2S1_CONF,
	TEGRA186_CODEC_I2S2_CONF,
	TEGRA186_CODEC_I2S3_CONF,
	TEGRA186_CODEC_I2S4_CONF,
	TEGRA186_CODEC_I2S5_CONF,
	TEGRA186_CODEC_I2S6_CONF,
	TEGRA186_CODEC_DMIC1_CONF,
	TEGRA186_CODEC_DMIC2_CONF,
	TEGRA186_CODEC_DMIC3_CONF,
	TEGRA186_CODEC_DMIC4_CONF,
	TEGRA186_CODEC_DSPK1_CONF,
	TEGRA186_CODEC_DSPK2_CONF,
	TEGRA186_CODEC_ASRC1_CONF,
	TEGRA186_XBAR_CODEC_CONF, /* Total number of xbar codec conf */
};

struct snd_soc_dai_link *tegra_machine_get_dai_link(void);

void tegra_machine_remove_dai_link(void);

int tegra_machine_append_dai_link(struct snd_soc_dai_link *link,
		unsigned int link_size);

void tegra_machine_set_dai_ops(int link, struct snd_soc_ops *ops);

void tegra_machine_set_dai_compr_ops(int link, struct snd_soc_compr_ops *ops);

void tegra_machine_set_dai_init(int link, void *ptr);

void tegra_machine_set_dai_params(int link,
		struct snd_soc_pcm_stream *params);

void tegra_machine_set_dai_fmt(int link, unsigned int fmt);

struct snd_soc_codec_conf *tegra_machine_get_codec_conf(void);

void tegra_machine_remove_codec_conf(void);

int tegra_machine_append_codec_conf(struct snd_soc_codec_conf *conf,
		unsigned int conf_size);

struct snd_soc_dai_link *tegra_machine_new_codec_links(
	struct platform_device *pdev,
	struct snd_soc_dai_link *tegra_codec_links,
	unsigned int *pnum_codec_links);

struct snd_soc_codec_conf *tegra_machine_new_codec_conf(
	struct platform_device *pdev,
	struct snd_soc_codec_conf *tegra_codec_conf,
	unsigned int *pnum_codec_links);

unsigned int tegra_machine_get_codec_dai_link_idx(const char *codec_name);

unsigned int tegra_machine_get_rx_mask(
	struct snd_soc_pcm_runtime *rtd);
unsigned int tegra_machine_get_tx_mask(
	struct snd_soc_pcm_runtime *rtd);

/* t18x specifc APIs */
struct snd_soc_dai_link *tegra_machine_get_dai_link_t18x(void);

int tegra_machine_append_dai_link_t18x(struct snd_soc_dai_link *link,
		unsigned int link_size);

struct snd_soc_codec_conf *tegra_machine_get_codec_conf_t18x(void);

int tegra_machine_append_codec_conf_t18x(struct snd_soc_codec_conf *conf,
		unsigned int conf_size);

unsigned int tegra_machine_get_codec_dai_link_idx_t18x(const char *codec_name);

unsigned int tegra_machine_get_rx_mask_t18x(
	struct snd_soc_pcm_runtime *rtd);
unsigned int tegra_machine_get_tx_mask_t18x(
	struct snd_soc_pcm_runtime *rtd);

void tegra_machine_remove_adsp_links_t18x(void);
int tegra_machine_add_i2s_codec_controls(struct snd_soc_card *card,
					 unsigned int num_dai_links);
int tegra_machine_add_codec_jack_control(struct snd_soc_card *card,
					 struct snd_soc_pcm_runtime *rtd,
					 struct snd_soc_jack *jack);

void tegra_machine_dma_set_mask(struct platform_device *pdev);

/* for legacy machine driver support */
static inline int tegra_machine_get_bclk_ratio(struct snd_soc_pcm_runtime *rtd,
					       unsigned int *ratio) {
	*ratio = 1;

	return 0;
}

static inline int tegra_machine_get_bclk_ratio_t18x(
	struct snd_soc_pcm_runtime *rtd, unsigned int *ratio) {
	*ratio = 1;

	return 0;
}

#endif

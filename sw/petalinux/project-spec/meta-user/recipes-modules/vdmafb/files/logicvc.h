/*
 * Xylon logiCVC IP core v2.05c definitions
 *
 * Author: Xylon d.o.o.
 * e-mail: davor.joja@logicbricks.com
 *
 * 2013 Xylon d.o.o.
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2.  This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 */

#ifndef __LOGICVC_H__
#define __LOGICVC_H__

/* All logiCVC registers are 32 bit registers */
/* All logiCVC registers are at 8 byte distance */
#define LOGICVC_REG_DIST_USED      8
/* R_HSY_FP */
#define LOGICVC_SHSY_FP_ROFF      (0  * LOGICVC_REG_DIST_USED)
/* R_HSY */
#define LOGICVC_SHSY_ROFF         (1  * LOGICVC_REG_DIST_USED)
/* R_HSY_BP */
#define LOGICVC_SHSY_BP_ROFF      (2  * LOGICVC_REG_DIST_USED)
/* R_HSY_RES */
#define SHSY_RES_ROFF             0x54
/* R_VSY_FP */
#define LOGICVC_SVSY_FP_ROFF      (4  * LOGICVC_REG_DIST_USED)
/* R_VSY */
#define LOGICVC_SVSY_ROFF         (5  * LOGICVC_REG_DIST_USED)
/* R_VSY_BP */
#define LOGICVC_SVSY_BP_ROFF      (6  * LOGICVC_REG_DIST_USED)
/* R_VSY_RES */
#define SVSY_RES_ROFF             0x50
/* R_CTRL */
#define LOGICVC_SCTRL_ROFF        (8  * LOGICVC_REG_DIST_USED)
/* R_DTYPE */
#define LOGICVC_SDTYPE_ROFF       (9  * LOGICVC_REG_DIST_USED)
/* R_BACKGROUND */
#define LOGICVC_BACKCOL_ROFF      (10 * LOGICVC_REG_DIST_USED)
/* R_DOUBLE_VBUFF */
#define LOGICVC_DOUBLE_VBUFF_ROFF (11 * LOGICVC_REG_DIST_USED)
/* R_DOUBLE_CLUT */
#define LOGICVC_DOUBLE_CLUT_ROFF  (12 * LOGICVC_REG_DIST_USED)
/* R_INT_STAT */
#define LOGICVC_INT_STAT_ROFF     (13 * LOGICVC_REG_DIST_USED)
/* R_INT_MASK */
#define LOGICVC_INT_MASK_ROFF     (14 * LOGICVC_REG_DIST_USED)
/* R_PWRCTRL */
#define LOGICVC_SPWRCTRL_ROFF     (15 * LOGICVC_REG_DIST_USED)
/* R_IPVER */
#define LOGICVC_IPVER_ROFF        (18 * LOGICVC_REG_DIST_USED)

/* logiCVC layer registers base and distance between the layers */
/* distance between groups of layer registers */
#define LOGICVC_LAYER_DISTANCE   (16  * LOGICVC_REG_DIST_USED)
/* offset to the beginning of layer 0 registers */
#define LOGICVC_LAYER0_BASE_ROFF (32  * LOGICVC_REG_DIST_USED)
/* offset to the beginning of layer 1 registers */
#define LOGICVC_LAYER1_BASE_ROFF \
	(LOGICVC_LAYER0_BASE_ROFF + LOGICVC_LAYER_DISTANCE * 1)
/* offset to the beginning of layer 2 registers */
#define LOGICVC_LAYER2_BASE_ROFF \
	(LOGICVC_LAYER0_BASE_ROFF + LOGICVC_LAYER_DISTANCE * 2)
/* offset to the beginning of layer 3 registers */
#define LOGICVC_LAYER3_BASE_ROFF \
	(LOGICVC_LAYER0_BASE_ROFF + LOGICVC_LAYER_DISTANCE * 3)
/* offset to the beginning of layer 4 registers */
#define LOGICVC_LAYER4_BASE_ROFF \
	(LOGICVC_LAYER0_BASE_ROFF + LOGICVC_LAYER_DISTANCE * 4)

/* logiCVC layer registers offsets (common for each layer) */
/*  LH_OFFSET */
#define LOGICVC_LAYER_HOR_OFF_ROFF (0 * LOGICVC_REG_DIST_USED)
/*  LV_OFFSET */
#define LOGICVC_LAYER_VER_OFF_ROFF (1 * LOGICVC_REG_DIST_USED)
/*  LH_POSITION */
#define LOGICVC_LAYER_HOR_POS_ROFF (2 * LOGICVC_REG_DIST_USED)
/*  LV_POSITION */
#define LOGICVC_LAYER_VER_POS_ROFF (3 * LOGICVC_REG_DIST_USED)
/*  LH_WIDTH */
#define LOGICVC_LAYER_WIDTH_ROFF   (4 * LOGICVC_REG_DIST_USED)
/*  LV_HEIGHT */
#define LOGICVC_LAYER_HEIGHT_ROFF  (5 * LOGICVC_REG_DIST_USED)
/*  ALPHA */
#define LOGICVC_LAYER_ALPHA_ROFF   (6 * LOGICVC_REG_DIST_USED)
/*  CTRL */
#define LOGICVC_LAYER_CTRL_ROFF    (7 * LOGICVC_REG_DIST_USED)
/*  TRANSPARENT */
#define LOGICVC_LAYER_TRANSP_ROFF  (8 * LOGICVC_REG_DIST_USED)

/* logiCVC interrupt bits */
#define LOGICVC_L0_VBUFF_SW_INT   0x01
#define LOGICVC_L1_VBUFF_SW_INT   0x02
#define LOGICVC_L2_VBUFF_SW_INT   0x04
#define LOGICVC_L3_VBUFF_SW_INT   0x08
#define LOGICVC_L4_VBUFF_SW_INT   0x10
#define LOGICVC_V_SYNC_INT        0x20
#define LOGICVC_E_VIDEO_VALID_INT 0x40
#define LOGICVC_L0_CLUT_SW_INT    0x100
#define LOGICVC_L1_CLUT_SW_INT    0x200
#define LOGICVC_L2_CLUT_SW_INT    0x400
#define LOGICVC_L3_CLUT_SW_INT    0x800
#define LOGICVC_L4_CLUT_SW_INT    0x1000

/* logiCVC layer base offsets */
#define LOGICVC_LAYER_OFFSET      0x80
#define LOGICVC_LAYER_BASE_OFFSET 0x100
#define LOGICVC_LAYER_0_OFFSET    0
#define LOGICVC_LAYER_1_OFFSET \
	(LOGICVC_LAYER_0_OFFSET + LOGICVC_LAYER_OFFSET)
#define LOGICVC_LAYER_2_OFFSET \
	(LOGICVC_LAYER_1_OFFSET + LOGICVC_LAYER_OFFSET)
#define LOGICVC_LAYER_3_OFFSET \
	(LOGICVC_LAYER_2_OFFSET + LOGICVC_LAYER_OFFSET)
#define LOGICVC_LAYER_4_OFFSET \
	(LOGICVC_LAYER_3_OFFSET + LOGICVC_LAYER_OFFSET)
#define LOGICVC_LAYER_BASE_END    0x338

/* logiCVC layer CLUT base offsets */
#define LOGICVC_CLUT_OFFSET           0x800
#define LOGICVC_CLUT_BASE_OFFSET      0x1000
#define LOGICVC_CLUT_L0_CLUT_0_OFFSET 0
#define LOGICVC_CLUT_L0_CLUT_1_OFFSET \
	(LOGICVC_CLUT_L0_CLUT_0_OFFSET + LOGICVC_CLUT_OFFSET)
#define LOGICVC_CLUT_L1_CLUT_0_OFFSET \
	(LOGICVC_CLUT_L0_CLUT_1_OFFSET + LOGICVC_CLUT_OFFSET)
#define LOGICVC_CLUT_L1_CLUT_1_OFFSET \
	(LOGICVC_CLUT_L1_CLUT_0_OFFSET + LOGICVC_CLUT_OFFSET)
#define LOGICVC_CLUT_L2_CLUT_0_OFFSET \
	(LOGICVC_CLUT_L1_CLUT_1_OFFSET + LOGICVC_CLUT_OFFSET)
#define LOGICVC_CLUT_L2_CLUT_1_OFFSET \
	(LOGICVC_CLUT_L2_CLUT_0_OFFSET + LOGICVC_CLUT_OFFSET)
#define LOGICVC_CLUT_L3_CLUT_0_OFFSET \
	(LOGICVC_CLUT_L2_CLUT_1_OFFSET + LOGICVC_CLUT_OFFSET)
#define LOGICVC_CLUT_L3_CLUT_1_OFFSET \
	(LOGICVC_CLUT_L3_CLUT_0_OFFSET + LOGICVC_CLUT_OFFSET)
#define LOGICVC_CLUT_L4_CLUT_0_OFFSET \
	(LOGICVC_CLUT_L3_CLUT_1_OFFSET + LOGICVC_CLUT_OFFSET)
#define LOGICVC_CLUT_L4_CLUT_1_OFFSET \
	(LOGICVC_CLUT_L4_CLUT_0_OFFSET + LOGICVC_CLUT_OFFSET)
#define LOGICVC_CLUT_REGISTER_SIZE    8
#define LOGICVC_CLUT_0_INDEX_OFFSET   2
#define LOGICVC_CLUT_1_INDEX_OFFSET   1

/* logiCVC register and CLUT base offsets */
#define LOGICVC_GENERAL_REGISTERS_RANGE 0x100
#define LOGICVC_REGISTERS_RANGE         0x6000

/* logiCVC register initial values */
#define CTRL_REG_INIT 0x001F
#define SD_REG_INIT   0

/* logiCVC display power signals */
#define LOGICVC_EN_BLIGHT_MSK 0x01
#define LOGICVC_EN_VDD_MSK    0x02
#define LOGICVC_EN_VEE_MSK    0x04
#define LOGICVC_V_EN_MSK      0x08

/* logiCVC various definitions */
#define LOGICVC_PIX_DATA_INVERT        0x80
#define LOGICVC_PIX_ACT_HIGH           0x100
#define LOGICVC_LAYER_ON               0x01
#define LOGICVC_SWAP_RB                0x10
#define LOGICVC_MAX_LAYERS             5
#define LOGICVC_MAX_LAYER_BUFFERS      3
#define LOGICVC_MIN_XRES               64
#define LOGICVC_MAX_XRES               2048
#define LOGICVC_MIN_VRES               1
#define LOGICVC_MAX_VRES               2048
#define LOGICVC_MAX_LINES              4096
#define LOGICVC_CLUT_SIZE              256
#define TRANSPARENT_COLOR_8BPP         0x25       /* dummy */
#define TRANSPARENT_COLOR_8BPP_CLUT_16 0xF813     /* dummy */
#define TRANSPARENT_COLOR_8BPP_CLUT_24 0x00FF009C /* dummy */
#define TRANSPARENT_COLOR_16BPP        0xF813     /* dummy */
#define TRANSPARENT_COLOR_24BPP        0x00FF009C /* dummy */
#define BACKGROUND_COLOR               0x00000000

#define LOGICVC_READABLE_REGS 0x01

enum xylonfb_layer_type {
	LOGICVC_RGB_LAYER = 0,
	LOGICVC_YCBCR_LAYER,
	LOGICVC_ALPHA_LAYER
};

enum xylonfb_alpha_format {
	LOGICVC_LAYER_ALPHA = 0,
	LOGICVC_PIXEL_ALPHA,
	LOGICVC_CLUT_16BPP_ALPHA,
	LOGICVC_CLUT_32BPP_ALPHA
};

enum xylonfb_display_interface {
	LOGICVC_DI_PARALLEL = 0,
	LOGICVC_DI_ITU656,
	LOGICVC_DI_LVDS_4bit,
	LOGICVC_DI_CAMERA_LINK_4bit,
	LOGICVC_DI_LVDS_3bit,
	LOGICVC_DI_DVI
};

enum xylonfb_display_color_space {
	LOGICVC_DCS_RGB = 0,
	LOGICVC_DCS_YUV422,
	LOGICVC_DCS_YUV444
};

#endif /* __LOGICVC_H__ */

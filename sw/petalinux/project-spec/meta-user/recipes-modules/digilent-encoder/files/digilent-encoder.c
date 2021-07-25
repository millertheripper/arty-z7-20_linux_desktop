/*  digilent-encoder.c - The simplest kernel module.

* Copyright (C) 2013 - 2016 Xilinx, Inc
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.

*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program. If not, see <http://www.gnu.org/licenses/>.

*/

#include <linux/export.h>
#include <linux/component.h>

#include <drm/drm.h>
#include <drm/drm_print.h>
#include <drm/drm_edid.h>
#include <drm/drm_atomic_helper.h>
#include <drm/drm_crtc.h>
#include <drm/drm_crtc_helper.h>
#include <drm/drm_probe_helper.h>
#include <drm/drm_encoder_slave.h>

#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/err.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/interrupt.h>

#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>
#include <linux/platform_device.h>

/* BEGIN - Standard module information, edit as appropriate */
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Digilent, Inc.");
MODULE_DESCRIPTION("digilent_encoder - DRM slave encoder for Video-out on Digilent boards");

#define DRIVER_NAME "digilent_encoder"

/* END - Standard module information, edit as appropriate */


/*
 * Default frame maximums/prefs; can be set in devicetree
 */
#define DIGILENT_ENC_MAX_FREQ 150000  //KHz
#define DIGILENT_ENC_MAX_H 1920
#define DIGILENT_ENC_MAX_V 1080
#define DIGILENT_ENC_PREF_H 1280
#define DIGILENT_ENC_PREF_V 720


struct digilent_encoder 
{
	struct drm_encoder encoder;
	struct drm_connector connector;
	struct device *dev;
	struct i2c_adapter *i2c_bus;
	bool i2c_present;
	u32 fmax;
    	u32 hmax;
	u32 vmax;
	u32 hpref;
	u32 vpref;
};


#define encoder_to_digilent_encoder(x) container_of(x, struct digilent_encoder, encoder)
#define connector_to_digilent_encoder(c) container_of(c, struct digilent_encoder, connector)


static enum drm_connector_status digilent_encoder_connector_detect(struct drm_connector *connector, bool force)
{
	struct digilent_encoder *digilent = connector_to_digilent_encoder(connector);

	if (digilent->i2c_present)
	{
		if (drm_probe_ddc(digilent->i2c_bus))
		{
			return connector_status_connected;
		}

		return connector_status_disconnected;
	}
	else
	{
		return connector_status_unknown;
	}
}


static void digilent_encoder_connector_destroy(struct drm_connector *connector)
{
	struct digilent_encoder *digilent = connector_to_digilent_encoder(connector);
	
	drm_connector_unregister(connector);
	drm_connector_cleanup(connector);
	connector->dev = NULL;
}


static const struct drm_connector_funcs digilent_encoder_connector_funcs =
{
//	.dpms				= drm_helper_connector_dpms,
	.detect				= digilent_encoder_connector_detect,
	.fill_modes			= drm_helper_probe_single_connector_modes,
	.destroy			= digilent_encoder_connector_destroy,
	.atomic_duplicate_state		= drm_atomic_helper_connector_duplicate_state,
	.atomic_destroy_state		= drm_atomic_helper_connector_destroy_state,
	.reset				= drm_atomic_helper_connector_reset,
};


static inline digilent_encoder_mode_valid_helper(struct drm_connector *connector,
						 struct drm_display_mode *mode)
{
	struct digilent_encoder *digilent = connector_to_digilent_encoder(connector);

	if (mode && 
	    !(mode->flags & ((DRM_MODE_FLAG_INTERLACE | DRM_MODE_FLAG_DBLCLK) | DRM_MODE_FLAG_3D_MASK)) &&
	    (mode->clock <= digilent->fmax) &&
	    (mode->hdisplay <= digilent->hmax) &&
	    (mode->vdisplay <= digilent->vmax))
	{	
		return MODE_OK;
	}

	return MODE_BAD;
}


static int digilent_encoder_get_modes_helper(struct drm_connector *connector)
{
	struct digilent_encoder *digilent = connector_to_digilent_encoder(connector);
	struct edid *edid;
	int num_modes = 0;

        if (digilent->i2c_present)
        {
                edid = drm_get_edid(connector, digilent->i2c_bus);

                /*
                 *Other drivers tend to call update edid property after the call to 
                 *drm_add_edid_modes. If problems with modesetting, this could be why.
                 */
                drm_connector_update_edid_property(connector, edid);
                if (edid) 
                {
                        num_modes = drm_add_edid_modes(connector, edid);
                        kfree(edid);
                }
        }
        else
        {
                num_modes = drm_add_modes_noedid(connector, DIGILENT_ENC_MAX_H, DIGILENT_ENC_MAX_V);
                drm_set_preferred_mode(connector, DIGILENT_ENC_PREF_H, DIGILENT_ENC_PREF_V);
        }
        return num_modes;
}


static struct drm_encoder *digilent_encoder_best_encoder_helper(struct drm_connector *connector)
{
	struct digilent_encoder *digilent = connector_to_digilent_encoder(connector);

	return &digilent->encoder;
}


static struct drm_connector_helper_funcs digilent_encoder_connector_helper_funcs =
{
	.get_modes = digilent_encoder_get_modes_helper,
	.mode_valid = digilent_encoder_mode_valid_helper,
	.best_encoder = digilent_encoder_best_encoder_helper,
};


static void digilent_encoder_atomic_mode_set(struct drm_encoder *encoder,
					     struct drm_crtc_state *crtc_state,
					     struct drm_connector_state *connector_state)
{

}


static void digilent_encoder_enable(struct drm_encoder *encoder)
{

}

static void digilent_encoder_disable(struct drm_encoder *encoder)
{

}


static const struct drm_encoder_helper_funcs digilent_encoder_helper_funcs =
{
	.atomic_mode_set = digilent_encoder_atomic_mode_set,
	.enable = digilent_encoder_enable,
	.disable = digilent_encoder_disable,
};


static const struct drm_encoder_funcs digilent_encoder_funcs =
{
    .destroy = drm_encoder_cleanup,
};


static int digilent_encoder_create_connector(struct drm_encoder *encoder)
{
	struct digilent_encoder *digilent = encoder_to_digilent_encoder(encoder);
	struct drm_connector *connector = &digilent->connector;
	int rc;

	connector->polled = DRM_CONNECTOR_POLL_HPD;
	connector->polled = DRM_CONNECTOR_POLL_CONNECT | DRM_CONNECTOR_POLL_DISCONNECT;

	rc = drm_connector_init(encoder->dev, connector, &digilent_encoder_connector_funcs, DRM_MODE_CONNECTOR_HDMIA);
	if (rc)
	{
		dev_err(digilent->dev, "Failed to initialize connector with drm\n");
		return rc;
	}

	drm_connector_helper_add(connector, &digilent_encoder_connector_helper_funcs);
	
	rc = drm_connector_register(connector);
	if (rc)
	{
        	dev_err(digilent->dev, "Failed to register the connector (rc=%d)\n", rc);
        	return rc;
	}
	
	rc = drm_connector_attach_encoder(connector, encoder);
	if (rc)
	{
		dev_err(digilent->dev, "Failed to attach encoder to connector (ret=%d)\n", rc);
		return rc;
	}
	
	return 0;
}


static int digilent_encoder_bind(struct device *dev, struct device *master, void *data)
{
	struct digilent_encoder *digilent = dev_get_drvdata(dev);
	struct drm_encoder *encoder = &digilent->encoder;
	struct drm_device *drm_dev = data;
	int rc;

	/**
	 * TODO: The possible CRTCs are 1 now as per current implementation of
	 * HDMI driver. DRM framework can support more than one CRTCs and
	 * HDMI driver can be enchanced for that.
	 **/
	encoder->possible_crtcs = 1;
	drm_encoder_init(drm_dev, encoder, &digilent_encoder_funcs, DRM_MODE_ENCODER_TMDS, NULL);
	drm_encoder_helper_add(encoder, &digilent_encoder_helper_funcs);
	
	rc = digilent_encoder_create_connector(encoder);
	if (rc)
	{
		dev_err(digilent->dev, "fail creating connect, rc = %d\n", rc);
		drm_encoder_cleanup(encoder);
	}
	
	return rc;
}


static void digilent_encoder_unbind(struct device *dev, struct device *master, void *data)
{
    struct digilent_encoder *digilent = dev_get_drvdata(dev);

    drm_encoder_cleanup(&digilent->encoder);
    drm_connector_cleanup(&digilent->connector);
}


static const struct component_ops digilent_encoder_component_ops =
{
	.bind = digilent_encoder_bind,
	.unbind = digilent_encoder_unbind,
};


static int digilent_encoder_probe(struct platform_device *pdev)
{
	struct digilent_encoder *digilent;
	struct device_node *sub_node;
	int rc;

	digilent = devm_kzalloc(&pdev->dev, sizeof(*digilent), GFP_KERNEL);
	if (!digilent)
	{
		return -ENOMEM;
	}
	
	digilent->dev = &pdev->dev;
	platform_set_drvdata(pdev, digilent);
	
	digilent->i2c_present = false;

	sub_node = of_parse_phandle(pdev->dev.of_node, "digilent,edid-i2c", 0);
	if (sub_node)
	{
		digilent->i2c_bus = of_find_i2c_adapter_by_node(sub_node);
		if (!digilent->i2c_bus)
		{
			dev_info(&pdev->dev, "failed to get the edid i2c adapter, using default modes\n");
		}
		else
		{
			digilent->i2c_present = false;
		}
	}

	digilent->fmax = DIGILENT_ENC_MAX_FREQ;
	digilent->hmax = DIGILENT_ENC_MAX_H;
	digilent->vmax = DIGILENT_ENC_MAX_V;
	digilent->hpref = DIGILENT_ENC_PREF_H;
	digilent->vpref = DIGILENT_ENC_PREF_V;
	
	dev_info(&pdev->dev, "set default display resolution to %dx%d, max frequency %d\r\n", digilent->hpref, digilent->vpref, digilent->fmax);

	rc = component_add(digilent->dev, &digilent_encoder_component_ops);

	dev_info(&pdev->dev, "digilent_encoder module probe returns %d\r\n", rc);

	return rc;
}


static int digilent_encoder_remove(struct platform_device *pdev)
{
	struct digilent_encoder *digilent = platform_get_drvdata(pdev);

	component_del(digilent->dev, &digilent_encoder_component_ops);
	
	return 0;
}


static struct of_device_id digilent_encoder_of_match[] =
{
	{ .compatible = "digilent,drm-encoder"},
	{ /* end of list */ },
};
MODULE_DEVICE_TABLE(of, digilent_encoder_of_match);


static struct platform_driver digilent_encoder_driver =
{
	.driver =
	{
		.name = DRIVER_NAME,
		.owner = THIS_MODULE,
		.of_match_table	= digilent_encoder_of_match,
	},
	.probe		= digilent_encoder_probe,
	.remove		= digilent_encoder_remove,
};

static int __init digilent_encoder_init(void)
{
	return platform_driver_register(&digilent_encoder_driver);
}


static void __exit digilent_encoder_exit(void)
{
	platform_driver_unregister(&digilent_encoder_driver);
	printk(KERN_INFO "digilent_encoder module exit.\r\n");
}

module_init(digilent_encoder_init);
module_exit(digilent_encoder_exit);

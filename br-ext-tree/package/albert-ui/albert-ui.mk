################################################################################
#
# albert-ui
#
################################################################################

ALBERT_UI_VERSION = 0.0.2
ALBERT_UI_SITE = $(BR2_EXTERNAL_ALBERT_PATH)/package/albert-ui
ALBERT_UI_SITE_METHOD = local
ALBERT_UI_DEPENDENCIES = qt5base qt5quickcontrols qt5quickcontrols2 qt5charts

define ALBERT_UI_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/albert-ui $(TARGET_DIR)/usr/bin/albert-ui
endef

$(eval $(cmake-package))

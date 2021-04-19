JOOMBY_VERSION = 0.0.2
JOOMBY = MIT
JOOMBY_SITE = $(BR2_EXTERNAL_JOOMBY_PATH)/package/joomby
JOOMBY_SITE_METHOD = local
JOOMBY_DEPENDENCIES = qt5base qt5quickcontrols qt5quickcontrols2 qt5charts

define JOOMBY_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/joomby $(TARGET_DIR)/usr/bin/joomby
endef

$(eval $(cmake-package))

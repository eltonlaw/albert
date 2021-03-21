PI_MAIN_CONTROLLER_VERSION = 0.0.2
PI_MAIN_CONTROLLER = MIT
PI_MAIN_CONTROLLER_SITE = $(TOPDIR)/package/pi-main-controller
PI_MAIN_CONTROLLER_SITE_METHOD = local
PI_MAIN_CONTROLLER_DEPENDENCIES = qt5base qt5quickcontrols qt5quickcontrols2 qt5charts

define PI_MAIN_CONTROLLER_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/pi-main-controller $(TARGET_DIR)/usr/bin/pi-main-controller
endef

$(eval $(cmake-package))

PI_MAIN_CONTROLLER_VERSION = 0.0.1
PI_MAIN_CONTROLLER_SITE = $(TOPDIR)/package/pi-main-controller
PI_MAIN_CONTROLLER_SITE_METHOD = local

define PI_MAIN_CONTROLLER_BUILD_CMDS
	$(TARGET_CC) -o $(@D)/pi-main-controller $(@D)/main.c
endef

define PI_MAIN_CONTROLLER_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/pi-main-controller $(TARGET_DIR)/usr/bin/pi-main-controller
endef

$(eval $(generic-package))

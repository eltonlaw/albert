################################################################################
#
# albert-temperature-sensor
#
################################################################################

ALBERT_TEMPERATURE_SENSOR_VERSION = 0.0.1
ALBERT_TEMPERATURE_SENSOR_SITE = $(BR2_EXTERNAL_ALBERT_PATH)/package/albert-temperature-sensor
ALBERT_TEMPERATURE_SENSOR_SITE_METHOD = local
ALBERT_TEMPERATURE_SENSOR_DEPENDENCIES = dbus

define ALBERT_TEMPERATURE_SENSOR_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/albert-temperature-sensor $(TARGET_DIR)/usr/bin/albert-temperature-sensor
endef

$(eval $(cmake-package))

TEMPERATURE_SENSOR_VERSION = 0.0.2
TEMPERATURE_SENSOR = MIT
TEMPERATURE_SENSOR_SITE = $(BR2_EXTERNAL_JOOMBY_PATH)/package/temperature-sensor
TEMPERATURE_SENSOR_SITE_METHOD = local
TEMPERATURE_SENSOR_DEPENDENCIES = systemd sdbusplus


define TEMPERATURE_SENSOR_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/temperature-sensor $(TARGET_DIR)/usr/bin/temperature-sensor
endef

define TEMPERATURE_SENSOR_INSTALL_INIT_SYSTEMD
	$(INSTALL) -D -m 644 \
		$(@D)/temperature-sensor.service \
		$(TARGET_DIR)/usr/lib/systemd/system/temperature-sensor.service
endef

ifeq ($(BR2_PACKAGE_DBUS),y)
define TEMPERATURE_SENSOR_INSTALL_DBUS
	$(INSTALL) -D -m 644 \
		$(@D)/org.joomby.TemperatureSensor.conf \
		$(TARGET_DIR)/etc/dbus-1/system.d/org.joomby.TemperatureSensor.conf
endef
endif

$(eval $(cmake-package))

# Assumption that this makefile is run from the root of `pi-main-controller`

build: buildroot/.git
	cd buildroot/ && git reset --hard
	# Synchronize configs from both sides
	@make sync-config
	# Cleanup buildroot build
	@make clean-br
	# Copy over source
	cp -R pi-main-controller/ buildroot/package/pi-main-controller/
	# Copy board files (overwriting existing files if needed)
	cp pi-main-controller/board/* buildroot/board/raspberrypi
	./scripts/run.py add-package
	# Patch qt5webengine so that host-libjpeg and host-freetype are dependencies
	cd buildroot/ && git apply ../patches/0001-package-qt5webengine-needs-host-freetype-host-libjpeg.patch
	# Rebuild project
	@make pi-main-controller-rebuild
	# Run build
	cd buildroot && make
	@make check

check:
	ls buildroot/output/build/pi-main-controller-0.0.2
	ls buildroot/output/target/usr/bin/pi-main-controller

# Whichever config is newer, sync that to the other
sync-config:
	rsync -rtuv pi-main-controller/.config buildroot/.config
	rsync -rtuv buildroot/.config pi-main-controller/.config

clean-br:
	cd buildroot && git checkout -- .
	rm -rf buildroot/package/pi-main-controller

flash: buildroot/output/images/sdcard.img
	stat -c %y buildroot/output/images/sdcard.img
	dd bs=5M if=buildroot/output/images/sdcard.img of=/dev/sdc conv=fsync

# If submodule is not initialized, initialzie it
buildroot/.git:
	git submodule update --init

# Removes cached build and runs rebuild
pi-main-controller-rebuild:
	cd buildroot && make pi-main-controller-dirclean
	cd buildroot && make $@

barebox-menuconfig linux-menuconfig menuconfig uboot-menuconfig:
	cd buildroot && make $@

run:
	cd pi-main-controller && make $@

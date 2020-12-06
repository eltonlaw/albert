# Assumption that this makefile is run from the root of `pi-main-controller`

build: buildroot/.git
	# Synchronize configs from both sides
	@make sync-config
	# Cleanup buildroot build
	@make clean-br
	# Copy over source
	cp -R src/ buildroot/package/pi-main-controller/
	# Copy board files (overwriting existing files if needed)
	cp src/board/* buildroot/board/raspberrypi
	./scripts/run.py add-package
	# Run build
	cd buildroot && make
	@make check

check:
	ls buildroot/output/build/pi-main-controller-0.0.1
	ls buildroot/output/target/usr/bin/pi-main-controller

# Whichever config is newer, sync that to the other
sync-config:
	rsync -rtuv src/.config buildroot/.config
	rsync -rtuv buildroot/.config src/.config

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
rebuild:
	rm -rf buildroot/output/build/
	cd buildroot && make pi-main-controller-rebuild

menuconfig:
	cd buildroot && make $@

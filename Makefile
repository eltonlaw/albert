build: buildroot/.git
	# Synchronize configs from both sides
	@make sync-config
	# Cleanup buildroot build
	@make clean-br
	# Copy over source
	cp -R src/ buildroot/package/pi-main-controller/
	./scripts/run.py add-package
	# -- TODO: create .hash file
	# Run build
	cd buildroot && make

sync-config:
	rsync -rtuv src/.config buildroot/.config
	rsync -rtuv buildroot/.config src/.config

clean-br:
	cd buildroot && git checkout -- .
	rm -rf buildroot/package/pi-main-controller

flash: buildroot/output/images/sdcard.img
	dd bs=5M if=buildroot/output/images/sdcard.img of=/dev/sdc conv=fsync

buildroot/.git:
	git submodule update --init

# Assumption that this makefile is run from the root of `joomby`
BR_EXT=BR2_EXTERNAL=$(PWD)/br-ext-tree

build: buildroot/.git
	cd buildroot/
	# cd buildroot/ && git reset --hard
	# config
	@make joomby_defconfig
	# Rebuild project
	@make joomby-rebuild
	# Run build
	cd buildroot && make $(BR_EXT)
	@make check

check:
	ls buildroot/output/build/joomby-0.0.2
	ls buildroot/output/target/usr/bin/joomby

flash: buildroot/output/images/sdcard.img
	stat -c %y buildroot/output/images/sdcard.img
	dd bs=5M if=buildroot/output/images/sdcard.img of=/dev/sdc conv=fsync

# If submodule is not initialized, initialzie it
buildroot/.git:
	git submodule update --init

# Removes cached build and runs rebuild
joomby-rebuild:
	cd buildroot && make joomby-dirclean $(BR_EXT)
	cd buildroot && make $@ $(BR_EXT)

# Saves
savedefconfig:
	cd buildroot && make $@

barebox-menuconfig linux-menuconfig menuconfig uboot-menuconfig savedefconfig joomby_defconfig dev_defconfig:
	@echo $(BR_EXT)
	cd buildroot && make $@ $(BR_EXT)

run:
	cd br-ext-tree/package/joomby && make $@

clean:
	cd buildroot && make clean

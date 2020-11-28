build: buildroot/.git
	cp .config buildroot/.config
	cd buildroot && make

buildroot/.git:
	git submodule update --init

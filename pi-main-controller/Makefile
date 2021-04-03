.PHONY: build test

# FIXME: the default PI_MAIN_CONTROLLER_BUILD_CMDS seems to be just a `make` so
# whatever the first recipe is will be run as the build command. Make sure this stays
# at the top. (can optionally just define a PI_MAIN_CONTROLLER_BUILD_CMDS)
rebuild:
	rm -rf build
	mkdir build
	cd build && cmake ..
	@make build

run: build
	cd build && ./pi-main-controller

build:
	cd build && make

clean:
	cd build && make $@

test:
	cd test && make test

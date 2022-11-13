.PHONY: build test

BIN=albert-ui

DEBUG=-DCMAKE_BUILD_TYPE=Debug

# FIXME: the default PI_MAIN_CONTROLLER_BUILD_CMDS seems to be just a `make` so
# whatever the first recipe is will be run as the build command. Make sure this stays
# at the top. (can optionally just define a PI_MAIN_CONTROLLER_BUILD_CMDS)
rebuild:
	rm -rf build
	mkdir build
	cd build && cmake .. $(DEBUG)
	@make build

build:
	cd build && make

run: build
	./build/$(BIN)

gdb: build
	gdb ./build/$(BIN)

test: build 
	./build/run_tests

clean:
	cd build && make $@

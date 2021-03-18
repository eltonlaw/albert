.PHONY: build

build:
	cd build && make && ./pi-main-controller

rebuild:
	rm -rf build
	mkdir build
	cd build && cmake ..
	@make build

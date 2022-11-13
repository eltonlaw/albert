# albert

This is a custom linux image for the raspberry pi built with [BuildRoot](https://buildroot.org/). UI built with QT which just charts randomly generated numbers in real time.

![Albert UI demo](https://github.com/eltonlaw/albert/blob/3b02373d56f1f64afe11e74cd11387baf1234f45/docs/demo_01.gif)

## Dev

### Deps

    sudo pacman -S cmake qt5-base qt5-charts qt5-quickcontrols qt5-quickcontrols2

### Building the UI

	cd br-ext-tree/package/albert
    mkdir build && cd build
    cmake ..
    make

### Building the Temperature Sensor Systemd Dbus Server

	cd br-ext-tree/package/temperature-sensor
    mkdir build && cd build
    cmake ..
    make

### Building the OS image

    make build

Basically this generates the custom config defined for this board and calls make in the `buildroot` submodule, providing the custom packages built in this repo to the build process via Buildroot's external tree argument. On build complete, an image will be at `buildroot/output/images/sdcard.img`

### Flashing RPI

My machine has two drives so USBs are generally `/dev/sdc` for me and is hardcoded in the Makefile, this probably needs to be modified depending on your setup (`lsblk`, change the `SD_DEVICE` variable) . Assuming the OS image has been built and exists at `./buildroot/output/images/sdcard.img`, running: 

    make flash

will just `dd` it into the SD card.

### Running Flashed Program

Plugging the SD card in, it boots into a login prompt with credentials `root` and `pass`. To start the UI:

    $ albert-ui

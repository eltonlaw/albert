# pi-main-controller

## Develop on Host Machine

### Deps

#### ArchLinux

Local deps:

    sudo pacman -S cmake qt5-base qt5-charts qt5-quickcontrols qt5-quickcontrols2


To build:

	cd src
    mkdir build
    make

## Building

    make build

## Flashing RPI

My machine has two drives so USBs are generally `/dev/sdc` for me and is hardcoded in the Makefile, this probably needs to be modified depending on your setup (`lsblk`, change the `SD_DEVICE` variable) . Assuming the OS image has been built and exists at `./buildroot/output/images/sdcard.img`, running: 

    make flash

will just `dd` it into the SD card.

## Running Flashed Program

Plugging the SD card in, it boots into a login prompt which are `root` and `pass`.

To start the app run:

    pi-main-controller

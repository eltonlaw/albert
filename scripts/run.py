#!/usr/bin/env python
import os
import pathlib
import sys
import buildroot_utils
import argparse

PACKAGE_NAME = "pi-main-controller"
PI_MAIN_CONTROLLER_SCRIPTS = pathlib.Path(__file__).parent.absolute()
PI_MAIN_CONTROLLER_ROOT = os.path.abspath(f"{PI_MAIN_CONTROLLER_SCRIPTS}/..")

if __name__ == "__main__":
    op = sys.argv[1]
    if op == 'add-package':
        buildroot_utils.config_in_add_package(
            f"{PI_MAIN_CONTROLLER_ROOT}/buildroot", # buildroot root
            ('Target packages', 'Custom'), # Key
            f"package/{PACKAGE_NAME}/Config.in" # value
        )

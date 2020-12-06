def config_in_read(fp):
    print(f"Reading: {fp}")
    config_in_json = {}

    current_menu = []
    with open(fp) as f:
        for line in f.readlines():
            line = line.strip()
            if line == "" or "comment" in line:
                pass
            elif "endmenu" in line:
                # pop from tuple
                current_menu = tuple(list(current_menu)[:-1])
            elif "menu" == line[0:4]:
                title = line[5:].replace('"', '')
                # cast and recast to append to tuple
                current_menu = tuple(list(current_menu) + [title])
                config_in_json[current_menu] = []
            elif "source" in line:
                package_config_path = line[7:].replace('"', '')
                assert current_menu != tuple(), "Before a source exists, there should have been a menu"
                config_in_json[current_menu].append(package_config_path)
    return config_in_json

def config_in_add_package(buildroot_root, menu, source):
    config_in = config_in_read(f"{buildroot_root}/package/Config.in")
    # If key already exists
    if menu in config_in:
        raise Exception(f"{menu} already exists in file")

    with open(f"{buildroot_root}/package/Config.in") as f:
        lines = f.readlines()
        # Find index of last `endmenu`
        index = next(i for i in reversed(range(len(lines))) if lines[i] == 'endmenu\n')
        # Insert in opposite order
        lines.insert(index, '\n')
        lines.insert(index, 'endmenu\n')
        lines.insert(index, '\tsource "package/pi-main-controller/Config.in"\n')
        lines.insert(index, 'menu "Custom"\n')

    with open(f"{buildroot_root}/package/Config.in", "w") as f:
        f.write(''.join(lines))

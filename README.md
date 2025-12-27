# rpi_pico_template - An CMake RaspberryPi Pico project template

This project serves as a starting point for building RaspberryPi Pico microcontroller firmware using a modern CMake-based workflow. It provides a clean structure and convenient integration with toolchains and flashing utilities.

## Features
- **CMake-based build system** for organized and scalable project structure.
- **Configurable Board and Platform**
- **Support for multiple build types** (Debug/Release).
- **Automatic generation of HEX/ELF/UF2** binary outputs.
- **Tasks for flashing and managing firmware** using tools such as `picotool`.

## Requirements
To install all dependencies, run the install-dependencies script under the bin directory.


## Project Structure
```
project-root/
├─ .vscode
|  └─ tasks.json                # Defines vscode tasks for certain flash utilities
├─ bin
|  └─ install-dependencies      # Script to install build and avr dependencies
├─ src/                         # Application source files
├─ include/                     # Header files
├─ .gitignore
├─ .gitmodules                  # Defining submodules such as pico-sdk
├─ CHANGELOG.md
├─ CMakeLists.txt               # Top level CMakeLists.txt
├─ CMakePresets.json            # CMakePresets file for defining build presets
├─ LICENSE
├─ readme.md
└─ sources.cmake                # source.cmake file to set source and include files
```

## Configuration

### Selecting the MCU
Edit your MCU and Board in the CMakePresets.json:
```
"PICO_BOARD": "pico",
"PICO_PLATFORM": "rp2040"
```

### CMake Presets
This project supports convenient presets for common Pico build types:

- `pico-debug` — equivalent to `-DCMAKE_BUILD_TYPE=Debug`
- `pico-release` — equivalent to `-DCMAKE_BUILD_TYPE=Release`

To configure using presets:
```bash
cmake --preset pico-debug
cmake --preset pico-release
```

## Building

### Building with Presets
From the project root:
```bash
cmake --preset pico-debug
cmake --build build/pico-debug
```
Or for release:
```bash
cmake --preset pico-release
cmake --build build/pico-release
```
Generated artifacts (e.g., `.hex`, `.elf`, `.uf2`) will appear in the corresponding preset's build directory.

## Author
Lukas Hammer

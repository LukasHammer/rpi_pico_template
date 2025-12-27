cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
set(PICO_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/pico-sdk)
include(libs/pico-sdk/external/pico_sdk_import.cmake)

include(sources.cmake)

project(pico_template C CXX ASM)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(${PROJECT_NAME} pico_stdlib)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${PROJECT_NAME})
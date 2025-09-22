cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(drivehub_rp2040 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if(NOT DEFINED PICO_SDK_PATH)
    set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
endif()

include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)
pico_sdk_init()

add_executable(drivehub
    src/main.c
    src/g27_translate.c
    src/ffb_forward.c
)

target_include_directories(drivehub PRIVATE include)
target_link_libraries(drivehub pico_stdlib tinyusb_host tinyusb_device)
pico_add_extra_outputs(drivehub)

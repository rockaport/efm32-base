# Base EFM32 CMake file
#
# This can be used as is as a project base, or by adding the efm32-base
# repository as a submodule to another project, copying this CMakeLists file
# to the top level directory, and updating the BASE_LOCATION variable to reflect this
# change
#
## Copyright (c) 2016 Ryan Kurte
# This file is covered under the MIT license available at: https://opensource.org/licenses/MIT

###### Project Environment #####

# Set minimum CMake version
cmake_minimum_required(VERSION 2.8.4)

# optional verbose mode, uncomment or pass in -DCMAKE_VERBOSE_MAKEFILE=ON
set(CMAKE_VERBOSE_MAKEFILE ON)

set(BASE_LOCATION .)
get_filename_component(SDK_ROOT sdk ABSOLUTE)
get_filename_component(APP_ROOT ${SDK_ROOT}/app ABSOLUTE)
get_filename_component(HARDWARE_ROOT ${SDK_ROOT}/hardware ABSOLUTE)
get_filename_component(HARDWARE_ROOT ${SDK_ROOT}/hardware ABSOLUTE)
get_filename_component(PLATFORM_ROOT ${SDK_ROOT}/platform ABSOLUTE)
get_filename_component(MIDDLEWARE_ROOT ${PLATFORM_ROOT}/middleware ABSOLUTE)
get_filename_component(PROTOCOL_ROOT ${SDK_ROOT}/protocol ABSOLUTE)
get_filename_component(DEVICE_ROOT ${PLATFORM_ROOT}/Device/SiliconLabs ABSOLUTE)

# Set the compiler (must be prior to project setup)
set(COMPILER_PREFIX "/home/andrew/opt/gcc-arm-none-eabi/bin/")
include(${BASE_LOCATION}/toolchain/arm-gcc.cmake)

##### Project Setup #####

# Configure project and languages
project(efm32-test C CXX ASM)

# Set device
if (NOT DEVICE)
    #    set(DEVICE EFM32G210F128)
    set(DEVICE BGM13P22F512GA)
    set(BOARD BRD4306A)
    set(BLE_LIB EFR32BG13P)
endif ()

# Set build
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE DEBUG)
endif ()

##### Modules #####

# Libraries can be added to the LIBS variable
# or manually included here.

# Add base libs (emlib, CMSIS, device files)
include(${BASE_LOCATION}/toolchain/efm32-base.cmake)

add_compile_definitions(__STACK_SIZE=0x800 __HEAP_SIZE=0xD00 __StackLimit=0x20000000 HAL_CONFIG=1)

add_subdirectory(common)
add_subdirectory(${APP_ROOT}/bluetooth)
add_subdirectory(${PLATFORM_ROOT}/CMSIS)
add_subdirectory(${DEVICE_ROOT})
add_subdirectory(${PLATFORM_ROOT}/emdrv)
add_subdirectory(${PLATFORM_ROOT}/emlib)
add_subdirectory(${PLATFORM_ROOT}/halconfig)
add_subdirectory(${PLATFORM_ROOT}/bootloader)
add_subdirectory(${PLATFORM_ROOT}/radio/rail_lib)
add_subdirectory(${MIDDLEWARE_ROOT}/glib)
add_subdirectory(${PROTOCOL_ROOT}/bluetooth)
add_subdirectory(${HARDWARE_ROOT})

# this is normally set in efm32-base.cmake, but libraries may modify it so set
# it after libraries/subdirectories have been added
set(CMAKE_EXE_LINKER_FLAGS "${COMMON_DEFINITIONS} -Xlinker -T${LINKER_SCRIPT} -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.map -Wl,--gc-sections -Wl,-v")

##### Files #####

# Add project headers
include_directories(${BASE_LOCATION}/include)

# Generate executable and link
add_executable(${PROJECT_NAME}
        source/advertisement.c
        source/app.c
        source/app_hw.c
        source/application_properties.c
        source/app_ui.c
        source/beacon.c
        source/gatt_db.c
        source/graphics.c
        source/htm.c
        source/ia.c
        source/init_app.c
        source/init_board.c
        source/init_mcu.c
        source/main.c
        source/pti.c)

target_link_libraries(${PROJECT_NAME} ${LIBS} emlib cmsis device bootloader middleware-glib)

# link optional libraries if available
if (${HAS_HARDWARE})
    target_link_libraries(${PROJECT_NAME} hardware)
endif ()

if (${HAS_BLUETOOTH})
    target_link_libraries(${PROJECT_NAME} bluetooth app-bluetooth)
endif ()

if (${HAS_RAIL})
    target_link_libraries(${PROJECT_NAME} rail-lib)
endif ()

##### Post build #####

# Add post build commands
include(${BASE_LOCATION}/toolchain/post-build.cmake)

# Add JLink commands
include(${BASE_LOCATION}/toolchain/jlink.cmake)

##### CMake debug prints #####
if (CMAKE_VERBOSE_MAKEFILE)
    print_debug_info()
endif ()

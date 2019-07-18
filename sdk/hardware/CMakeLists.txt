project(hardware)

if (NOT DEFINED BOARD)
    message("No board defined, skipping hardware")
    set(HAS_HARDWARE FALSE PARENT_SCOPE)
    return()
endif ()

set(HAS_HARDWARE TRUE PARENT_SCOPE)

message("Board defined, adding hardware library for: ${CPU_FAMILY_U}_${BOARD}")

add_library(${PROJECT_NAME}
        kit/common/drivers/display.c
        kit/common/drivers/displayls013b7dh03.c
        kit/common/drivers/displaypalemlib.c
        kit/common/drivers/si7013.c
        kit/common/drivers/i2cspm.c
        kit/common/drivers/mx25flash_spi.c
        kit/common/drivers/udelay.c
        kit/common/bsp/bsp_stk_leds.c)

target_include_directories(${PROJECT_NAME} PUBLIC
        kit/${CPU_FAMILY_U}_${BOARD}/config
        kit/common/bsp
        kit/common/drivers
        kit/common/halconfig
        module/config)

target_link_libraries(${PROJECT_NAME} PUBLIC halconfig common emlib middleware-glib)

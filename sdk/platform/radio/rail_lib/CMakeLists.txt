project(rail-lib)

message("rail: ${DEVICE_L}")
set(RAIL_LIB "${CMAKE_CURRENT_SOURCE_DIR}/autogen/librail_release/librail_config_${DEVICE_L}_gcc.a")

if (NOT EXISTS ${RAIL_LIB})
    message("No rail library, skipping rail lib")
    set(HAS_RAIL FALSE PARENT_SCOPE)
    return()
endif ()

set(HAS_RAIL TRUE PARENT_SCOPE)

message("Found chip specific rail library: ${RAIL_LIB}")

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
        common
        chip/efr32/efr32xg1x
        bluetooth/ble_stack/inc/common
        bluetooth/ble_stack/inc/soc
        protocol/bluetooth/ble_stack/inc/soc)

target_link_libraries(${PROJECT_NAME} INTERFACE
        emlib
        ${CMAKE_CURRENT_SOURCE_DIR}/autogen/librail_release/librail_module_efr32xg13_gcc_release.a
        ${RAIL_LIB})

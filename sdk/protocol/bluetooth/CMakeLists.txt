project(bluetooth)

string(TOLOWER ${DEVICE} DEVICE_L)

set(BLE_LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/ble_stack/linker/GCC/${DEVICE_L}.ld")

if (NOT EXISTS ${BLE_LINKER_SCRIPT})
    message("No bluetooth specific linker script defined, skipping protocol")
    set(HAS_PROTOCOL FALSE PARENT_SCOPE)
    return()
endif ()

set(HAS_BLUETOOTH TRUE PARENT_SCOPE)

message("Found bluetooth specific linker script, using this instead:\n before: ${LINKER_SCRIPT}\n after: ${BLE_LINKER_SCRIPT}")

set(LINKER_SCRIPT ${BLE_LINKER_SCRIPT} PARENT_SCOPE)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
        ble_stack/inc/common
        ble_stack/inc/soc)

target_link_libraries(${PROJECT_NAME} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/${BLE_LIB}/GCC/binapploader.o
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/${BLE_LIB}/GCC/libbluetooth.a
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/${BLE_LIB}/GCC/libpsstore.a
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/${BLE_LIB}/GCC/libmbedtls.a
        emdrv)

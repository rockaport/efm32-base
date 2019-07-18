project(emdrv)

# find . -name '*.c' | sort -u
add_library(${PROJECT_NAME}
        sleep/src/sleep.c)

target_include_directories(${PROJECT_NAME} PUBLIC
        common
        sleep/inc)

target_link_libraries(${PROJECT_NAME} emlib)
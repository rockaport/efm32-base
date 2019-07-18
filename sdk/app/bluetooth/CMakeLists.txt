project(app-bluetooth)

add_library(${PROJECT_NAME}
        common/util/infrastructure.c)

target_include_directories(${PROJECT_NAME} PUBLIC common/util)

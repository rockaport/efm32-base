# sdk components depend on certain app specific header files that result in a
# circular dependency.
project(common)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE .)

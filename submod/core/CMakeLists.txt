file(GLOB_RECURSE CORE_SOURCES src/*.cpp src/*.c src/*.s)
add_library(core ${CORE_SOURCES})
target_include_directories(
    core
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    INTERFACE $<INSTALL_INTERFACE:include>
)

copy_header_files(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include/core)
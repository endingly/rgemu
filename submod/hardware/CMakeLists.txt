file(GLOB_RECURSE HARDWARE_SOURCES src/*.cpp src/*.c src/*.s)
add_library(hardware ${HARDWARE_SOURCES})
target_include_directories(
    hardware
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    INTERFACE $<INSTALL_INTERFACE:include>
)
target_link_libraries(hardware PRIVATE core)

# add_subdirectory(test)

copy_header_files(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include/hardware)
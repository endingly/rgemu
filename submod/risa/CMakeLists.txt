file(GLOB_RECURSE RIAS_SOURCES src/*.cpp src/*.c src/*.s)
add_library(risa ${RIAS_SOURCES})
target_include_directories(
    risa
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    INTERFACE $<INSTALL_INTERFACE:include>
)

copy_header_files(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include/risa)
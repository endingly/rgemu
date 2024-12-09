find_package(GTest CONFIG REQUIRED)
file(GLOB_RECURSE RISA_TEST_SOURCES *.cpp)
add_executable(risa_test ${RISA_TEST_SOURCES})
target_link_libraries(risa_test GTest::gtest GTest::gtest_main risa)
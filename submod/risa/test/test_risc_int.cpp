#include <gtest/gtest.h>

#include <risa/risc_int.hpp>

TEST(RiscIntTest, Addition) {
  using namespace rgemu::risa::base;

  uint5_t a = 1;
  uint5_t b = 2;

  auto result = a & b;
  std::cout << result << std::endl;
  std::cout << sizeof(result) << std::endl;
}

#include <gtest/gtest.h>

#include <risa/risc_int.hpp>

TEST(RiscIntTest, Addition) {
  using namespace rgemu::risa::base;

  uint5_t a = 1;
  std::cout << "a = " << a << std::endl;
  std::cout << sizeof(a) << std::endl;
}

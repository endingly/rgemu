#include <gtest/gtest.h>

#include <risa/risc_int.hpp>

TEST(RiscIntTest, Operator) {
  using namespace rgemu::risa::base;

  uint5_t a    = 1;
  uint5_t b    = 2;
  auto    flag = true;

  // Test bitwise operators
  a & b;
  a | b;
  a ^ b;
  ~a;
  a << 1;
  a >> 1;

  // Test comparison operators
  a == b;
  b == a;
  a != b;
  b != a;
  a < b;
  b < a;
  a <= b;
  b <= a;
  a > b;
  b > a;
  a >= b;
  b >= a;

  // Test base arithmetic operators
  a + b;
  a - b;
  a* b;
  a / b;
  a % b;
  a++;
  a--;
  ++a;
  --a;
  a + 1;
  a - 1;
  a * 1;
  a / 1;
  a % 1;
  1 + a;
  1 - a;
  1 * a;
  1 / a;
  1 % a;



  // test base arithmetic assignment operators
  a += b;
  a -= b;
  a *= b;
  a /= b;
  a %= b;
}

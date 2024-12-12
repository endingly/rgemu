#include <gtest/gtest.h>

#include <risa/risc_int.hpp>

TEST(RiscIntTest, Operator) {
  using namespace rgemu::risa::base;

  uint5_t a    = 4;
  uint5_t b    = 3;
  auto    flag = true;
  uint8_t A    = 4;
  uint8_t B    = 3;

  // Test bitwise operators
  ASSERT_EQ(a & b, A & B);
  ASSERT_EQ(a | b, A | B);
  ASSERT_EQ(a ^ b, A ^ B);
  ASSERT_EQ(~a, (~A) & 0b0001'1111);
  ASSERT_EQ(a << 1, A << 1);
  ASSERT_EQ(a >> 1, A >> 1);

  // Test comparison operators
  ASSERT_EQ(a == b, A == B);
  ASSERT_EQ(a != b, A != B);
  ASSERT_EQ(a < b, A < B);
  ASSERT_EQ(a <= b, A <= B);
  ASSERT_EQ(a > b, A > B);
  ASSERT_EQ(a >= b, A >= B);

  // Test base arithmetic operators
  ASSERT_EQ(a + b, A + B);
  ASSERT_EQ(a - b, A - B);
  ASSERT_EQ(a * b, A * B);
  ASSERT_EQ(a / b, A / B);
  ASSERT_EQ(a % b, A % B);
  ASSERT_EQ(a++, A++);
  ASSERT_EQ(a--, A--);
  ASSERT_EQ(++a, ++A);
  ASSERT_EQ(--a, --A);
  ASSERT_EQ(a + 1, A + 1);
  ASSERT_EQ(a - 1, A - 1);
  ASSERT_EQ(a * 1, A * 1);
  ASSERT_EQ(a / 1, A / 1);
  ASSERT_EQ(a % 1, A % 1);
  ASSERT_EQ(1 + a, 1 + A);
  ASSERT_EQ(1 - a, 1 - A);
  ASSERT_EQ(1 * a, 1 * A);
  ASSERT_EQ(1 / a, 1 / A);
  ASSERT_EQ(1 % a, 1 % A);

  // test base arithmetic assignment operators
  ASSERT_EQ(a += b, A += B);
  ASSERT_EQ(a -= b, A -= B);
  ASSERT_EQ(a *= b, A *= B);
  ASSERT_EQ(a /= b, A /= B);
  ASSERT_EQ(a %= b, A %= B);
  ASSERT_EQ('a' - a, 'a' - A);
}

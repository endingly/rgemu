#pragma once
#include <cstdint>
#include <stdexcept>

namespace rgemu::risa::base {

template <int bitWidth>
struct RiscInt {
  static_assert(bitWidth > 0 && bitWidth <= 64,
                "bitWidth must be greater than 0 and less than or equal to 64");
  constexpr static int MAX_VALUE = (1ULL << bitWidth) - 1;

  uint64_t value : bitWidth;

  RiscInt() : value(0) {}
  RiscInt(uint64_t val) {
    if (val > MAX_VALUE) {
      throw std::out_of_range("Value out of range for RiscInt<" +
                              std::to_string(bitWidth) + ">");
    } else
      value = val;
  }
  operator uint64_t() const { return value; }

  RiscInt<bitWidth>& operator=(uint64_t val) {
    if (val > MAX_VALUE) {
      throw std::out_of_range("Value out of range for RiscInt<" +
                              std::to_string(bitWidth) + ">");
    } else
      value = val;
    return *this;
  }

  RiscInt<bitWidth>& operator+=(const RiscInt<bitWidth>& other) {
    value += other.value;
    return *this;
  }

  RiscInt<bitWidth>& operator-=(const RiscInt<bitWidth>& other) {
    value -= other.value;
    return *this;
  }

  RiscInt<bitWidth>& operator*=(const RiscInt<bitWidth>& other) {
    value *= other.value;
    return *this;
  }

  RiscInt<bitWidth>& operator/=(const RiscInt<bitWidth>& other) {
    if (other.value == 0) {
      throw std::runtime_error("Division by zero");
    }
    value /= other.value;
    return *this;
  }

  RiscInt<bitWidth>& operator%=(const RiscInt<bitWidth>& other) {
    if (other.value == 0) {
      throw std::runtime_error("Division by zero");
    }
    value %= other.value;
    return *this;
  }

  RiscInt<bitWidth>& operator&=(const RiscInt<bitWidth>& other) {
    value &= other.value;
    return *this;
  }

  RiscInt<bitWidth>& operator|=(const RiscInt<bitWidth>& other) {
    value |= other.value;
    return *this;
  }

  RiscInt<bitWidth>& operator^=(const RiscInt<bitWidth>& other) {
    value ^= other.value;
    return *this;
  }

  RiscInt<bitWidth>& operator<<=(const RiscInt<bitWidth>& other) {
    value <<= other.value;
    return *this;
  }

  RiscInt<bitWidth>& operator>>=(const RiscInt<bitWidth>& other) {
    value >>= other.value;
    return *this;
  }

  RiscInt<bitWidth> operator+(const RiscInt<bitWidth>& other) const {
    RiscInt<bitWidth> result(*this);
    result += other;
    return result;
  }

  RiscInt<bitWidth> operator-(const RiscInt<bitWidth>& other) const {
    RiscInt<bitWidth> result(*this);
    result -= other;
    return result;
  }

  RiscInt<bitWidth> operator*(const RiscInt<bitWidth>& other) const {
    RiscInt<bitWidth> result(*this);
    result *= other;
    return result;
  }

  RiscInt<bitWidth> operator/(const RiscInt<bitWidth>& other) const {
    RiscInt<bitWidth> result(*this);
    result /= other;
    return result;
  }

  RiscInt<bitWidth> operator%(const RiscInt<bitWidth>& other) const {
    RiscInt<bitWidth> result(*this);
    result %= other;
    return result;
  }

  RiscInt<bitWidth> operator&(const RiscInt<bitWidth>& other) const {
    RiscInt<bitWidth> result(*this);
    result &= other;
    return result;
  }

  RiscInt<bitWidth> operator|(const RiscInt<bitWidth>& other) const {
    RiscInt<bitWidth> result(*this);
    result |= other;
    return result;
  }

  RiscInt<bitWidth> operator^(const RiscInt<bitWidth>& other) const {
    RiscInt<bitWidth> result(*this);
    result ^= other;
    return result;
  }

  RiscInt<bitWidth> operator<<(const RiscInt<bitWidth>& other) const {
    RiscInt<bitWidth> result(*this);
    result <<= other;
    return result;
  }

  RiscInt<bitWidth> operator>>(const RiscInt<bitWidth>& other) const {
    RiscInt<bitWidth> result(*this);
    result >>= other;
    return result;
  }

  bool operator==(const RiscInt<bitWidth>& other) const {
    return value == other.value;
  }

  bool operator!=(const RiscInt<bitWidth>& other) const {
    return value != other.value;
  }

  bool operator<(const RiscInt<bitWidth>& other) const {
    return value < other.value;
  }

  bool operator<=(const RiscInt<bitWidth>& other) const {
    return value <= other.value;
  }

  bool operator>(const RiscInt<bitWidth>& other) const {
    return value > other.value;
  }

  bool operator>=(const RiscInt<bitWidth>& other) const {
    return value >= other.value;
  }

  RiscInt<bitWidth> operator<<(int shift) const {
    RiscInt<bitWidth> result(*this);
    result <<= shift;
    return result;
  }

  RiscInt<bitWidth> operator>>(int shift) const {
    RiscInt<bitWidth> result(*this);
    result >>= shift;
    return result;
  }
};

using uint3_t = RiscInt<3>;
using uint5_t = RiscInt<5>;
using uint6_t = RiscInt<6>;
using uint7_t = RiscInt<7>;

};  // namespace rgemu::risa::base

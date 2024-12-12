#pragma once
#include <bitset>
#include <concepts>
#include <cstdint>
#include <stdexcept>

namespace rgemu::risa::base {

template <int bitWidth>
struct RiscInt {

  constexpr static int BIT_WIDTH = bitWidth;
  static_assert(bitWidth > 0 && bitWidth <= 64,
                "bitWidth must be greater than 0 and less than or equal to 64");

  // define base int types
  consteval static auto get_base_type() {
    if constexpr (bitWidth <= 8) {
      return uint8_t{};
    } else if constexpr (bitWidth <= 16) {
      return uint16_t{};
    } else if constexpr (bitWidth <= 32) {
      return uint32_t{};
    } else {
      return uint64_t{};
    }
  }

  using base_type = decltype(get_base_type());

  constexpr static int BASE_WIDTH = sizeof(base_type) * 8;

  constexpr static base_type MAX_VALUE = (1ULL << bitWidth) - 1;

  constexpr static base_type MASK =
      static_cast<base_type>(~(MAX_VALUE << bitWidth));

  base_type value;

#pragma region constructors and init

  RiscInt() : value(0) {}

  template <std::integral T>
  RiscInt(T val) {
    value = val & MASK;
  }

  RiscInt(const RiscInt& other) : value(other.value) {}

  RiscInt& operator=(const RiscInt& other) {
    value = other.value;
    return *this;
  }

  template <std::integral T>
  RiscInt& operator=(T val) {
    value = val & MASK;
    return *this;
  }

#pragma endregion

#pragma region concertions

  template <std::integral T>
  operator T() const {
    return static_cast<T>(value);
  }

#pragma endregion

#pragma region std in and out

  friend std::ostream& operator<<(std::ostream& os, const RiscInt& val) {
    os << val.value;
    return os;
  }

  friend std::istream& operator>>(std::istream& is, RiscInt& val) {
    is >> val.value;
    return is;
  }

#pragma endregion

#pragma region bitwise operators

  RiscInt<bitWidth> operator~() const { return RiscInt<bitWidth>(~value); }

  RiscInt<bitWidth> operator&(const RiscInt<bitWidth>& other) const {
    return RiscInt<bitWidth>(value & other.value);
  }

  RiscInt<bitWidth>& operator&=(const RiscInt<bitWidth>& other) {
    value = value & other.value & MASK;
    return *this;
  }

  RiscInt<bitWidth> operator|(const RiscInt<bitWidth>& other) const {
    return RiscInt<bitWidth>(value | other.value);
  }

  RiscInt<bitWidth>& operator|=(const RiscInt<bitWidth>& other) {
    value = value | other.value | MASK;
    return *this;
  }

  RiscInt<bitWidth> operator^(const RiscInt<bitWidth>& other) const {
    return RiscInt<bitWidth>(value ^ other.value);
  }

  RiscInt<bitWidth>& operator^=(const RiscInt<bitWidth>& other) {
    value = value ^ other.value | MASK;
    return *this;
  }

  RiscInt<bitWidth> operator<<(const RiscInt<bitWidth>& other) const {
    return RiscInt<bitWidth>(value
                             << static_cast<uint32_t>(other.value & MASK));
  }

  RiscInt<bitWidth>& operator<<=(const RiscInt<bitWidth>& other) {
    value <<= static_cast<uint32_t>(other.value & MASK);
    return *this;
  }

  RiscInt<bitWidth> operator>>(const RiscInt<bitWidth>& other) const {
    return RiscInt<bitWidth>(value >>
                             static_cast<uint32_t>(other.value & MASK));
  }

  RiscInt<bitWidth>& operator>>=(const RiscInt<bitWidth>& other) {
    value >>= static_cast<uint32_t>(other.value & MASK);
    return *this;
  }

  // template for integer types
  template <std::integral T>
  RiscInt<bitWidth> operator&(T other) const {
    return RiscInt<bitWidth>(value & other);
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator&=(T other) {
    value = value & other & MASK;
    return *this;
  }

  template <std::integral T>
  RiscInt<bitWidth> operator|(T other) const {
    return RiscInt<bitWidth>(value | other);
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator|=(T other) {
    value = value | other & MASK;
    return *this;
  }

  template <std::integral T>
  RiscInt<bitWidth> operator^(T other) const {
    return RiscInt<bitWidth>(value ^ other);
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator^=(T other) {
    value = value ^ other & MASK;
    return *this;
  }

  template <std::integral T>
  RiscInt<bitWidth> operator<<(T other) const {
    return RiscInt<bitWidth>(value << other);
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator<<=(T other) {
    value = (value << other) & MASK;
    return *this;
  }

  template <std::integral T>
  RiscInt<bitWidth> operator>>(T other) const {
    return RiscInt<bitWidth>(value >> other);
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator>>=(T other) {
    value = (value >> other) & MASK;
    return *this;
  }

#pragma endregion

#pragma region arithmetic operators

  // 算术运算符重载
  auto operator+(const RiscInt<bitWidth>& other) const {
    return value + other.value;
  }

  RiscInt<bitWidth>& operator+=(const RiscInt<bitWidth>& other) {
    auto result = value + other.value;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    value = result;
    return *this;
  }

  auto operator-(const RiscInt<bitWidth>& other) const {
    auto result = value - other.value;
    return result;
  }

  auto operator-() const { return -value; }

  RiscInt<bitWidth>& operator-=(const RiscInt<bitWidth>& other) {
    auto result = value - other.value;
    if (result < 0) {
      result = 0;
    }
    value = result;
    return *this;
  }

  auto operator*(const RiscInt<bitWidth>& other) const {
    return value * other.value;
  }

  RiscInt<bitWidth>& operator*=(const RiscInt<bitWidth>& other) {
    auto result = value * other.value;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    value = result & MASK;
    return *this;
  }

  auto operator/(const RiscInt<bitWidth>& other) const {
    if (other.value == 0) {
      throw std::runtime_error("division by zero");
    }
    auto result = value / other.value;
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth>& operator/=(const RiscInt<bitWidth>& other) {
    if (other.value == 0) {
      throw std::runtime_error("division by zero");
    }
    auto result = value / other.value;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    value = result & MASK;
    return *this;
  }

  auto operator%(const RiscInt<bitWidth>& other) const {
    if (other.value == 0) {
      throw std::runtime_error("division by zero");
    }
    return value % other.value;
  }

  RiscInt<bitWidth>& operator%=(const RiscInt<bitWidth>& other) {
    if (other.value == 0) {
      throw std::runtime_error("division by zero");
    }
    auto result = value % other.value;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    value = result & MASK;
    return *this;
  }

  // template for integer types
  template <std::integral T>
  auto operator+(T other) const {
    return value + other;
  }

  template <std::integral T>
  friend T operator+(T other, const RiscInt<bitWidth>& val) {
    return other + val.value;
  }

  // ++
  RiscInt<bitWidth>& operator++() {
    if (value == std::numeric_limits<base_type>::max()) {
      throw std::overflow_error("Incrementing would cause overflow.");
    }
    ++value;
    return *this;
  }

  RiscInt<bitWidth> operator++(int) {
    auto result = *this;
    ++(*this);
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator+=(T other) {
    auto result = value + other;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    value = result & MASK;
    return *this;
  }

  template <std::integral T>
  auto operator-(T other) const {
    auto result = value - other;
    return result;
  }

  RiscInt<bitWidth>& operator--() {
    if (value == 0) {
      throw std::underflow_error("Decrementing would cause underflow.");
    }
    --value;
    return *this;
  }

  RiscInt<bitWidth> operator--(int) {
    RiscInt temp = *this;
    --(*this);
    return temp;
  }

  template <std::integral T>
  friend auto operator-(T other, const RiscInt<bitWidth>& val) {
    return other - val.value;
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator-=(T other) {
    auto result = value - other;
    if (result < 0) {
      result = 0;
    }
    value = result & MASK;
    return *this;
  }

  template <std::integral T>
  auto operator*(T other) const {
    return value * other;
  }

  template <std::integral T>
  friend auto operator*(T other, const RiscInt<bitWidth>& val) {
    auto result = val.value * other;
    return result;
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator*=(T other) {
    auto result = value * other;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    value = result & MASK;
    return *this;
  }

  template <std::integral T>
  auto operator/(T other) const {
    if (other == 0) {
      throw std::runtime_error("division by zero");
    }
    auto result = value / other;
    return result;
  }

  template <std::integral T>
  friend auto operator/(T other, const RiscInt<bitWidth>& val) {
    if (val.value == 0) {
      throw std::runtime_error("division by zero");
    }
    auto result = other / val.value;
    return result;
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator/=(T other) {
    if (other == 0) {
      throw std::runtime_error("division by zero");
    }
    auto result = value / other;
    if (result < 0) {
      result = 0;
    }
    value = result & MASK;
    return *this;
  }

  template <std::integral T>
  auto operator%(T other) const {
    if (other == 0) {
      throw std::runtime_error("division by zero");
    }
    return value % other;
  }

  template <std::integral T>
  friend auto operator%(T other, const RiscInt<bitWidth>& val) {
    if (val.value == 0) {
      throw std::runtime_error("division by zero");
    }
    auto result = other % val.value;
    return result;
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator%=(T other) {
    if (other == 0) {
      throw std::runtime_error("division by zero");
    }
    auto result = value % other;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    value = result & MASK;
    return *this;
  }

#pragma endregion

#pragma region logical operators

  // 逻辑运算符重载
  bool operator!() const { return !value; }

  bool operator&&(const RiscInt<bitWidth>& other) const {
    return value && other.value;
  }

  bool operator||(const RiscInt<bitWidth>& other) const {
    return value || other.value;
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

  bool operator==(const RiscInt<bitWidth>& other) const {
    return value == other.value;
  }

  bool operator!=(const RiscInt<bitWidth>& other) const {
    return value != other.value;
  }

  // template for integer types
  template <std::integral T>
  bool operator&&(T other) const {
    return value && other;
  }

  template <std::integral T>
  bool operator||(T other) const {
    return value || other;
  }

  template <std::integral T>
  bool operator<(T other) const {
    return value < other;
  }

  template <std::integral T>
  bool operator<=(T other) const {
    return value <= other;
  }

  template <std::integral T>
  bool operator>(T other) const {
    return value > other;
  }

  template <std::integral T>
  bool operator>=(T other) const {
    return value >= other;
  }

  template <std::integral T>
  bool operator==(T other) const {
    return value == other;
  }

  template <std::integral T>
  bool operator!=(T other) const {
    return value != other;
  }

  template <std::integral T>
  friend bool operator&&(T other, const RiscInt<bitWidth>& val) {
    return other && val.value;
  }

  template <std::integral T>
  friend bool operator||(T other, const RiscInt<bitWidth>& val) {
    return other || val.value;
  }

  template <std::integral T>
  friend bool operator<(T other, const RiscInt<bitWidth>& val) {
    return other < val.value;
  }

  template <std::integral T>
  friend bool operator<=(T other, const RiscInt<bitWidth>& val) {
    return other <= val.value;
  }

  template <std::integral T>
  friend bool operator>(T other, const RiscInt<bitWidth>& val) {
    return other > val.value;
  }

  template <std::integral T>
  friend bool operator>=(T other, const RiscInt<bitWidth>& val) {
    return other >= val.value;
  }

  template <std::integral T>
  friend bool operator==(T other, const RiscInt<bitWidth>& val) {
    return other == val.value;
  }

  template <std::integral T>
  friend bool operator!=(T other, const RiscInt<bitWidth>& val) {
    return other != val.value;
  }

#pragma endregion
};

using uint3_t = RiscInt<3>;
using uint5_t = RiscInt<5>;
using uint6_t = RiscInt<6>;
using uint7_t = RiscInt<7>;
};  // namespace rgemu::risa::base

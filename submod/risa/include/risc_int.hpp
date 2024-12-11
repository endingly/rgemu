#pragma once
#include <bitset>
#include <concepts>
#include <cstdint>
#include <stdexcept>

namespace rgemu::risa::base {

template <int bitWidth>
struct RiscInt {

  std::bitset<bitWidth> value;

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

  constexpr static base_type MAX_VALUE = (1ULL << bitWidth) - 1;

  RiscInt() : value(0) {}

  template <std::integral T>
  RiscInt(T val) : value(val) {}

  RiscInt(std::bitset<bitWidth> val) : value(val) {}

  RiscInt(const RiscInt<bitWidth>& other) : value(other.value) {}

  RiscInt<bitWidth>& operator=(const RiscInt<bitWidth>& other) {
    value = other.value;
    return *this;
  }

  template <std::integral T>
  RiscInt<bitWidth>& operator=(T val) {
    if (val > MAX_VALUE) {
      val = MAX_VALUE;
    } else
      value = val;
    return *this;
  }

  RiscInt<bitWidth>& operator+=(const RiscInt<bitWidth>& other) {
    auto result = value.to_ulong() + other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth>& operator-=(const RiscInt<bitWidth>& other) {
    auto result = value.to_ulong() - other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth>& operator*=(const RiscInt<bitWidth>& other) {
    auto result = value.to_ulong() * other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth>& operator/=(const RiscInt<bitWidth>& other) {
    if (other.value.to_ulong() == 0) {
      throw std::runtime_error("Division by zero");
    }
    auto result = value.to_ulong() / other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth>& operator%=(const RiscInt<bitWidth>& other) {
    if (other.value.to_ulong() == 0) {
      throw std::runtime_error("Division by zero");
    }
    auto result = value.to_ulong() % other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth>& operator&=(const RiscInt<bitWidth>& other) {
    auto result = value.to_ulong() & other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth>& operator|=(const RiscInt<bitWidth>& other) {
    auto result = value.to_ulong() | other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth>& operator^=(const RiscInt<bitWidth>& other) {
    auto result = value.to_ulong() ^ other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth>& operator++() {
    auto result = value.to_ulong() + 1;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth> operator++(int) {
    auto result = value.to_ulong() + 1;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth>& operator--() {
    auto result = value.to_ulong() - 1;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth> operator--(int) {
    auto result = value.to_ulong() - 1;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator~() const {
    auto result = ~value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator-() const {
    auto result = -value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator+(const RiscInt<bitWidth>& other) const {
    auto result = value.to_ulong() + other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  RiscInt<bitWidth> operator+(T other) const {
    auto result = value.to_ulong() + other;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  friend RiscInt<bitWidth> operator+(T other, const RiscInt<bitWidth>& self) {
    auto result = self.value.to_ulong() + other;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  friend RiscInt<bitWidth> operator*(T other, const RiscInt<bitWidth>& self) {
    auto result = self.value.to_ulong() * other;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator-(const RiscInt<bitWidth>& other) const {
    auto result = value.to_ulong() - other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  friend RiscInt<bitWidth> operator-(T other, const RiscInt<bitWidth>& self) {
    auto result = other - self.value.to_ulong();
    if (result > MAX_VALUE)
      result = MAX_VALUE;
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator*(const RiscInt<bitWidth>& other) const {
    auto result = value.to_ulong() * other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  RiscInt<bitWidth> operator*(T other) const {
    auto result = value.to_ulong() * other;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator/(const RiscInt<bitWidth>& other) const {
    if (other.value.to_ulong() == 0) {
      throw std::runtime_error("Division by zero");
    }
    auto result = value.to_ulong() / other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  RiscInt<bitWidth> operator/(T other) const {
    if (other == 0) {
      throw std::runtime_error("Division by zero");
    }
    auto result = value.to_ulong() / other;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  friend RiscInt<bitWidth> operator/(T other, const RiscInt<bitWidth>& self) {
    if (self.value.to_ulong() == 0) {
      throw std::runtime_error("Division by zero");
    }
    auto result = other / self.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator%(const RiscInt<bitWidth>& other) const {
    if (other.value.to_ulong() == 0) {
      throw std::runtime_error("Division by zero");
    }
    auto result = value.to_ulong() % other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  RiscInt<bitWidth> operator%(T other) const {
    if (other == 0) {
      throw std::runtime_error("Division by zero");
    }
    auto result = value.to_ulong() % other;
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  friend RiscInt<bitWidth> operator%(T other, const RiscInt<bitWidth>& self) {
    if (self.value.to_ulong() == 0) {
      throw std::runtime_error("Division by zero");
    }
    auto result = other % self.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    }
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator&(const RiscInt<bitWidth>& other) const {
    std::bitset<bitWidth> result = (value & other.value);
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator|(const RiscInt<bitWidth>& other) const {
    std::bitset<bitWidth> result = (value | other.value);
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator^(const RiscInt<bitWidth>& other) const {
    std::bitset<bitWidth> result = (value ^ other.value);
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  RiscInt<bitWidth> operator&(T other) const {
    std::bitset<bitWidth> result = (value & other);
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  RiscInt<bitWidth> operator|(T other) const {
    std::bitset<bitWidth> result = (value | other);
    return RiscInt<bitWidth>(result);
  }

  template <std::integral T>
  RiscInt<bitWidth> operator^(T other) const {
    std::bitset<bitWidth> result = (value ^ other);
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator<<(int shift) const {
    std::bitset<bitWidth> result = (value << shift);
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator>>(int shift) const {
    std::bitset<bitWidth> result = (value >> shift);
    return RiscInt<bitWidth>(result);
  }

  bool operator==(const RiscInt<bitWidth>& other) const {
    return value == other.value;
  }

  bool operator!=(const RiscInt<bitWidth>& other) const {
    return value != other.value;
  }

  bool operator<(const RiscInt<bitWidth>& other) const {
    return value.to_ulong() < other.value.to_ulong();
  }

  bool operator<=(const RiscInt<bitWidth>& other) const {
    return value.to_ulong() <= other.value.to_ulong();
  }

  bool operator>(const RiscInt<bitWidth>& other) const {
    return value.to_ulong() > other.value.to_ulong();
  }

  bool operator>=(const RiscInt<bitWidth>& other) const {
    return value.to_ulong() >= other.value.to_ulong();
  }

  template <std::integral T>
  bool operator==(const T& other) const {
    return value.to_ulong() == other;
  }

  template <std::integral T>
  bool operator!=(const T& other) const {
    return value.to_ulong() != other;
  }

  template <std::integral T>
  bool operator<(const T& other) const {
    return value.to_ulong() < other;
  }

  template <std::integral T>
  bool operator<=(const T& other) const {
    return value.to_ulong() <= other;
  }

  template <std::integral T>
  bool operator>=(const T& other) const {
    return value.to_ulong() >= other;
  }

  friend std::ostream& operator<<(std::ostream&            os,
                                  const RiscInt<bitWidth>& obj) {
    os << obj.value.to_ulong();
    return os;
  }
};

using uint3_t = RiscInt<3>;
using uint5_t = RiscInt<5>;
using uint6_t = RiscInt<6>;
using uint7_t = RiscInt<7>;
};  // namespace rgemu::risa::base

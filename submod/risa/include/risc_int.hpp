#pragma once
#include <bitset>
#include <cstdint>
#include <stdexcept>

namespace rgemu::risa::base {

template <int bitWidth>
struct RiscInt {

  std::bitset<bitWidth> value;

  static_assert(bitWidth > 0 && bitWidth <= 64,
                "bitWidth must be greater than 0 and less than or equal to 64");
  constexpr static uint32_t MAX_VALUE = (1ULL << bitWidth) - 1;

  RiscInt() : value(0) {}

  RiscInt(uint64_t val) : value(val) {}

  RiscInt(std::bitset<bitWidth> val) : value(val) {}

  RiscInt(const RiscInt<bitWidth>& other) : value(other.value) {}

  RiscInt<bitWidth>& operator=(const RiscInt<bitWidth>& other) {
    value = other.value;
    return *this;
  }

  RiscInt<bitWidth>& operator=(uint64_t val) {
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

  RiscInt<bitWidth>& operator<<=(const RiscInt<bitWidth>& other) {
    auto result = value.to_ulong() << other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return *this;
  }

  RiscInt<bitWidth>& operator>>=(const RiscInt<bitWidth>& other) {
    auto result = value.to_ulong() >> other.value.to_ulong();
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
    } else
      value = result;
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
    } else
      value = result;
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator~() const {
    auto result = ~value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator-() const {
    auto result = -value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator+(const RiscInt<bitWidth>& other) const {
    auto result = value.to_ulong() + other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator*(const RiscInt<bitWidth>& other) const {
    auto result = value.to_ulong() * other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator/(const RiscInt<bitWidth>& other) const {
    if (other.value.to_ulong() == 0) {
      throw std::runtime_error("Division by zero");
    }
    auto result = value.to_ulong() / other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
    return RiscInt<bitWidth>(result);
  }

  RiscInt<bitWidth> operator%(const RiscInt<bitWidth>& other) const {
    if (other.value.to_ulong() == 0) {
      throw std::runtime_error("Division by zero");
    }
    auto result = value.to_ulong() % other.value.to_ulong();
    if (result > MAX_VALUE) {
      result = MAX_VALUE;
    } else
      value = result;
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

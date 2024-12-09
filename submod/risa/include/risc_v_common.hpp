#pragma once
#include <cstdint>
#include <type_traits>

namespace rgemu::risa {

template <typename T>
concept is_support_type =
    std::is_same_v<T, uint32_t> || std::is_same_v<T, uint64_t>;

template <is_support_type T>
constexpr T zero;

template <is_support_type T>
constexpr T ra;

template <is_support_type T>
constexpr T sp;

template <is_support_type T>
constexpr T gp;

template <is_support_type T>
constexpr T tp;

template <is_support_type T>
constexpr T t0;

template <is_support_type T>
constexpr T t1;

template <is_support_type T>
constexpr T t2;

template <is_support_type T>
constexpr T s0;

template <is_support_type T>
constexpr T s1;

template <is_support_type T>
constexpr T a0;

template <is_support_type T>
constexpr T a1;

template <is_support_type T>
constexpr T a2;

template <is_support_type T>
constexpr T a3;

template <is_support_type T>
constexpr T a4;

template <is_support_type T>
constexpr T a5;

template <is_support_type T>
constexpr T a6;

template <is_support_type T>
constexpr T a7;

template <is_support_type T>
constexpr T s2;

template <is_support_type T>
constexpr T s3;

template <is_support_type T>
constexpr T s4;

template <is_support_type T>
constexpr T s5;

template <is_support_type T>
constexpr T s6;

template <is_support_type T>
constexpr T s7;

template <is_support_type T>
constexpr T s8;

template <is_support_type T>
constexpr T s9;

template <is_support_type T>
constexpr T s10;

template <is_support_type T>
constexpr T s11;

template <is_support_type T>
constexpr T t3;

template <is_support_type T>
constexpr T t4;

template <is_support_type T>
constexpr T t5;

template <is_support_type T>
constexpr T t6;
};  // namespace rgemu::risa

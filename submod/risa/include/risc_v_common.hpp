#pragma once
#include <cstdint>
#include <type_traits>

namespace rgemu::risa {

template <typename T>
concept is_support_type =
    std::is_same_v<T, uint32_t> || std::is_same_v<T, uint64_t>;

template <is_support_type T>
struct RiscvRegFile {
  T zero;
  T ra;
  T sp;
  T gp;
  T tp;
  T t0;
  T t1;
  T t2;
  T s0;
  T s1;
  T a0;
  T a1;
  T a2;
  T a3;
  T a4;
  T a5;
  T a6;
  T a7;
  T s2;
  T s3;
  T s4;
  T s5;
  T s6;
  T s7;
  T s8;
  T s9;
  T s10;
  T s11;
  T t3;
  T t4;
  T t5;
  T t6;
};

};  // namespace rgemu::risa

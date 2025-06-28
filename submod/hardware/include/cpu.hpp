#pragma once
#include <unordered_map>
#include "bus.hpp"

namespace rgemu::hardware {

struct cpu_t {

  using RegType                  = uint64_t;
  using OpcodeLength             = uint32_t;
  constexpr static size_t RegNum = 32;

  RegType pc;                 // Program Counter
  RegType registers[RegNum];  // General-purpose registers
  bus_t   bus;

  void initialize();

 private:
  RegType read(uint64_t address, bus_write_size_t size);
  void    write(uint64_t address, bus_write_size_t size, RegType value);
};

}  // namespace rgemu::hardware
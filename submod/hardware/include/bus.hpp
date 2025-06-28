#pragma once
#include "dram.hpp"

namespace rgemu::hardware {

enum class bus_write_size_t { BYTE = 1, WORD = 2, DWORD = 4, QWORD = 8 };

struct bus_t {
  dram_t dram;

  uint64_t read(uint64_t address, bus_write_size_t size);

  void write(uint64_t address, bus_write_size_t size, uint64_t value);
};

}  // namespace rgemu::hardware

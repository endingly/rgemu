#include "dram.hpp"

namespace rgemu::hardware {

uint64_t dram_t::read(uint64_t          address,
                      dram_write_size_t size = dram_write_size_t::BYTE) {
  auto start  = address - DRAM_BASE;
  auto offset = static_cast<uint64_t>(size);

  if (offset == 0 || offset > DRAM_SIZE || start + offset > DRAM_SIZE) {
    throw std::out_of_range("Read size out of range");
  }

  // little endian read
  switch (size) {
    case dram_write_size_t::BYTE:
      return memory[start];
    case dram_write_size_t::WORD:
      return *reinterpret_cast<uint16_t*>(&memory[start]);
    case dram_write_size_t::DWORD:
      return *reinterpret_cast<uint32_t*>(&memory[start]);
    case dram_write_size_t::QWORD:
      return *reinterpret_cast<uint64_t*>(&memory[start]);
    default:
      throw std::invalid_argument("Invalid read size");
  }
}

void dram_t::write(uint64_t address, dram_write_size_t size, uint64_t value) {
  auto start  = address - DRAM_BASE;
  auto offset = static_cast<uint64_t>(size);

  if (offset == 0 || offset > DRAM_SIZE || start + offset > DRAM_SIZE) {
    throw std::out_of_range("Write size out of range");
  }
  // little endian write
  switch (size) {
    case dram_write_size_t::BYTE:
      memory[start] = static_cast<uint8_t>(value);
      break;
    case dram_write_size_t::WORD:
      *reinterpret_cast<uint16_t*>(&memory[start]) =
          static_cast<uint16_t>(value);
      break;
    case dram_write_size_t::DWORD:
      *reinterpret_cast<uint32_t*>(&memory[start]) =
          static_cast<uint32_t>(value);
      break;
    case dram_write_size_t::QWORD:
      *reinterpret_cast<uint64_t*>(&memory[start]) = value;
      break;
    default:
      throw std::invalid_argument("Invalid write size");
  }
}

};  // namespace rgemu::hardware
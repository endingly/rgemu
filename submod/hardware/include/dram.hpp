#pragma once
#include <algorithm>
#include <cstdint>
#include <stdexcept>

namespace rgemu::hardware {

constexpr uint64_t DRAM_SIZE = 1024 * 1024 * 1;  // 1 MB DRAM size
constexpr uint64_t DRAM_BASE = 0x80000000;       // Base address for DRAM

/// @brief Enumeration for DRAM write sizes
/// This enum defines the sizes of writes that can be performed to DRAM.
/// It is used to specify the size of data being written to the DRAM.
/// @note The sizes are defined in bytes.
enum class dram_write_size_t : uint8_t {
  BYTE  = 1,  // Write size of 1 byte
  WORD  = 2,  // Write size of 2 bytes
  DWORD = 4,  // Write size of 4 bytes
  QWORD = 8   // Write size of 8 bytes
};

struct dram_t {

  uint8_t memory[DRAM_SIZE];  // Memory array to simulate DRAM

  /// @brief Constructor to initialize the DRAM
  dram_t() {
    std::fill(memory, memory + DRAM_SIZE, 0);  // C++20 way to initialize memory
  }

  /// Function to read a byte from DRAM
  /// @param address The address to read from
  /// @param size The size of the read operation (default is BYTE)
  uint64_t read(uint64_t address, dram_write_size_t size);

  /// Function to write a byte to DRAM
  /// @param address The address to write to
  /// @param value The value to write
  /// @throws `std::out_of_range` if the address is out of bounds
  /// @note This function does not support writing more than one byte at a time
  void write(uint64_t address, dram_write_size_t size = dram_write_size_t::BYTE,
             uint64_t value);
};

};  // namespace rgemu::hardware
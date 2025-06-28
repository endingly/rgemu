#pragma once
#include <concepts>
#include <cstdint>
#include <type_traits>

namespace rgemu::core {

template <typename T>
concept Is_uint = std::is_unsigned_v<T>;

using DefaultRegType      = uint64_t;
using DefaultOpcodeLength = uint32_t;

template <Is_uint RegType_, Is_uint OpcodeLength_ = DefaultOpcodeLength>
// hardware operations abstract
class IHardwareOperations {
 public:
  using RegType                                             = RegType_;
  using OpcodeLength                                        = OpcodeLength_;
  virtual RegType readRegister(uint8_t reg)                 = 0;
  virtual void    writeRegister(uint8_t reg, RegType value) = 0;
  virtual RegType loadMemory(uint32_t addr)                 = 0;
  virtual void    storeMemory(uint32_t addr, RegType value) = 0;
  virtual ~IHardwareOperations()                            = default;
};

template <Is_uint OpcodeLength_, Is_uint RegType_ = DefaultRegType>
// ISA operations abstract
class IISAOperations {
 public:
  using RegType                                        = RegType_;
  using OpcodeLength                                   = OpcodeLength_;
  virtual void executeInstruction(OpcodeLength opcode) = 0;
  virtual bool decodeInstruction(OpcodeLength opcode)  = 0;
  virtual ~IISAOperations()                            = default;
};

};  // namespace rgemu::core
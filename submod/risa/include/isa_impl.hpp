#pragma once
#include <core/abstraction.hpp>
#include <memory>
#include "instruction.hpp"

namespace rgemu::risa::interface {

class isa_impl : public core::IISAOperations<rgemu::risa::OpCodeCell> {

 private:
  using BaseType         = core::IISAOperations<rgemu::risa::OpCodeCell>;
  using instruction_type = rgemu::risa::instruction_type;
  using instruction      = rgemu::risa::instruction;

 public:
  using HardwareType = rgemu::core::IHardwareOperations<RegType, OpCodeCell>;

 private:
  std::unique_ptr<HardwareType> hardware;

 public:
  using RegType    = BaseType::RegType;
  virtual void executeInstruction(OpCodeCell opcode);

  ~isa_impl() override = default;
  isa_impl()           = default;
};

};  // namespace rgemu::risa::interface

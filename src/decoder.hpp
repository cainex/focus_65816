#pragma once

#include <memory>
#include "register_file.hpp"
#include "memory_manager.hpp"
#include "opcodes.hpp"
#include "addressing_modes.hpp"

class Decoder
{
public:
    Decoder() = delete;
    Decoder(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile>reg) : m_mem(mem), m_reg(reg) {}
    ~Decoder() {}

    std::shared_ptr<OpCode> DecodeNext();

protected:
    std::shared_ptr<MemoryManager> m_mem;
    std::shared_ptr<RegisterFile> m_reg;
};

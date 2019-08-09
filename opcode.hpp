#pragma once

#include <cstdint>
#include <memory>
#include "memory_manager.hpp"
#include "register_file.hpp"
#include "addressing_modes.hpp"

class OpCode 
{
public:
    OpCode() = delete;
    OpCode(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : m_addrMode(addrMode), m_mem(mem), m_reg(reg) {}
    ~OpCode() {}

    virtual bool Execute() = 0;

protected:
    std::shared_ptr<MemoryManager> m_mem;
    std::shared_ptr<RegisterFile> m_reg;
    std::shared_ptr<AddressingMode> m_addrMode;

};

class ADC : public OpCode
{
public:
    ADC() = delete;
    ADC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~ADC() {}

    virtual bool Execute();

};

class LDA : public OpCode
{
public:
    LDA() = delete;
    LDA(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~LDA() {}

    virtual bool Execute();
};

class STA : public OpCode
{
public:
    STA() = delete;
    STA(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~STA() {}

    virtual bool Execute();
};
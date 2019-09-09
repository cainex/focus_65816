#pragma once

#include <cstdint>
#include <memory>
#include "memory_manager.hpp"
#include "register_file.hpp"

class AddressingMode {
public:
    AddressingMode() = delete;
    AddressingMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : m_mem(mem), m_reg(reg) {}
    ~AddressingMode() {}

    virtual uint16_t operand() = 0;
    virtual void operand(const uint16_t &op) = 0;
protected:
    std::shared_ptr<MemoryManager> m_mem;
    std::shared_ptr<RegisterFile> m_reg;

private:
};

class AbsoluteMode: public AddressingMode
{
public:
    AbsoluteMode() = delete;
    AbsoluteMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~AbsoluteMode() {}

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class ImmediateMode: public AddressingMode
{
public:
    ImmediateMode() = delete;
    ImmediateMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~ImmediateMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class ProgramCounterRelativeMode: public AddressingMode
{
public:
    ProgramCounterRelativeMode() = delete;
    ProgramCounterRelativeMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~ProgramCounterRelativeMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class AccumulatorMode: public AddressingMode
{
public:
    AccumulatorMode() = delete;
    AccumulatorMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~AccumulatorMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class ProgramCounterRelativeLongMode: public AddressingMode
{
public:
    ProgramCounterRelativeLongMode() = delete;
    ProgramCounterRelativeLongMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~ProgramCounterRelativeLongMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class ImpliedMode: public AddressingMode
{
public:
    ImpliedMode() = delete;
    ImpliedMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~ImpliedMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class StackMode: public AddressingMode
{
public:
    StackMode() = delete;
    StackMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~StackMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class DirectMode: public AddressingMode
{
public:
    DirectMode() = delete;
    DirectMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~DirectMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class DirectIndexedXMode: public AddressingMode
{
public:
    DirectIndexedXMode() = delete;
    DirectIndexedXMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~DirectIndexedXMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class DirectIndexedYMode: public AddressingMode
{
public:
    DirectIndexedYMode() = delete;
    DirectIndexedYMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~DirectIndexedYMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class DirectIndirectMode: public AddressingMode
{
public:
    DirectIndirectMode() = delete;
    DirectIndirectMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~DirectIndirectMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class DirectIndexedIndirectMode: public AddressingMode
{
public:
    DirectIndexedIndirectMode() = delete;
    DirectIndexedIndirectMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~DirectIndexedIndirectMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class DirectIndirectIndexedMode: public AddressingMode
{
public:
    DirectIndirectIndexedMode() = delete;
    DirectIndirectIndexedMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~DirectIndirectIndexedMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class DirectIndirectLongMode: public AddressingMode
{
public:
    DirectIndirectLongMode() = delete;
    DirectIndirectLongMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~DirectIndirectLongMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class DirectIndirectLongIndexedMode: public AddressingMode
{
public:
    DirectIndirectLongIndexedMode() = delete;
    DirectIndirectLongIndexedMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~DirectIndirectLongIndexedMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class AbsoluteIndexedXMode: public AddressingMode
{
public:
    AbsoluteIndexedXMode() = delete;
    AbsoluteIndexedXMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~AbsoluteIndexedXMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class AbsoluteIndexedYMode: public AddressingMode
{
public:
    AbsoluteIndexedYMode() = delete;
    AbsoluteIndexedYMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~AbsoluteIndexedYMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class AbsoluteLongMode: public AddressingMode
{
public:
    AbsoluteLongMode() = delete;
    AbsoluteLongMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~AbsoluteLongMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class AbsoluteLongIndexedMode: public AddressingMode
{
public:
    AbsoluteLongIndexedMode() = delete;
    AbsoluteLongIndexedMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~AbsoluteLongIndexedMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class StackRelativeMode: public AddressingMode
{
public:
    StackRelativeMode() = delete;
    StackRelativeMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~StackRelativeMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class StackRelativeIndirectIndexedMode: public AddressingMode
{
public:
    StackRelativeIndirectIndexedMode() = delete;
    StackRelativeIndirectIndexedMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~StackRelativeIndirectIndexedMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class AbsoluteIndirectMode: public AddressingMode
{
public:
    AbsoluteIndirectMode() = delete;
    AbsoluteIndirectMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~AbsoluteIndirectMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class AbsoluteIndexedIndirectMode: public AddressingMode
{
public:
    AbsoluteIndexedIndirectMode() = delete;
    AbsoluteIndexedIndirectMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~AbsoluteIndexedIndirectMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};

class BlockMoveMode: public AddressingMode
{
public:
    BlockMoveMode() = delete;
    BlockMoveMode(std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : AddressingMode(mem, reg) {}
    ~BlockMoveMode() {}    

    virtual uint16_t operand();
    virtual void operand(const uint16_t &op);
};




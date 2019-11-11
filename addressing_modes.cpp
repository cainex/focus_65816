#include "addressing_modes.hpp"

uint16_t AbsoluteMode::operand()
{
    uint32_t effectiveAddress;

    effectiveAddress = static_cast<uint32_t>(m_reg->dbr())<<16 | static_cast<uint32_t>(m_mem->Read<uint16_t>(m_reg->pc()));
    m_reg->pc(m_reg->pc() + 2);

    return m_mem->Read<uint16_t>(effectiveAddress);
}

uint16_t ImmediateMode::operand()
{
    uint16_t op = m_mem->Read<uint16_t>(m_reg->pc());
    m_reg->pc(m_reg->pc() + 2);

    return op;
}

uint16_t ProgramCounterRelativeMode::operand()
{
    uint8_t relByte = m_mem->Read<uint8_t>(m_reg->pc());
    m_reg->pc(m_reg->pc() + 1);

    return m_reg->pc() + static_cast<uint16_t>(relByte);
}

uint16_t AccumulatorMode::operand()
{
    return m_reg->a();
}

uint16_t ProgramCounterRelativeLongMode::operand()
{
    uint16_t relByte = m_mem->Read<uint16_t>(m_reg->pc());
    m_reg->pc(m_reg->pc() + 2);

    return m_reg->pc() + relByte;
}

uint16_t ImpliedMode::operand()
{
    return 0;
}

uint16_t StackMode::operand()
{
    return 0;
}

uint16_t DirectMode::operand()
{
    return 0;
}

uint16_t DirectIndexedWithXMode::operand()
{
    return 0;
}

uint16_t DirectIndexedWithYMode::operand()
{
    return 0;
}

uint16_t DirectIndirectMode::operand()
{
    return 0;
}

uint16_t DirectIndexedIndirectMode::operand()
{
    return 0;
}

uint16_t DirectIndirectIndexedMode::operand()
{
    return 0;
}

uint16_t DirectIndirectLongMode::operand()
{
    return 0;
}

uint16_t DirectIndirectLongIndexedMode::operand()
{
    return 0;
}

uint16_t AbsoluteIndexedWithXMode::operand()
{
    uint32_t effectiveAddress;

    effectiveAddress = static_cast<uint32_t>(m_reg->dbr())<<16 | static_cast<uint32_t>(m_mem->Read<uint16_t>(m_reg->pc()));
    effectiveAddress = static_cast<uint32_t>(m_reg->x());
    m_reg->pc(m_reg->pc() + 2);

    return m_mem->Read<uint16_t>(effectiveAddress);
}

uint16_t AbsoluteIndexedWithYMode::operand()
{
    uint32_t effectiveAddress;

    effectiveAddress = static_cast<uint32_t>(m_reg->dbr())<<16 | static_cast<uint32_t>(m_mem->Read<uint16_t>(m_reg->pc()));
    effectiveAddress = static_cast<uint32_t>(m_reg->y());
    m_reg->pc(m_reg->pc() + 2);

    return m_mem->Read<uint16_t>(effectiveAddress);
}

uint16_t AbsoluteLongMode::operand()
{
    return 0;
}

uint16_t AbsoluteLongIndexedMode::operand()
{
    return 0;
}

uint16_t StackRelativeMode::operand()
{
    return 0;
}

uint16_t StackRelativeIndirectIndexedMode::operand()
{
    return 0;
}

uint16_t AbsoluteIndirectMode::operand()
{
    return 0;
}

uint16_t AbsoluteIndexedIndirectMode::operand()
{
    uint32_t effectiveAddress;

    effectiveAddress = static_cast<uint32_t>(m_mem->Read<uint16_t>(m_reg->pc()));
    effectiveAddress += static_cast<uint32_t>(m_reg->x());
    effectiveAddress += static_cast<uint32_t>(m_reg->pbr())<<16;
    m_reg->pc(m_reg->pc() + 2);

    return effectiveAddress;
}

uint16_t BlockMoveMode::operand()
{
    return 0;
}




void AbsoluteMode::operand(const uint16_t &op)
{
    uint32_t effectiveAddress;

    effectiveAddress = static_cast<uint32_t>(m_mem->Read<uint16_t>(m_reg->pc()));
    effectiveAddress = effectiveAddress | static_cast<uint32_t>(m_reg->dbr())<<16;
    m_reg->pc(m_reg->pc() + 2);

    m_mem->Write(effectiveAddress, op);
}

void ImmediateMode::operand(const uint16_t &op)
{
}

void ProgramCounterRelativeMode::operand(const uint16_t &op)
{
}

void AccumulatorMode::operand(const uint16_t &op)
{
}

void ProgramCounterRelativeLongMode::operand(const uint16_t &op)
{
}

void ImpliedMode::operand(const uint16_t &op)
{
}

void StackMode::operand(const uint16_t &op)
{
}

void DirectMode::operand(const uint16_t &op)
{
}

void DirectIndexedWithXMode::operand(const uint16_t &op)
{
}

void DirectIndexedWithYMode::operand(const uint16_t &op)
{
}

void DirectIndirectMode::operand(const uint16_t &op)
{
}

void DirectIndexedIndirectMode::operand(const uint16_t &op)
{
}

void DirectIndirectIndexedMode::operand(const uint16_t &op)
{
}

void DirectIndirectLongMode::operand(const uint16_t &op)
{
}

void DirectIndirectLongIndexedMode::operand(const uint16_t &op)
{
}

void AbsoluteIndexedWithXMode::operand(const uint16_t &op)
{
}

void AbsoluteIndexedWithYMode::operand(const uint16_t &op)
{
}

void AbsoluteLongMode::operand(const uint16_t &op)
{
}

void AbsoluteLongIndexedMode::operand(const uint16_t &op)
{
}

void StackRelativeMode::operand(const uint16_t &op)
{
}

void StackRelativeIndirectIndexedMode::operand(const uint16_t &op)
{
}

void AbsoluteIndirectMode::operand(const uint16_t &op)
{
}

void AbsoluteIndexedIndirectMode::operand(const uint16_t &op)
{
}

void BlockMoveMode::operand(const uint16_t &op)
{
}

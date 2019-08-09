#include "opcode.hpp"

bool ADC::Execute()
{
    uint32_t m;
    uint32_t c;
    uint32_t r;

    m = static_cast<uint32_t>(m_addrMode->operand());
    c = m_reg->c() ? 1 : 0;

    r = static_cast<uint32_t>(m_reg->a()) + m + c;

    // Update status flags
    (m_reg->a() ^ r) & (m ^ r) & 0x8000 ? m_reg->setV() : m_reg->clrV();
    r & 0x10000 ? m_reg->setC() : m_reg->clrC();
    r & 0x8000 ? m_reg->setN() : m_reg->clrN();
    r == 0 ? m_reg->setZ() : m_reg->clrZ();

    // Update accumulator
    m_reg->a(static_cast<uint16_t>(r & 0xffff));

    return true;
}

bool LDA::Execute ()
{
    uint16_t r = m_addrMode->operand();
    m_reg->a(r);

    // Update status flags
    r & 0x8000 ? m_reg->setN() : m_reg->clrN();
    r == 0 ? m_reg->setZ() : m_reg->clrZ();

    return true;
}

bool STA::Execute ()
{
    m_addrMode->operand(m_reg->a());

    // No status flag updates
    
    return true;
}

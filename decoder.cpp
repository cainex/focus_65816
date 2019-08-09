#include "decoder.hpp"
#include <iostream>

std::shared_ptr<OpCode> Decoder::DecodeNext()
{
    uint8_t uop = m_mem->Read<uint8_t>(m_reg->pc_addr());

    if (uop == 0x6d) { // ADC Absolute
        std::cout << "ADC" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteAddressingMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    else if (uop == 0xa9) {
        std::cout << "LDA" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    else if (uop == 0x8d) {
        std::cout << "STA" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteAddressingMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    else {
        std::cout << "UNKNOW UOP : " << std::hex << static_cast<uint32_t>(uop) << std::dec << std::endl;
        exit(1);
    }

}
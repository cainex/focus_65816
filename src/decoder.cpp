
#include "decoder.hpp"
#include <iostream>

std::shared_ptr<OpCode> Decoder::DecodeNext()
{
    uint8_t uop = m_mem->Read<uint8_t>(m_reg->pc_addr());


    if (uop == 0x00 ) { // BRK Stack
        std::cout << "BRK s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BRK(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x01 ) { // ORA DirectIndexedIndirect
        std::cout << "ORA (d,x)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x02 ) { // COP Stack
        std::cout << "COP s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new COP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x03 ) { // ORA StackRelative
        std::cout << "ORA d,s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x04 ) { // TSB Direct
        std::cout << "TSB d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TSB(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x05 ) { // ORA Direct
        std::cout << "ORA d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x06 ) { // ASL Direct
        std::cout << "ASL d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ASL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x07 ) { // ORA DirectIndirectLong
        std::cout << "ORA [d]" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x08 ) { // PHP Stack
        std::cout << "PHP s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PHP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x09 ) { // ORA Immediate
        std::cout << "ORA #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x0a ) { // ASL Accumulator
        std::cout << "ASL A" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AccumulatorMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ASL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x0b ) { // PHD Stack
        std::cout << "PHD s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PHD(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x0c ) { // TSB Absolute
        std::cout << "TSB a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TSB(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x0d ) { // ORA Absolute
        std::cout << "ORA a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x0e ) { // ASL Absolute
        std::cout << "ASL a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ASL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x0f ) { // ORA AbsoluteLong
        std::cout << "ORA al" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x10 ) { // BPL ProgramCounterRelative
        std::cout << "BPL r" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ProgramCounterRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BPL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x11 ) { // ORA DirectIndirectIndexed
        std::cout << "ORA (d),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x12 ) { // ORA DirectIndirect
        std::cout << "ORA (d)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x13 ) { // ORA StackRelativeIndirectIndexed
        std::cout << "ORA (d,s),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x14 ) { // TRB Direct
        std::cout << "TRB d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TRB(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x15 ) { // ORA DirectIndexedWithX
        std::cout << "ORA d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x16 ) { // ASL DirectIndexedWithX
        std::cout << "ASL d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ASL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x17 ) { // ORA DirectIndirectLongIndexed
        std::cout << "ORA [d],y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x18 ) { // CLC Implied
        std::cout << "CLC i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CLC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x19 ) { // ORA AbsoluteIndexedWithY
        std::cout << "ORA a,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x1a ) { // INC Accumulator
        std::cout << "INC A" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AccumulatorMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new INC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x1b ) { // TCS Implied
        std::cout << "TCS i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TCS(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x1c ) { // TRB Absolute
        std::cout << "TRB a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TRB(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x1d ) { // ORA AbsoluteIndexedWithX
        std::cout << "ORA a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x1e ) { // ASL AbsoluteIndexedWithX
        std::cout << "ASL a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ASL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x1f ) { // ORA AbsoluteLongIndexed
        std::cout << "ORA al,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ORA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x20 ) { // JSR Absolute
        std::cout << "JSR a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new JSR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x21 ) { // AND DirectIndexedIndirect
        std::cout << "AND (d,x)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x22 ) { // JSL AbsoluteLong
        std::cout << "JSL al" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new JSL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x23 ) { // AND StackRelative
        std::cout << "AND d,s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x24 ) { // BIT Direct
        std::cout << "BIT d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BIT(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x25 ) { // AND Direct
        std::cout << "AND d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x26 ) { // ROL Direct
        std::cout << "ROL d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ROL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x27 ) { // AND DirectIndirectLong
        std::cout << "AND [d]" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x28 ) { // PLP Stack
        std::cout << "PLP s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PLP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x29 ) { // AND Immediate
        std::cout << "AND #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x2a ) { // ROL Accumulator
        std::cout << "ROL A" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AccumulatorMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ROL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x2b ) { // PLD Stack
        std::cout << "PLD s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PLD(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x2c ) { // BIT Absolute
        std::cout << "BIT a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BIT(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x2d ) { // AND Absolute
        std::cout << "AND a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x2e ) { // ROL Absolute
        std::cout << "ROL a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ROL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x2f ) { // AND AbsoluteLong
        std::cout << "AND al" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x30 ) { // BMI ProgramCounterRelative
        std::cout << "BMI r" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ProgramCounterRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BMI(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x31 ) { // AND DirectIndirectIndexed
        std::cout << "AND (d),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x32 ) { // AND DirectIndirect
        std::cout << "AND (d)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x33 ) { // AND StackRelativeIndirectIndexed
        std::cout << "AND (d,s),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x34 ) { // BIT DirectIndexedWithX
        std::cout << "BIT d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BIT(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x35 ) { // AND DirectIndexedWithX
        std::cout << "AND d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x36 ) { // ROL DirectIndexedWithX
        std::cout << "ROL d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ROL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x37 ) { // AND DirectIndirectLongIndexed
        std::cout << "AND [d],y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x38 ) { // SEC Implied
        std::cout << "SEC i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SEC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x39 ) { // AND AbsoluteIndexedWithY
        std::cout << "AND a,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x3a ) { // DEC Accumulator
        std::cout << "DEC A" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AccumulatorMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new DEC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x3b ) { // TSC Implied
        std::cout << "TSC i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TSC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x3c ) { // BIT AbsoluteIndexedWithX
        std::cout << "BIT a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BIT(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x3d ) { // AND AbsoluteIndexedWithX
        std::cout << "AND a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x3e ) { // ROL AbsoluteIndexedWithX
        std::cout << "ROL a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ROL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x3f ) { // AND AbsoluteLongIndexed
        std::cout << "AND al,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new AND(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x40 ) { // RTI Stack
        std::cout << "RTI s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new RTI(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x41 ) { // EOR DirectIndexedIndirect
        std::cout << "EOR (d,x)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x42 ) { // WDM Implied
        std::cout << "WDM i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new WDM(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x43 ) { // EOR StackRelative
        std::cout << "EOR d,s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x44 ) { // MVP BlockMove
        std::cout << "MVP xyc" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new BlockMoveMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new MVP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x45 ) { // EOR Direct
        std::cout << "EOR d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x46 ) { // LSR Direct
        std::cout << "LSR d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LSR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x47 ) { // EOR DirectIndirectLong
        std::cout << "EOR [d]" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x48 ) { // PHA Stack
        std::cout << "PHA s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PHA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x49 ) { // EOR Immediate
        std::cout << "EOR #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x4a ) { // LSR Accumulator
        std::cout << "LSR A" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AccumulatorMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LSR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x4b ) { // PHK Stack
        std::cout << "PHK s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PHK(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x4c ) { // JMP Absolute
        std::cout << "JMP a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new JMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x4d ) { // EOR Absolute
        std::cout << "EOR a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x4e ) { // LSR Absolute
        std::cout << "LSR a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LSR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x4f ) { // EOR AbsoluteLong
        std::cout << "EOR al" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x50 ) { // BVC ProgramCounterRelative
        std::cout << "BVC r" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ProgramCounterRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BVC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x51 ) { // EOR DirectIndirectIndexed
        std::cout << "EOR (d),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x52 ) { // EOR DirectIndirect
        std::cout << "EOR (d)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x53 ) { // EOR StackRelativeIndirectIndexed
        std::cout << "EOR (d,s),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x54 ) { // MVN BlockMove
        std::cout << "MVN xyc" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new BlockMoveMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new MVN(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x55 ) { // EOR DirectIndexedWithX
        std::cout << "EOR d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x56 ) { // LSR DirectIndexedWithX
        std::cout << "LSR d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LSR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x57 ) { // EOR DirectIndirectLongIndexed
        std::cout << "EOR [d],y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x58 ) { // CLI Implied
        std::cout << "CLI i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CLI(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x59 ) { // EOR AbsoluteIndexedWithY
        std::cout << "EOR a,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x5a ) { // PHY Stack
        std::cout << "PHY s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PHY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x5b ) { // TCD Implied
        std::cout << "TCD i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TCD(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x5c ) { // JMP AbsoluteLong
        std::cout << "JMP al" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new JMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x5d ) { // EOR AbsoluteIndexedWithX
        std::cout << "EOR a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x5e ) { // LSR AbsoluteIndexedWithX
        std::cout << "LSR a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LSR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x5f ) { // EOR AbsoluteLongIndexed
        std::cout << "EOR al,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new EOR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x60 ) { // RTS Stack
        std::cout << "RTS s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new RTS(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x61 ) { // ADC DirectIndexedIndirect
        std::cout << "ADC (d,x)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x62 ) { // PER Stack
        std::cout << "PER s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PER(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x63 ) { // ADC StackRelative
        std::cout << "ADC d,s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x64 ) { // STZ Direct
        std::cout << "STZ d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STZ(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x65 ) { // ADC DirectIndexedWithX
        std::cout << "ADC d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x66 ) { // ROR DirectIndexedWithX
        std::cout << "ROR d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ROR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x67 ) { // ADC DirectIndirectLong
        std::cout << "ADC [d]" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x68 ) { // PLA Stack
        std::cout << "PLA s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PLA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x69 ) { // ADC Immediate
        std::cout << "ADC #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x6a ) { // ROR Accumulator
        std::cout << "ROR A" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AccumulatorMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ROR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x6b ) { // RTL Stack
        std::cout << "RTL s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new RTL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x6c ) { // JMP AbsoluteIndirect
        std::cout << "JMP (a)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new JMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x6d ) { // ADC Absolute
        std::cout << "ADC a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x6e ) { // ROR Absolute
        std::cout << "ROR a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ROR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x6f ) { // ADC AbsoluteLong
        std::cout << "ADC al" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x70 ) { // BVS ProgramCounterRelative
        std::cout << "BVS r" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ProgramCounterRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BVS(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x71 ) { // ADC DirectIndirectIndexed
        std::cout << "ADC (d),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x72 ) { // ADC DirectIndirect
        std::cout << "ADC (d)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x73 ) { // ADC StackRelativeIndirectIndexed
        std::cout << "ADC (d,s),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x74 ) { // STZ DirectIndexedWithX
        std::cout << "STZ d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STZ(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x75 ) { // ADC DirectIndexedWithX
        std::cout << "ADC d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x76 ) { // ROR DirectIndexedWithX
        std::cout << "ROR d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ROR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x77 ) { // ADC DirectIndirectLongIndexed
        std::cout << "ADC [d],y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x78 ) { // SEI Implied
        std::cout << "SEI i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SEI(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x79 ) { // ADC AbsoluteIndexedWithY
        std::cout << "ADC a,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x7a ) { // PLY Stack
        std::cout << "PLY s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PLY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x7b ) { // TDC Implied
        std::cout << "TDC i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TDC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x7c ) { // JMP AbsoluteIndexedIndirect
        std::cout << "JMP (a,x)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new JMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x7d ) { // ADC AbsoluteIndexedWithX
        std::cout << "ADC a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x7e ) { // ROR AbsoluteIndexedWithX
        std::cout << "ROR a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ROR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x7f ) { // ADC AbsoluteLongIndexed
        std::cout << "ADC al,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new ADC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x80 ) { // BRA ProgramCounterRelative
        std::cout << "BRA r" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ProgramCounterRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BRA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x81 ) { // STA DirectIndexedIndirect
        std::cout << "STA (d,x)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x82 ) { // BRL ProgramCounterRelativeLong
        std::cout << "BRL rl" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ProgramCounterRelativeLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BRL(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x83 ) { // STA StackRelative
        std::cout << "STA d,s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x84 ) { // STY Direct
        std::cout << "STY d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x85 ) { // STA Direct
        std::cout << "STA d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x86 ) { // STX Direct
        std::cout << "STX d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x87 ) { // STA DirectIndirectLong
        std::cout << "STA [d]" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x88 ) { // DEY Implied
        std::cout << "DEY i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new DEY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x89 ) { // BIT Immediate
        std::cout << "BIT #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BIT(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x8a ) { // TXA Implied
        std::cout << "TXA i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TXA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x8b ) { // PHB Stack
        std::cout << "PHB s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PHB(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x8c ) { // STY Absolute
        std::cout << "STY a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x8d ) { // STA Absolute
        std::cout << "STA a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x8e ) { // STX Absolute
        std::cout << "STX a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x8f ) { // STA AbsoluteLong
        std::cout << "STA al" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x90 ) { // BCC ProgramCounterRelative
        std::cout << "BCC r" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ProgramCounterRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BCC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x91 ) { // STA DirectIndirectIndexed
        std::cout << "STA (d),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x92 ) { // STA DirectIndirect
        std::cout << "STA (d)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x93 ) { // STA StackRelativeIndirectIndexed
        std::cout << "STA (d,s),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x94 ) { // STY DirectIndexedWithX
        std::cout << "STY d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x95 ) { // STA DirectIndexedWithX
        std::cout << "STA d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x96 ) { // STX DirectIndexedWithY
        std::cout << "STX d,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x97 ) { // STA DirectIndirectLongIndexed
        std::cout << "STA [d],y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x98 ) { // TYA Implied
        std::cout << "TYA i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TYA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x99 ) { // STA AbsoluteIndexedWithY
        std::cout << "STA a,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x9a ) { // TXS Implied
        std::cout << "TXS i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TXS(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x9b ) { // TXY Implied
        std::cout << "TXY i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TXY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x9c ) { // STZ Absolute
        std::cout << "STZ a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STZ(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x9d ) { // STA AbsoluteIndexedWithX
        std::cout << "STA a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x9e ) { // STZ AbsoluteIndexedWithX
        std::cout << "STZ a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STZ(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0x9f ) { // STA AbsoluteLongIndexed
        std::cout << "STA al,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xa0 ) { // LDY Immediate
        std::cout << "LDY #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xa1 ) { // LDA DirectIndexedIndirect
        std::cout << "LDA (d,x)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xa2 ) { // LDX Immediate
        std::cout << "LDX #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xa3 ) { // LDA StackRelative
        std::cout << "LDA d,s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xa4 ) { // LDY Direct
        std::cout << "LDY d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xa5 ) { // LDA Direct
        std::cout << "LDA d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xa6 ) { // LDX Direct
        std::cout << "LDX d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xa7 ) { // LDA DirectIndirectLong
        std::cout << "LDA [d]" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xa8 ) { // TAY Implied
        std::cout << "TAY i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TAY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xa9 ) { // LDA Immediate
        std::cout << "LDA #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xaa ) { // TAX Implied
        std::cout << "TAX i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TAX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xab ) { // PLB Stack
        std::cout << "PLB s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PLB(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xac ) { // LDY Absolute
        std::cout << "LDY a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xad ) { // LDA Absolute
        std::cout << "LDA a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xae ) { // LDX Absolute
        std::cout << "LDX a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xaf ) { // LDA AbsoluteLong
        std::cout << "LDA al" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xb0 ) { // BCS ProgramCounterRelative
        std::cout << "BCS r" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ProgramCounterRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BCS(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xb1 ) { // LDA DirectIndirectIndexed
        std::cout << "LDA (d),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xb2 ) { // LDA DirectIndirect
        std::cout << "LDA (d)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xb3 ) { // LDA StackRelativeIndirectIndexed
        std::cout << "LDA (d,s),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xb4 ) { // LDY DirectIndexedWithX
        std::cout << "LDY d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xb5 ) { // LDA DirectIndexedWithX
        std::cout << "LDA d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xb6 ) { // LDX DirectIndexedWithY
        std::cout << "LDX d,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xb7 ) { // LDA DirectIndirectLongIndexed
        std::cout << "LDA [d],y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xb8 ) { // CLV Implied
        std::cout << "CLV i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CLV(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xb9 ) { // LDA AbsoluteIndexedWithY
        std::cout << "LDA a,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xba ) { // TSX Implied
        std::cout << "TSX i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TSX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xbb ) { // TYX Implied
        std::cout << "TYX i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new TYX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xbc ) { // LDY AbsoluteIndexedWithX
        std::cout << "LDY a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xbd ) { // LDA AbsoluteIndexedWithX
        std::cout << "LDA a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xbe ) { // LDX AbsoluteIndexedWithY
        std::cout << "LDX a,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xbf ) { // LDA AbsoluteLongIndexed
        std::cout << "LDA al,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new LDA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xc0 ) { // CPY Immediate
        std::cout << "CPY #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CPY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xc1 ) { // CMP DirectIndexedIndirect
        std::cout << "CMP (d,x)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xc2 ) { // REP Immediate
        std::cout << "REP #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new REP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xc3 ) { // CMP StackRelative
        std::cout << "CMP d,s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xc4 ) { // CPY Direct
        std::cout << "CPY d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CPY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xc5 ) { // CMP Direct
        std::cout << "CMP d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xc6 ) { // DEC Direct
        std::cout << "DEC d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new DEC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xc7 ) { // CMP DirectIndirectLong
        std::cout << "CMP [d]" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xc8 ) { // INY Implied
        std::cout << "INY i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new INY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xc9 ) { // CMP Immediate
        std::cout << "CMP #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xca ) { // DEX Implied
        std::cout << "DEX i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new DEX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xcb ) { // WAI Implied
        std::cout << "WAI i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new WAI(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xcc ) { // CPY Absolute
        std::cout << "CPY a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CPY(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xcd ) { // CMP Absolute
        std::cout << "CMP a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xce ) { // DEC Absolute
        std::cout << "DEC a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new DEC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xcf ) { // CMP AbsoluteLong
        std::cout << "CMP al" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xd0 ) { // BNE ProgramCounterRelative
        std::cout << "BNE r" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ProgramCounterRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BNE(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xd1 ) { // CMP DirectIndirectIndexed
        std::cout << "CMP (d),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xd2 ) { // CMP DirectIndirect
        std::cout << "CMP (d)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xd3 ) { // CMP StackRelativeIndirectIndexed
        std::cout << "CMP (d,s),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xd4 ) { // PEI Stack
        std::cout << "PEI s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PEI(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xd5 ) { // CMP DirectIndexedWithX
        std::cout << "CMP d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xd6 ) { // DEC DirectIndexedWithX
        std::cout << "DEC d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new DEC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xd7 ) { // CMP DirectIndirectLongIndexed
        std::cout << "CMP [d],y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xd8 ) { // CLD Implied
        std::cout << "CLD i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CLD(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xd9 ) { // CMP AbsoluteIndexedWithY
        std::cout << "CMP a,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xda ) { // PHX Stack
        std::cout << "PHX s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PHX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xdb ) { // STP Implied
        std::cout << "STP i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new STP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xdc ) { // JML AbsoluteIndirect
        std::cout << "JML (a)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new JML(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xdd ) { // CMP AbsoluteIndexedWithX
        std::cout << "CMP a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xde ) { // DEC AbsoluteIndexedWithX
        std::cout << "DEC a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new DEC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xdf ) { // CMP AbsoluteLongIndexed
        std::cout << "CMP al,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CMP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xe0 ) { // CPX Immediate
        std::cout << "CPX #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CPX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xe1 ) { // SBC DirectIndexedIndirect
        std::cout << "SBC (d,x)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xe2 ) { // SEP Immediate
        std::cout << "SEP #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SEP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xe3 ) { // SBC StackRelative
        std::cout << "SBC d,s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xe4 ) { // CPX Direct
        std::cout << "CPX d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CPX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xe5 ) { // SBC Direct
        std::cout << "SBC d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xe6 ) { // INC Direct
        std::cout << "INC d" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new INC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xe7 ) { // SBC DirectIndirectLong
        std::cout << "SBC [d]" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xe8 ) { // INX Implied
        std::cout << "INX i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new INX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xe9 ) { // SBC Immediate
        std::cout << "SBC #" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImmediateMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xea ) { // NOP Implied
        std::cout << "NOP i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new NOP(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xeb ) { // XBA Implied
        std::cout << "XBA i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new XBA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xec ) { // CPX Absolute
        std::cout << "CPX a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new CPX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xed ) { // SBC Absolute
        std::cout << "SBC a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xee ) { // INC Absolute
        std::cout << "INC a" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new INC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xef ) { // SBC AbsoluteLong
        std::cout << "SBC al" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xf0 ) { // BEQ ProgramCounterRelative
        std::cout << "BEQ r" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ProgramCounterRelativeMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new BEQ(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xf1 ) { // SBC DirectIndirectIndexed
        std::cout << "SBC (d),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xf2 ) { // SBC DirectIndirect
        std::cout << "SBC (d)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xf3 ) { // SBC StackRelativeIndirectIndexed
        std::cout << "SBC (d,s),y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackRelativeIndirectIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xf4 ) { // PEA Stack
        std::cout << "PEA s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PEA(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xf5 ) { // SBC DirectIndexedWithX
        std::cout << "SBC d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xf6 ) { // INC DirectIndexedWithX
        std::cout << "INC d,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new INC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xf7 ) { // SBC DirectIndirectLongIndexed
        std::cout << "SBC [d],y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new DirectIndirectLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xf8 ) { // SED Implied
        std::cout << "SED i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SED(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xf9 ) { // SBC AbsoluteIndexedWithY
        std::cout << "SBC a,y" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithYMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xfa ) { // PLX Stack
        std::cout << "PLX s" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new StackMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new PLX(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xfb ) { // XCE Implied
        std::cout << "XCE i" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new ImpliedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new XCE(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xfc ) { // JSR AbsoluteIndexedIndirect
        std::cout << "JSR (a,x)" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedIndirectMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new JSR(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xfd ) { // SBC AbsoluteIndexedWithX
        std::cout << "SBC a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xfe ) { // INC AbsoluteIndexedWithX
        std::cout << "INC a,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteIndexedWithXMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new INC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    if (uop == 0xff ) { // SBC AbsoluteLongIndexed
        std::cout << "SBC al,x" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new AbsoluteLongIndexedMode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new SBC(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
    std::cout << "UNKNOW UOP : " << std::hex << static_cast<uint32_t>(uop) << std::dec << std::endl;
    exit(1);

}
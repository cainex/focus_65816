
#pragma once

#include <cstdint>
#include <memory>
#include <assert.h>
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

    bool get_c(uint32_t r) { return r & 0x10000; }
    bool get_n(uint32_t r) { return r & 0x8000; }
    bool get_z(uint32_t r) { return r == 0; }
};


class ADC : public OpCode
{
public:
    ADC() = delete;
    ADC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~ADC() {}

    virtual bool Execute();
};

class AND : public OpCode
{
public:
    AND() = delete;
    AND(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~AND() {}

    virtual bool Execute();
};

class ASL : public OpCode
{
public:
    ASL() = delete;
    ASL(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~ASL() {}

    virtual bool Execute();
};

class BCC : public OpCode
{
public:
    BCC() = delete;
    BCC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BCC() {}

    virtual bool Execute();
};

class BCS : public OpCode
{
public:
    BCS() = delete;
    BCS(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BCS() {}

    virtual bool Execute();
};

class BEQ : public OpCode
{
public:
    BEQ() = delete;
    BEQ(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BEQ() {}

    virtual bool Execute();
};

class BIT : public OpCode
{
public:
    BIT() = delete;
    BIT(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BIT() {}

    virtual bool Execute();
};

class BMI : public OpCode
{
public:
    BMI() = delete;
    BMI(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BMI() {}

    virtual bool Execute();
};

class BNE : public OpCode
{
public:
    BNE() = delete;
    BNE(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BNE() {}

    virtual bool Execute();
};

class BPL : public OpCode
{
public:
    BPL() = delete;
    BPL(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BPL() {}

    virtual bool Execute();
};

class BRA : public OpCode
{
public:
    BRA() = delete;
    BRA(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BRA() {}

    virtual bool Execute();
};

class BRK : public OpCode
{
public:
    BRK() = delete;
    BRK(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BRK() {}

    virtual bool Execute();
};

class BRL : public OpCode
{
public:
    BRL() = delete;
    BRL(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BRL() {}

    virtual bool Execute();
};

class BVC : public OpCode
{
public:
    BVC() = delete;
    BVC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BVC() {}

    virtual bool Execute();
};

class BVS : public OpCode
{
public:
    BVS() = delete;
    BVS(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~BVS() {}

    virtual bool Execute();
};

class CLC : public OpCode
{
public:
    CLC() = delete;
    CLC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~CLC() {}

    virtual bool Execute();
};

class CLD : public OpCode
{
public:
    CLD() = delete;
    CLD(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~CLD() {}

    virtual bool Execute();
};

class CLI : public OpCode
{
public:
    CLI() = delete;
    CLI(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~CLI() {}

    virtual bool Execute();
};

class CLV : public OpCode
{
public:
    CLV() = delete;
    CLV(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~CLV() {}

    virtual bool Execute();
};

class CMP : public OpCode
{
public:
    CMP() = delete;
    CMP(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~CMP() {}

    virtual bool Execute();
};

class COP : public OpCode
{
public:
    COP() = delete;
    COP(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~COP() {}

    virtual bool Execute();
};

class CPX : public OpCode
{
public:
    CPX() = delete;
    CPX(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~CPX() {}

    virtual bool Execute();
};

class CPY : public OpCode
{
public:
    CPY() = delete;
    CPY(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~CPY() {}

    virtual bool Execute();
};

class DEC : public OpCode
{
public:
    DEC() = delete;
    DEC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~DEC() {}

    virtual bool Execute();
};

class DEX : public OpCode
{
public:
    DEX() = delete;
    DEX(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~DEX() {}

    virtual bool Execute();
};

class DEY : public OpCode
{
public:
    DEY() = delete;
    DEY(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~DEY() {}

    virtual bool Execute();
};

class EOR : public OpCode
{
public:
    EOR() = delete;
    EOR(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~EOR() {}

    virtual bool Execute();
};

class INC : public OpCode
{
public:
    INC() = delete;
    INC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~INC() {}

    virtual bool Execute();
};

class INX : public OpCode
{
public:
    INX() = delete;
    INX(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~INX() {}

    virtual bool Execute();
};

class INY : public OpCode
{
public:
    INY() = delete;
    INY(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~INY() {}

    virtual bool Execute();
};

class JML : public OpCode
{
public:
    JML() = delete;
    JML(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~JML() {}

    virtual bool Execute();
};

class JMP : public OpCode
{
public:
    JMP() = delete;
    JMP(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~JMP() {}

    virtual bool Execute();
};

class JSL : public OpCode
{
public:
    JSL() = delete;
    JSL(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~JSL() {}

    virtual bool Execute();
};

class JSR : public OpCode
{
public:
    JSR() = delete;
    JSR(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~JSR() {}

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

class LDX : public OpCode
{
public:
    LDX() = delete;
    LDX(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~LDX() {}

    virtual bool Execute();
};

class LDY : public OpCode
{
public:
    LDY() = delete;
    LDY(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~LDY() {}

    virtual bool Execute();
};

class LSR : public OpCode
{
public:
    LSR() = delete;
    LSR(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~LSR() {}

    virtual bool Execute();
};

class MVN : public OpCode
{
public:
    MVN() = delete;
    MVN(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~MVN() {}

    virtual bool Execute();
};

class MVP : public OpCode
{
public:
    MVP() = delete;
    MVP(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~MVP() {}

    virtual bool Execute();
};

class NOP : public OpCode
{
public:
    NOP() = delete;
    NOP(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~NOP() {}

    virtual bool Execute();
};

class ORA : public OpCode
{
public:
    ORA() = delete;
    ORA(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~ORA() {}

    virtual bool Execute();
};

class PEA : public OpCode
{
public:
    PEA() = delete;
    PEA(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PEA() {}

    virtual bool Execute();
};

class PEI : public OpCode
{
public:
    PEI() = delete;
    PEI(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PEI() {}

    virtual bool Execute();
};

class PER : public OpCode
{
public:
    PER() = delete;
    PER(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PER() {}

    virtual bool Execute();
};

class PHA : public OpCode
{
public:
    PHA() = delete;
    PHA(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PHA() {}

    virtual bool Execute();
};

class PHB : public OpCode
{
public:
    PHB() = delete;
    PHB(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PHB() {}

    virtual bool Execute();
};

class PHD : public OpCode
{
public:
    PHD() = delete;
    PHD(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PHD() {}

    virtual bool Execute();
};

class PHK : public OpCode
{
public:
    PHK() = delete;
    PHK(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PHK() {}

    virtual bool Execute();
};

class PHP : public OpCode
{
public:
    PHP() = delete;
    PHP(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PHP() {}

    virtual bool Execute();
};

class PHX : public OpCode
{
public:
    PHX() = delete;
    PHX(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PHX() {}

    virtual bool Execute();
};

class PHY : public OpCode
{
public:
    PHY() = delete;
    PHY(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PHY() {}

    virtual bool Execute();
};

class PLA : public OpCode
{
public:
    PLA() = delete;
    PLA(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PLA() {}

    virtual bool Execute();
};

class PLB : public OpCode
{
public:
    PLB() = delete;
    PLB(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PLB() {}

    virtual bool Execute();
};

class PLD : public OpCode
{
public:
    PLD() = delete;
    PLD(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PLD() {}

    virtual bool Execute();
};

class PLP : public OpCode
{
public:
    PLP() = delete;
    PLP(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PLP() {}

    virtual bool Execute();
};

class PLX : public OpCode
{
public:
    PLX() = delete;
    PLX(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PLX() {}

    virtual bool Execute();
};

class PLY : public OpCode
{
public:
    PLY() = delete;
    PLY(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~PLY() {}

    virtual bool Execute();
};

class REP : public OpCode
{
public:
    REP() = delete;
    REP(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~REP() {}

    virtual bool Execute();
};

class ROL : public OpCode
{
public:
    ROL() = delete;
    ROL(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~ROL() {}

    virtual bool Execute();
};

class ROR : public OpCode
{
public:
    ROR() = delete;
    ROR(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~ROR() {}

    virtual bool Execute();
};

class RTI : public OpCode
{
public:
    RTI() = delete;
    RTI(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~RTI() {}

    virtual bool Execute();
};

class RTL : public OpCode
{
public:
    RTL() = delete;
    RTL(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~RTL() {}

    virtual bool Execute();
};

class RTS : public OpCode
{
public:
    RTS() = delete;
    RTS(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~RTS() {}

    virtual bool Execute();
};

class SBC : public OpCode
{
public:
    SBC() = delete;
    SBC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~SBC() {}

    virtual bool Execute();
};

class SEC : public OpCode
{
public:
    SEC() = delete;
    SEC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~SEC() {}

    virtual bool Execute();
};

class SED : public OpCode
{
public:
    SED() = delete;
    SED(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~SED() {}

    virtual bool Execute();
};

class SEI : public OpCode
{
public:
    SEI() = delete;
    SEI(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~SEI() {}

    virtual bool Execute();
};

class SEP : public OpCode
{
public:
    SEP() = delete;
    SEP(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~SEP() {}

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

class STP : public OpCode
{
public:
    STP() = delete;
    STP(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~STP() {}

    virtual bool Execute();
};

class STX : public OpCode
{
public:
    STX() = delete;
    STX(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~STX() {}

    virtual bool Execute();
};

class STY : public OpCode
{
public:
    STY() = delete;
    STY(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~STY() {}

    virtual bool Execute();
};

class STZ : public OpCode
{
public:
    STZ() = delete;
    STZ(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~STZ() {}

    virtual bool Execute();
};

class TAX : public OpCode
{
public:
    TAX() = delete;
    TAX(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TAX() {}

    virtual bool Execute();
};

class TAY : public OpCode
{
public:
    TAY() = delete;
    TAY(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TAY() {}

    virtual bool Execute();
};

class TCD : public OpCode
{
public:
    TCD() = delete;
    TCD(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TCD() {}

    virtual bool Execute();
};

class TCS : public OpCode
{
public:
    TCS() = delete;
    TCS(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TCS() {}

    virtual bool Execute();
};

class TDC : public OpCode
{
public:
    TDC() = delete;
    TDC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TDC() {}

    virtual bool Execute();
};

class TRB : public OpCode
{
public:
    TRB() = delete;
    TRB(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TRB() {}

    virtual bool Execute();
};

class TSB : public OpCode
{
public:
    TSB() = delete;
    TSB(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TSB() {}

    virtual bool Execute();
};

class TSC : public OpCode
{
public:
    TSC() = delete;
    TSC(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TSC() {}

    virtual bool Execute();
};

class TSX : public OpCode
{
public:
    TSX() = delete;
    TSX(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TSX() {}

    virtual bool Execute();
};

class TXA : public OpCode
{
public:
    TXA() = delete;
    TXA(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TXA() {}

    virtual bool Execute();
};

class TXS : public OpCode
{
public:
    TXS() = delete;
    TXS(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TXS() {}

    virtual bool Execute();
};

class TXY : public OpCode
{
public:
    TXY() = delete;
    TXY(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TXY() {}

    virtual bool Execute();
};

class TYA : public OpCode
{
public:
    TYA() = delete;
    TYA(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TYA() {}

    virtual bool Execute();
};

class TYX : public OpCode
{
public:
    TYX() = delete;
    TYX(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~TYX() {}

    virtual bool Execute();
};

class WAI : public OpCode
{
public:
    WAI() = delete;
    WAI(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~WAI() {}

    virtual bool Execute();
};

class WDM : public OpCode
{
public:
    WDM() = delete;
    WDM(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~WDM() {}

    virtual bool Execute();
};

class XBA : public OpCode
{
public:
    XBA() = delete;
    XBA(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~XBA() {}

    virtual bool Execute();
};

class XCE : public OpCode
{
public:
    XCE() = delete;
    XCE(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~XCE() {}

    virtual bool Execute();
};


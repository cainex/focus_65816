
#include "opcodes.hpp"


bool ADC::Execute()
{
    
        uint32_t a = static_cast<uint32_t>(m_reg->a());
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t c = m_reg->c() ? 1 : 0;
        uint32_t r;

        r = a + o + c;

        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->v((a ^ r) & (o ^ r) & 0x8000);
        m_reg->c(get_c(r));
        return true;

}

bool AND::Execute()
{
    
        uint32_t a = static_cast<uint32_t>(m_reg->a());
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = a & o;

        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool ASL::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = o << 1;

        m_addrMode->operand(r);
        m_reg->c(get_c(r));
        return true;

}

bool BCC::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t c = m_reg->c() ? 1 : 0;
        uint32_t pc = m_reg->pc();
        uint32_t r;

        if (c == 0) r = pc + o; else r = pc;

        m_reg->pc(r);
        return true;

}

bool BCS::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t c = m_reg->c() ? 1 : 0;
        uint32_t pc = m_reg->pc();
        uint32_t r;

        if (c == 1) r = pc + o; else r = pc;

        m_reg->pc(r);
        return true;

}

bool BEQ::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t z = m_reg->z() ? 1 : 0;
        uint32_t pc = m_reg->pc();
        uint32_t r;

        if (z == 1) r = pc + o; else r = pc;

        m_reg->pc(r);
        return true;

}

bool BIT::Execute()
{
    
        uint32_t a = static_cast<uint32_t>(m_reg->a());
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = a & o;

        m_reg->z(get_z(r));
        m_reg->n(m_reg->m() ? (r>>7)&0x1 : (r>>15)&0x1);
        m_reg->v(m_reg->m() ? (r>>6)&0x1 : (r>>14)&0x1);
        return true;

}

bool BMI::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t n = m_reg->n() ? 1 : 0;
        uint32_t pc = m_reg->pc();
        uint32_t r;

        if (n == 1) r = pc + o; else r = pc;

        m_reg->pc(r);
        return true;

}

bool BNE::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t z = m_reg->z() ? 1 : 0;
        uint32_t pc = m_reg->pc();
        uint32_t r;

        if (z == 0) r = pc + o; else r = pc;

        m_reg->pc(r);
        return true;

}

bool BPL::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t n = m_reg->n() ? 1 : 0;
        uint32_t pc = m_reg->pc();
        uint32_t r;

        if (n == 0) r = pc + 0; else r = pc;

        m_reg->pc(r);
        return true;

}

bool BRA::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t pc = m_reg->pc();
        uint32_t r;

        r = pc + o;

        m_reg->pc(r);
        return true;

}

bool BRK::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        assert(0);

        return true;

}

bool BRL::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t pc = m_reg->pc();
        uint32_t r;

        r = pc + o;

        m_reg->pc(r);
        return true;

}

bool BVC::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t v = m_reg->v() ? 1 : 0;
        uint32_t pc = m_reg->pc();
        uint32_t r;

        if (v == 0) r = pc + o; else r = pc;

        m_reg->pc(r);
        return true;

}

bool BVS::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t v = m_reg->v() ? 1 : 0;
        uint32_t pc = m_reg->pc();
        uint32_t r;

        if (v == 1) r = pc + o; else r = pc;

        m_reg->pc(r);
        return true;

}

bool CLC::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t c = m_reg->c() ? 1 : 0;
        uint32_t r;

        r = 0;

        m_reg->c(r);
        return true;

}

bool CLD::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = 0;

        m_reg->d(r);
        return true;

}

bool CLI::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = 0;

        m_reg->i(r);
        return true;

}

bool CLV::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t v = m_reg->v() ? 1 : 0;
        uint32_t r;

        r = 0;

        m_reg->v(r);
        return true;

}

bool CMP::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t a = static_cast<uint32_t>(m_reg->a());
        uint32_t r;

        r = a - o;

        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        m_reg->c(get_c(r));
        return true;

}

bool COP::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        assert(0);

        return true;

}

bool CPX::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t x = static_cast<uint32_t>(m_reg->x());
        uint32_t r;

        r = x - o;

        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        m_reg->c(get_c(r));
        return true;

}

bool CPY::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t y = static_cast<uint32_t>(m_reg->y());
        uint32_t r;

        r = y - o;

        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        m_reg->c(get_c(r));
        return true;

}

bool DEC::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = o - 1;

        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool DEX::Execute()
{
    
        uint32_t x = static_cast<uint32_t>(m_reg->x());
        uint32_t r;

        r = x - 1;

        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool DEY::Execute()
{
    
        uint32_t y = static_cast<uint32_t>(m_reg->y());
        uint32_t r;

        r = y - 1;

        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool EOR::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t a = static_cast<uint32_t>(m_reg->a());
        uint32_t r;

        r = a ^ o;

        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool INC::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = o + 1;

        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool INX::Execute()
{
    
        uint32_t x = static_cast<uint32_t>(m_reg->x());
        uint32_t r;

        r = x + 1;

        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool INY::Execute()
{
    
        uint32_t y = static_cast<uint32_t>(m_reg->y());
        uint32_t r;

        r = y + 1;

        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool JML::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = o;

        m_reg->pc(r);
        return true;

}

bool JMP::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = o;

        m_reg->pc(r);
        return true;

}

bool JSL::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        assert(0);

        return true;

}

bool JSR::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        assert(0);

        return true;

}

bool LDA::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = o;

        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool LDX::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = o;

        m_reg->x(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool LDY::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = o;

        m_reg->y(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool LSR::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t u;
        uint32_t r;

        u = o & 0x1; r = o >> 1;

        m_reg->n(0);
        m_reg->z(get_z(r));
        m_reg->c(u);
        return true;

}

bool MVN::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        assert(0);

        return true;

}

bool MVP::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        assert(0);

        return true;

}

bool NOP::Execute()
{
    
        uint32_t r;

        

        return true;

}

bool ORA::Execute()
{
    
        uint32_t a = static_cast<uint32_t>(m_reg->a());
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = a | o;

        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool PEA::Execute()
{
        uint16_t o = m_addrMode->operand();

        m_reg->s(m_reg->s() - 2);
        m_mem->Write(m_reg->s()+2, static_cast<uint8_t>(o>>8));
        m_mem->Write(m_reg->s()+1, static_cast<uint8_t>(o&0xff));

        return true;
}

bool PEI::Execute()
{
        uint16_t o = m_addrMode->operand();
        uint16_t a = m_mem->Read<uint16_t>(o);

        m_reg->s(m_reg->s() - 2);
        m_mem->Write(m_reg->s()+2, static_cast<uint8_t>(a>>8));
        m_mem->Write(m_reg->s()+1, static_cast<uint8_t>(a&0xff));

        return true;
}

bool PER::Execute()
{
        uint16_t o = m_addrMode->operand();
        uint16_t a = m_mem->Read<uint16_t>(o);

        m_reg->s(m_reg->s() - 2);
        m_mem->Write(m_reg->s()+2, static_cast<uint8_t>(a>>8));
        m_mem->Write(m_reg->s()+1, static_cast<uint8_t>(a&0xff));

        return true;
}

bool PHA::Execute()
{
    
        uint16_t a = m_reg->a();
        uint16_t r;

        m_reg->s(m_reg->s() - 2);
        m_mem->Write(m_reg->s()+2, static_cast<uint8_t>(a>>8));
        m_mem->Write(m_reg->s()+1, static_cast<uint8_t>(a&0xff));

        return true;

}

bool PHB::Execute()
{
    
        uint16_t a = m_reg->dbr();

        m_reg->s(m_reg->s() - 2);
        m_mem->Write(m_reg->s()+2, static_cast<uint8_t>(a>>8));
        m_mem->Write(m_reg->s()+1, static_cast<uint8_t>(a&0xff));

        return true;

}

bool PHD::Execute()
{
    
        // uint16_t a = m_reg->d();

        // m_reg->s(m_reg->s() - 2);
        // m_mem->Write(m_reg->s()+2, static_cast<uint8_t>(a>>8));
        // m_mem->Write(m_reg->s()+1, static_cast<uint8_t>(a&0xff));

        return true;

}

bool PHK::Execute()
{
    
        // uint16_t a = m_reg->k();

        // m_reg->s(m_reg->s() - 2);
        // m_mem->Write(m_reg->s()+2, static_cast<uint8_t>(a>>8));
        // m_mem->Write(m_reg->s()+1, static_cast<uint8_t>(a&0xff));

        return true;

}

bool PHP::Execute()
{
    
        uint8_t a = m_reg->stat();

        m_reg->s(m_reg->s() - 1);
        m_mem->Write(m_reg->s()+1, static_cast<uint8_t>(a&0xff));

        return true;

}

bool PHX::Execute()
{
    
        uint16_t a = m_reg->x();

        m_reg->s(m_reg->s() - 2);
        m_mem->Write(m_reg->s()+2, static_cast<uint8_t>(a>>8));
        m_mem->Write(m_reg->s()+1, static_cast<uint8_t>(a&0xff));

        return true;

}

bool PHY::Execute()
{
    
        uint16_t a = m_reg->y();

        m_reg->s(m_reg->s() - 2);
        m_mem->Write(m_reg->s()+2, static_cast<uint8_t>(a>>8));
        m_mem->Write(m_reg->s()+1, static_cast<uint8_t>(a&0xff));

        return true;

}

bool PLA::Execute()
{
    
        uint16_t r = 0;

        m_reg->s(m_reg->s() + 2);
        r |= m_mem->Read<uint8_t>(m_reg->s()-1)<<8;
        r |= m_mem->Read<uint8_t>(m_reg->s()-2)&0xff;

        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));        
        
        return true;

}

bool PLB::Execute()
{
    
        uint16_t r = 0;

        m_reg->s(m_reg->s() + 2);
        r |= m_mem->Read<uint8_t>(m_reg->s()-1)<<8;
        r |= m_mem->Read<uint8_t>(m_reg->s()-2)&0xff;

        m_reg->dbr(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));        
        return true;

}

bool PLD::Execute()
{
    
        uint16_t r = 0;

        m_reg->s(m_reg->s() + 2);
        r |= m_mem->Read<uint8_t>(m_reg->s()-1)<<8;
        r |= m_mem->Read<uint8_t>(m_reg->s()-2)&0xff;

        m_reg->dr(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));        
        return true;

}

bool PLP::Execute()
{
    
        uint16_t r = 0;

        m_reg->s(m_reg->s() + 1);
        r |= m_mem->Read<uint8_t>(m_reg->s()-1);

        m_reg->stat(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));        
        return true;

}

bool PLX::Execute()
{
    
        uint16_t r = 0;

        m_reg->s(m_reg->s() + 2);
        r |= m_mem->Read<uint8_t>(m_reg->s()-1)<<8;
        r |= m_mem->Read<uint8_t>(m_reg->s()-2)&0xff;

        m_reg->x(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));        
        return true;

}

bool PLY::Execute()
{
    
        uint16_t r = 0;

        m_reg->s(m_reg->s() + 2);
        r |= m_mem->Read<uint8_t>(m_reg->s()-1)<<8;
        r |= m_mem->Read<uint8_t>(m_reg->s()-2)&0xff;

        m_reg->y(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));        
        return true;

}

bool REP::Execute()
{
    
        uint8_t o = static_cast<uint8_t>(m_addrMode->operand());
        uint8_t r = m_reg->stat();

        r =  r & ~o;

        m_reg->stat(r);

        return true;

}

bool ROL::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = (o << 1) | (m_reg->c() ? 1 : 0);

        m_addrMode->operand(r);
        m_reg->c(get_c(r));
        m_reg->z(get_z(r));
        m_reg->n(get_n(r));
        return true;

}

bool ROR::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        r = (o >> 1) | (m_reg->c() ? 0x8000 : 0);

        m_addrMode->operand(r);
        m_reg->c(o & 1);
        m_reg->z(get_z(r));
        m_reg->n(get_n(r));
        return true;

}

bool RTI::Execute()
{
    
        // Pull the status register from the stack
        uint8_t p = m_mem->Read<uint8_t>(m_reg->s() + 1);
        m_reg->s(m_reg->s() + 2);

        // Set the status register in the register file
        m_reg->stat(p);

        // Pull the program counter from the stack
        uint16_t pc = m_mem->Read<uint8_t>(m_reg->s());
        m_reg->s(m_reg->s() + 1);
        pc |= m_mem->Read<uint8_t>(m_reg->s()) << 8;
        m_reg->s(m_reg->s() + 1);

        // Set the program counter in the register file
        m_reg->pc(pc);

        return true;

}

bool RTL::Execute()
{
    
        uint16_t pcl = m_mem->Read<uint8_t>(m_reg->s());
        m_reg->s(m_reg->s() + 1);
        uint16_t pch = m_mem->Read<uint8_t>(m_reg->s());
        m_reg->s(m_reg->s() + 1);
        m_reg->pc((pch << 8) | pcl);
        m_reg->pc(m_reg->pc() + 1);
        uint8_t pb = m_mem->Read<uint8_t>(m_reg->s());
        m_reg->s(m_reg->s() + 1);
        m_reg->k(pb);
        
        return true;

}

bool RTS::Execute()
{
    
        uint16_t pcl = m_mem->Read<uint8_t>(m_reg->s());
        m_reg->s(m_reg->s() + 1);
        uint16_t pch = m_mem->Read<uint8_t>(m_reg->s());
        m_reg->s(m_reg->s() + 1);
        m_reg->pc((pch << 8) | pcl);
        m_reg->pc(m_reg->pc() + 1);

        return true;

}

bool SBC::Execute()
{
    
        uint32_t a = static_cast<uint32_t>(m_reg->a());
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t c = m_reg->c() ? 1 : 0;
        uint32_t r;

        r = a - o - (1 - c);

        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->v((a ^ o) & (a ^ r) & 0x8000);
        m_reg->c(get_c(r));
        m_reg->z(get_z(r));
        return true;

}

bool SEC::Execute()
{
    
        uint32_t r;

        r = 1;

        m_reg->c(r);
        return true;

}

bool SED::Execute()
{
    
        uint32_t r;

        r = 1;

        m_reg->d(r);
        return true;

}

bool SEI::Execute()
{
    
        uint32_t r;

        r = 1;

        m_reg->i(r);
        return true;

}

bool SEP::Execute()
{
        uint8_t o = static_cast<uint8_t>(m_addrMode->operand());
        uint8_t r = m_reg->stat();

        r = r | o;

        m_reg->stat(r);

        return true;

}

bool STA::Execute()
{
    
        m_addrMode->operand(m_reg->a());
        
        return true;

}

bool STP::Execute()
{
    
        m_addrMode->operand(m_reg->stat());

        return true;

}

bool STX::Execute()
{
    
        m_addrMode->operand(m_reg->x());

        return true;

}

bool STY::Execute()
{
    
        m_addrMode->operand(m_reg->y());

        return true;

}

bool STZ::Execute()
{
    
        m_addrMode->operand(0);

        return true;

}

bool TAX::Execute()
{
    
        uint32_t r = m_reg->a();

        m_reg->x(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool TAY::Execute()
{
    
        uint32_t r = m_reg->a();

        m_reg->y(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool TCD::Execute()
{
    
        uint32_t r = m_reg->a();

        m_reg->dr(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool TCS::Execute()
{
    
        uint32_t r = m_reg->a();

        m_reg->s(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

// TDC - Transfer Direct Page to Accumulator
bool TDC::Execute()
{
    
       uint32_t r = m_reg->dr();

        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool TRB::Execute()
{
    
        uint16_t r = m_addrMode->operand();
        bool bitSet;

        bitSet = (r & m_reg->a()) != 0;
        m_reg->z(bitSet ? 0 : 1);
        r &= ~m_reg->a();
        m_addrMode->operand(r);
        return true;
}

bool TSB::Execute()
{
    
        uint16_t r = m_addrMode->operand();
        bool bitSet;

        bitSet = (r & m_reg->a()) != 0;
        m_reg->z(bitSet ? 0 : 1);
        r |= m_reg->a();
        m_addrMode->operand(r);
        return true;

}

bool TSC::Execute()
{
    
        uint32_t r = m_reg->s();

        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool TSX::Execute()
{
    
        uint32_t r = m_reg->s();

        m_reg->x(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool TXA::Execute()
{
    
        uint32_t r = m_reg->x();

        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool TXS::Execute()
{
    
        uint32_t r = m_reg->x();

        m_reg->s(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool TXY::Execute()
{
    
        uint32_t r = m_reg->x();

        m_reg->y(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

// TYA transfers the Y register to the A register.
bool TYA::Execute()
{
    
        uint32_t r = m_reg->y();

        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

// TYX transfers the Y register to the X register.
bool TYX::Execute()
{
    
        uint32_t r = m_reg->y();

        m_reg->x(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool WAI::Execute()
{
    
        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());
        uint32_t r;

        assert(0);

        return true;

}


bool WDM::Execute()
{
    
        return true;

}

bool XBA::Execute()
{

        uint16_t r = m_reg->a();

        r = ((r & 0xFF) << 8) | ((r & 0xFF00) >> 8);
        m_reg->a(r);
        m_reg->n(get_n(r));
        m_reg->z(get_z(r));
        return true;

}

bool XCE::Execute()
{
 
        bool c = m_reg->c();
        bool e = m_reg->e();

        m_reg->c(e);
        m_reg->e(c);
        return true;

}


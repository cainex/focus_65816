#pragma once

#include <cstdint>

union Reg
{
    Reg(uint16_t v): w(v) {}

    uint16_t w;
    struct val {
        uint8_t l : 8;
        uint8_t h : 8;
    } r;
};

class RegisterFile
{
public:
    const uint8_t N_POS = 7;
    const uint8_t V_POS = 6;
    const uint8_t M_POS = 5;
    const uint8_t X_POS = 4;
    const uint8_t B_POS = 4;
    const uint8_t D_POS = 3;
    const uint8_t I_POS = 2;
    const uint8_t Z_POS = 1;
    const uint8_t C_POS = 0;

    RegisterFile() : m_a(0), m_x(0), m_y(0), m_s(0), m_pc(0), m_dr(0), m_pbr(0), m_dbr(0), m_k(0),  m_stat(0), m_e(false){}
    ~RegisterFile() {}

    // 8-bit registers
    const uint8_t al()  { return m_a.r.l; }
    const uint8_t ah()  { return m_a.r.h; }
    const uint8_t xl()  { return m_x.r.l; }
    const uint8_t xh()  { return m_x.r.h; }
    const uint8_t yl()  { return m_y.r.l; }
    const uint8_t yh()  { return m_y.r.h; }
    const uint8_t pcl() { return m_pc.r.l; }
    const uint8_t pch() { return m_pc.r.h; }
    const uint8_t drl() { return m_dr.r.l; }
    const uint8_t drh() { return m_dr.r.h; }
    const uint8_t pbr() { return m_pbr; }
    const uint8_t dbr() { return m_dbr; }
    const uint8_t k()   { return m_k; }
    const uint8_t sl()   { return m_s.r.l; }
    const uint8_t sh()   { return m_s.r.h; }

    void al(const uint8_t val)   { m_a.r.l = val; }
    void ah(const uint8_t val)   { m_a.r.h = val; }
    void xl(const uint8_t val)   { m_x.r.l = val; }
    void xh(const uint8_t val)   { m_x.r.h = val; }
    void yl(const uint8_t val)   { m_y.r.l = val; }
    void yh(const uint8_t val)   { m_y.r.h = val; }
    void pcl(const uint8_t val)  { m_pc.r.l = val; }
    void pch(const uint8_t val)  { m_pc.r.h = val; }
    void drl(const uint8_t val)  { m_dr.r.l = val; }
    void drh(const uint8_t val)  { m_dr.r.h = val; }
    void pbr(const uint8_t val)  { m_pbr = val; }
    void dbr(const uint8_t val)  { m_dbr = val; }
    void k(const uint8_t val)    { m_k = val; }
    void sl(const uint8_t val)   { m_s.r.l = val; }
    void sh(const uint8_t val)   { m_s.r.h = val; }

    // 16-bit registers
    const uint16_t a()  { return m_a.w; }
    const uint16_t x()  { return m_x.w; }
    const uint16_t y()  { return m_y.w; }
    const uint16_t pc() { return m_pc.w; }
    const uint16_t dr() { return m_dr.w; }
    const uint16_t s()  { return m_s.w; }

    void a(const uint16_t val)  { m_a.w = val; }
    void x(const uint16_t val)  { m_x.w = val; }
    void y(const uint16_t val)  { m_y.w = val; }
    void pc(const uint16_t val) { m_pc.w = val; }
    void dr(const uint16_t val) { m_dr.w = val; }
    void s(const uint16_t val)  { m_s.w = val; }

    // 24-bit addresses
    const uint32_t x_addr() 
    { 
        return  (static_cast<const uint32_t>(m_dbr)<<16) | static_cast<uint32_t>(m_x.w); 
    }

    const uint32_t y_addr() 
    { 
        return  (static_cast<const uint32_t>(m_dbr)<<16) | static_cast<uint32_t>(m_y.w); 
    }

    const uint32_t s_addr()
    {
        return static_cast<uint32_t>(m_s.w);
    }

    const uint32_t pc_addr()
    {
        return  (static_cast<const uint32_t>(m_pbr)<<16) | static_cast<uint32_t>(m_pc.w); 
    }

    const uint32_t dr_addr()
    {
        return static_cast<uint32_t>(m_dr.w);
    }

    // status bits
    const uint8_t stat() { return m_stat; }
    const bool n() { return m_stat & (0x1<<N_POS); }
    const bool v() { return m_stat & (0x1<<V_POS); }
    const bool m() { return m_stat & (0x1<<M_POS); }
    const bool b() { return m_stat & (0x1<<B_POS); }
    const bool ix() { return m_stat & (0x1<<X_POS); }
    const bool d() { return m_stat & (0x1<<D_POS); }
    const bool i() { return m_stat & (0x1<<I_POS); }
    const bool z() { return m_stat & (0x1<<Z_POS); }
    const bool c() { return m_stat & (0x1<<C_POS); }
    const bool e() { return m_e; }

    void setStat(uint8_t idx, bool value)
    {
        if (value)
            m_stat |= 0x1 << idx;
        else
            m_stat &= ~(0x1 << idx);    
    }

    void setN() { setStat(N_POS, true); }
    void setV() { setStat(V_POS, true); }
    void setM() { setStat(M_POS, true); }
    void setB() { setStat(B_POS, true); }
    void setIx() { setStat(X_POS, true); }
    void setD() { setStat(D_POS, true); }
    void setI() { setStat(I_POS, true); }
    void setZ() { setStat(Z_POS, true); }
    void setC() { setStat(C_POS, true); }
    void setE() { m_e = true; }

    void clrN() { setStat(N_POS, false); }
    void clrV() { setStat(V_POS, false); }
    void clrM() { setStat(M_POS, false); }
    void clrB() { setStat(B_POS, false); }
    void clrIx() { setStat(X_POS, false); }
    void clrD() { setStat(D_POS, false); }
    void clrI() { setStat(I_POS, false); }
    void clrZ() { setStat(Z_POS, false); }
    void clrC() { setStat(C_POS, false); }
    void clrE() { m_e = false; }

    void stat(const uint8_t val) { m_stat = val; }
    void n(bool v) { setStat(N_POS, v); }
    void v(bool v) { setStat(V_POS, v); }
    void m(bool v) { setStat(M_POS, v); }
    void b(bool v) { setStat(B_POS, v); }
    void ix(bool v) { setStat(X_POS, v); }
    void d(bool v) { setStat(D_POS, v); }
    void i(bool v) { setStat(I_POS, v); }
    void z(bool v) { setStat(Z_POS, v); }
    void c(bool v) { setStat(C_POS, v); }
    void e(bool v) { m_e = v; }


protected:
    Reg m_a;
    Reg m_x;
    Reg m_y;
    Reg m_s;
    Reg m_pc;
    Reg m_dr;
    uint8_t m_pbr;
    uint8_t m_dbr;
    uint8_t m_k;
    uint8_t m_stat;
    bool m_e;

};

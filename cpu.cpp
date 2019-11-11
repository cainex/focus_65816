#include "cpu.hpp"
#include <iostream>

Cpu::Cpu()  : m_rf(std::make_shared<RegisterFile>()), m_mem(std::make_shared<MemoryManager>()), m_dec(std::make_shared<Decoder>(m_mem, m_rf))
{

}

Cpu::Cpu(std::shared_ptr<MemoryManager> mem) :
    m_rf(std::make_shared<RegisterFile>()), m_mem(move(mem)), m_dec(std::make_shared<Decoder>(m_mem, m_rf))
{

}

Cpu::~Cpu() {}

void Cpu::Execute()
{
    std::cout << "CPU - PC[" << std::hex << m_rf->pc_addr() << std::dec << "] ";
    auto op = m_dec->DecodeNext();
    op->Execute();
}

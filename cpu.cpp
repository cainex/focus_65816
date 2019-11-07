#include "cpu.hpp"
#include <iostream>

Cpu::Cpu()  : _rf(std::make_shared<RegisterFile>()), _mem(std::make_shared<MemoryManager>()), _dec(std::make_shared<Decoder>(_mem, _rf))
{

}

Cpu::Cpu(std::shared_ptr<MemoryManager> mem) :
    _rf(std::make_shared<RegisterFile>()), _mem(move(mem)), _dec(std::make_shared<Decoder>(_mem, _rf))
{

}

Cpu::~Cpu() {}

void Cpu::Execute()
{
    std::cout << "CPU - PC[" << std::hex << _rf->pc_addr() << std::dec << "] ";
    auto op = _dec->DecodeNext();
    op->Execute();
}
#pragma once
#include "decoder.hpp"
#include "memory_manager.hpp"
#include "register_file.hpp"

class Cpu 
{
public:
Cpu();
Cpu(std::shared_ptr<MemoryManager> mem);
~Cpu();

void Execute();

protected:
std::shared_ptr<RegisterFile> _rf;
std::shared_ptr<MemoryManager> _mem;
std::shared_ptr<Decoder> _dec;


};

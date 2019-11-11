#include "memory.hpp"
#include <iostream>

Memory::Memory() : m_mem(new uint8_t[1<<24])
{
}

Memory::Memory(uint32_t size, uint32_t base) : MemoryDevice(size, base), m_mem(new uint8_t[1<<24])
{
}

Memory::~Memory()
{
}

bool Memory::Read(const uint32_t &address, uint8_t  &data)
{
    std::cout << "[" << std::hex << address << "] -> " << static_cast<uint16_t>(m_mem[address]) << std::dec << std::endl;
    data = m_mem[address];
    return true;

}

bool Memory::Read(const uint32_t &address, uint16_t &data)
{
    std::cout << "[" << std::hex << address << "] -> " << (static_cast<uint16_t>(m_mem[address+1])<<8 | static_cast<uint16_t>(m_mem[address])) << std::dec << std::endl;
    data = m_mem[address];
    data = data + (static_cast<uint16_t>(m_mem[address+1]) << 8);

    return true;

}

bool Memory::Write(const uint32_t &address, const uint8_t  &data)
{
    m_mem[address] = data;
    std::cout << "[" << std::hex << address << "] <- " << static_cast<uint16_t>(data) << std::dec << std::endl;
    return true;

}

bool Memory::Write(const uint32_t &address, const uint16_t &data)
{
    m_mem[address] = static_cast<uint8_t>(data);
    m_mem[address+1] = static_cast<uint8_t>(data>>8);
    std::cout << "[" << std::hex << address << "] <- " << data << std::dec << std::endl;
    return true;
}

#include "memory_manager.hpp"
#include <iostream>

bool MemoryManager::Read(const uint32_t &address, uint8_t &data)
{
    data = m_mem[address];
    return true;
}

template<typename T>
T MemoryManager::Read(const uint32_t &address)
{
    return 0;
}

template<>
uint8_t MemoryManager::Read(const uint32_t &address)
{
    std::cout << "[" << std::hex << address << "] -> " << static_cast<uint16_t>(m_mem[address]) << std::dec << std::endl;
    return m_mem[address];
}

template<>
uint16_t MemoryManager::Read(const uint32_t &address)
{
    std::cout << "[" << std::hex << address << "] -> " << (static_cast<uint16_t>(m_mem[address+1])<<8 | static_cast<uint16_t>(m_mem[address])) << std::dec << std::endl;
    return static_cast<uint16_t>(m_mem[address+1])<<8 | static_cast<uint16_t>(m_mem[address]);
}
    

bool MemoryManager::Write(const uint32_t &address, const uint8_t &data)
{
    m_mem[address] = data;
    std::cout << "[" << std::hex << address << "] <- " << static_cast<uint16_t>(data) << std::dec << std::endl;
    return true;
}

bool MemoryManager::Write(const uint32_t &address, const uint16_t &data)
{
    m_mem[address] = static_cast<uint8_t>(data);
    m_mem[address+1] = static_cast<uint8_t>(data>>8);
    std::cout << "[" << std::hex << address << "] <- " << data << std::dec << std::endl;
    return true;
}

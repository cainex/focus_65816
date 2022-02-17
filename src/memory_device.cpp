#include "memory_device.hpp"

MemoryDevice::MemoryDevice() : m_size(1<<24), m_base(0)
{

}

MemoryDevice::MemoryDevice(uint32_t size, uint32_t base) : m_size(size), m_base(base)
{

}

MemoryDevice::~MemoryDevice() 
{

}

const uint32_t MemoryDevice::GetBaseAddress()
{
    return m_base;
}

const uint32_t MemoryDevice::GetLimitAddress()
{
    return (m_base + m_size)-1;
}

const uint32_t MemoryDevice::GetSize()
{
    return m_size;
}

bool MemoryDevice::Contains(const uint32_t &address)
{
    if (address >= m_base && address <= (m_base + m_size - 1)) {
        return true;
    }

    return false;
}

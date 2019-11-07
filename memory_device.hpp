#pragma once

#include <cstdint>
#include <memory>
#include <cstdint>

class MemoryDevice
{
public:
MemoryDevice();
~MemoryDevice();

virtual const uint32_t GetBaseAddress();
virtual const uint32_t GetLimitAddress();
virtual const uint32_t GetSize();
virtual bool Contains(const uint32_t &address);

protected:
uint32_t m_size;
uint32_t m_base;

};

#pragma once

#include "memory_device.hpp"
#include <cstdint>
#include <memory>

class Memory : public MemoryDevice 
{
public:
Memory();
Memory(uint32_t size, uint32_t base);
~Memory();

virtual bool Read(const uint32_t &address, uint8_t  &data);
virtual bool Read(const uint32_t &address, uint16_t &data);

virtual bool Write(const uint32_t &address, const uint8_t  &data);
virtual bool Write(const uint32_t &address, const uint16_t &data);

protected:
std::unique_ptr<uint8_t[]> m_mem;

};

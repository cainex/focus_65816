#pragma once

#include <memory>
#include <cstdint>

class MemoryDevice
{
public:
MemoryDevice();
MemoryDevice(uint32_t size, uint32_t base);
~MemoryDevice();

virtual const uint32_t GetBaseAddress();
virtual const uint32_t GetLimitAddress();
virtual const uint32_t GetSize();
virtual bool Contains(const uint32_t &address);

virtual bool Read(const uint32_t &address, uint8_t  &data) = 0;
virtual bool Read(const uint32_t &address, uint16_t &data) = 0;

virtual bool Write(const uint32_t &address, const uint8_t  &data) = 0;
virtual bool Write(const uint32_t &address, const uint16_t &data) = 0;

protected:
uint32_t m_size;
uint32_t m_base;

};

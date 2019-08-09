#pragma once

#include <cstdint>
#include <memory>

class MemoryManager
{
public:
    MemoryManager() : m_size(1<<24), m_mem(new uint8_t[1<<24]) {}
    ~MemoryManager() {}

    virtual bool Read(const uint32_t &address, uint8_t &data);
    template <typename T>
    T Read(const uint32_t &address);

    bool Write(const uint32_t &address, const uint8_t &data);
    bool Write(const uint32_t &address, const uint16_t &data);

protected:
    uint32_t m_size;
    std::unique_ptr<uint8_t[]> m_mem;
};
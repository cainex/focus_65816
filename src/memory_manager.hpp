#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include "memory_device.hpp"

class MemoryManager
{
public:
    MemoryManager() {}
    ~MemoryManager() {}

    virtual bool Read(const uint32_t &address, uint8_t &data);
    template <typename T>
    T Read(const uint32_t &address);

    bool Write(const uint32_t &address, const uint8_t &data);
    bool Write(const uint32_t &address, const uint16_t &data);

    bool Push(const uint8_t &data);
    bool Pull(uint8_t &data);
    
    bool AddDevice(std::shared_ptr< MemoryDevice> device);
    std::shared_ptr<MemoryDevice> GetDevice(const uint32_t &address);

protected:
    std::vector< std::shared_ptr< MemoryDevice > > m_devices;
};

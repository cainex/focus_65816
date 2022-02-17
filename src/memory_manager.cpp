#include "memory_manager.hpp"
#include <iostream>
#include <algorithm>

bool MemoryManager::Read(const uint32_t &address, uint8_t &data)
{
    std::shared_ptr<MemoryDevice> dev = std::move(GetDevice(address));
    if (dev == nullptr) {
        return false;
    }

    return dev->Read(address, data);
}

template<typename T>
T MemoryManager::Read(const uint32_t &address)
{
    return 0;
}

template<>
uint8_t MemoryManager::Read(const uint32_t &address)
{
    std::shared_ptr<MemoryDevice> dev = std::move(GetDevice(address));
    if (dev == nullptr) {
        return false;
    }

    uint8_t data;
    dev->Read(address, data);

    return data;
}

template<>
uint16_t MemoryManager::Read(const uint32_t &address)
{
    std::shared_ptr<MemoryDevice> dev = std::move(GetDevice(address));
    if (dev == nullptr) {
        return false;
    }

    uint16_t data;
    dev->Read(address, data);

    return data;
}
    

bool MemoryManager::Write(const uint32_t &address, const uint8_t &data)
{
    std::shared_ptr<MemoryDevice> dev = std::move(GetDevice(address));
    if (dev == nullptr) {
        return false;
    }

    return dev->Write(address, data);
}

bool MemoryManager::Write(const uint32_t &address, const uint16_t &data)
{
    std::shared_ptr<MemoryDevice> dev = std::move(GetDevice(address));
    if (dev == nullptr) {
        return false;
    }

    return dev->Write(address, data);
}

bool MemoryManager::AddDevice(std::shared_ptr< MemoryDevice > device)
{
    m_devices.push_back(device);

    return true;
}

std::shared_ptr<MemoryDevice> MemoryManager::GetDevice(const uint32_t &address)
{
    std::shared_ptr<MemoryDevice> found_device;

    std::for_each(m_devices.begin(), m_devices.end(), [&found_device, address](std::shared_ptr<MemoryDevice> &d) {
        if (d->Contains(address)) {
            found_device = d;
        } 
    });

    return found_device;
}

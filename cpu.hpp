#pragma once

#include "memory_device.hpp"

class Cpu : public MemoryDevice
{
public:
Cpu() : MemoryDevice() {}
~Cpu() {}


};

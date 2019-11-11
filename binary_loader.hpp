#pragma once

#include <memory>
#include <string>
#include <exception>
#include "memory_manager.hpp"

class BinaryLoader
{
public:
BinaryLoader();
BinaryLoader(std::shared_ptr<MemoryManager> mem);
~BinaryLoader();

void Load(std::string filename);

struct FileError : public std::exception
{
    const char * what () const throw () {
        return "File Error";
    }
};

protected:
std::shared_ptr<MemoryManager> m_mem;

};

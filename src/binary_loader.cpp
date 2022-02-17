#include "binary_loader.hpp"
#include <fstream>
#include <iostream>

BinaryLoader::BinaryLoader()
{
}

BinaryLoader::BinaryLoader(std::shared_ptr<MemoryManager> mem) : m_mem(mem)
{
}

BinaryLoader::~BinaryLoader()
{
}

void BinaryLoader::Load(std::string filename)
{
    std::cout << "Loading " << filename.c_str() << std::endl;

    // Get filesize
    std::ifstream infile(filename.c_str(), std::ios::ate | std::ios::binary);

    if (!infile) {
       throw(FileError());
    }

    uint32_t filesize = infile.tellg();
    uint32_t offset = 0;

    infile.close();

    infile.open(filename.c_str(), std::ios::in | std::ios::binary);
    if (!infile) {
       throw(FileError());
    }
    
    for (uint32_t i = 0; i < filesize; i++) {
        uint8_t next_c;

        std::cout << ".";
        infile.read(reinterpret_cast<char*>(&next_c), 1);
        m_mem->Write(offset, next_c);
        offset++;
    }

    std::cout << std::endl;
}

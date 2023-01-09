#include <iostream>
#include <memory>
#include "cpu.hpp"
#include "memory_manager.hpp"
#include "memory.hpp"
#include "binary_loader.hpp"
#include "deps/cxxopts/include/cxxopts.hpp">

int main (int argc, char* argv[])
{

    cxxopts::Options options(argv[0], "Focus 65c816 simulator");
    options.add_options()
        ("help", "print help")
        ("d,debug", "Enable debugging")
        ("f,file", "Filename of binary to load", cxxopts::value<std::string>()->default_value(std::string("test.out")));
    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help({""}) << std::endl;
        exit(0);
    }
    std::cout << "Initializing!" << std::endl;

    auto mem = std::make_shared<MemoryManager>();
    auto lmem = std::make_shared<Memory>(1<<24, 0);
    mem->AddDevice(std::static_pointer_cast<MemoryDevice>(lmem));
    auto cpu = std::make_shared<Cpu>(mem);

    auto loader = std::make_shared<BinaryLoader>(mem);

    try
    {
        loader->Load(result["file"].as<std::string>());
    }
    catch(const BinaryLoader::FileError& e)
    {
        std::cout << e.what() << '\n';
        exit(0);
    }
    

    mem->Read<uint16_t>(0x52);
    std::cout << "Execute" << std::endl;
    
    for (int i =0; i < 3; i++) {
        cpu->Execute();
    }
    mem->Read<uint16_t>(0x52);

    exit(0);

}
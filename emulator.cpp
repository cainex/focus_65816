#include <iostream>
#include "decoder.hpp"
#include "memory_manager.hpp"
#include "register_file.hpp"

int main (int argc, char* argv[])
{
    std::cout << "Initializing!" << std::endl;

    auto rf = std::make_shared<RegisterFile>();
    auto mem = std::make_shared<MemoryManager>();
    auto dec = std::make_shared<Decoder>(mem, rf);

    std::cout << "Loading memory" << std::endl;

// 000000r 1               .P816
// 000000r 1               .ORG $0000
// 000000  1               .CODE
// 000000  1               test_adc:
// 000000  1  A9 10            lda #$0010
// 000002  1  6D 00 20         adc data
// 000005  1  8D 04 20         sta out_data
// 000008  1               .ORG $2000
// 002000  1               .DATA
// 002000  1               data:
// 002000  1  0D 0C 0B 0A      .DWORD $0a0b0c0d
// 002004  1               out_data:
// 002004  1  44 33 22 11      .DWORD $11223344
// 002004  1               

    mem->Write(0x0000, static_cast<uint8_t>(0xa9));
    mem->Write(0x0001, static_cast<uint8_t>(0x10));
    mem->Write(0x0002, static_cast<uint8_t>(0x00));
    mem->Write(0x0003, static_cast<uint8_t>(0x6d));
    mem->Write(0x0004, static_cast<uint8_t>(0x00));
    mem->Write(0x0005, static_cast<uint8_t>(0x20));
    mem->Write(0x0006, static_cast<uint8_t>(0x8d));
    mem->Write(0x0007, static_cast<uint8_t>(0x04));
    mem->Write(0x0008, static_cast<uint8_t>(0x20));
    mem->Write(0x2000, static_cast<uint8_t>(0x01));
    mem->Write(0x2001, static_cast<uint8_t>(0x02));
    mem->Write(0x2002, static_cast<uint8_t>(0x03));
    mem->Write(0x2003, static_cast<uint8_t>(0x04));


    mem->Read<uint16_t>(0x2004);
    std::cout << "Execute" << std::endl;
    
    for (int i =0; i < 3; i++) {
        std::cout << "PC[" << std::hex << rf->pc_addr() << std::dec << "] ";
        auto op = dec->DecodeNext();
        op->Execute();
    }
    mem->Read<uint16_t>(0x2004);

    exit(0);

}
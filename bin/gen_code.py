from absl import app
from absl import flags
from jinja2 import Template
import json

FLAGS = flags.FLAGS
flags.DEFINE_string("filename", None, "Input definition file")
flags.DEFINE_string("decoder_filename", "generated_decoder", "Root filename for decoder")
flags.DEFINE_string("opcodes_filename", "generated_opcodes", "Root filename for opcodes")

# Required flag.
flags.mark_flag_as_required("filename")

decoder_preamble = """
#include "decoder.hpp"
#include <iostream>

std::shared_ptr<OpCode> Decoder::DecodeNext()
{
    uint8_t uop = m_mem->Read<uint8_t>(m_reg->pc_addr());

"""

decoder_postable = """
    std::cout << "UNKNOW UOP : " << std::hex << static_cast<uint32_t>(uop) << std::dec << std::endl;
    exit(1);

}"""

uop_template_string = """
    if (uop == {{ opcode }} ) { // {{ uop }} {{ addr_mode }}
        std::cout << "{{ uop }} {{ addr_mode_string }}" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new {{addr_mode}}_Mode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new {{ uop }}(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
"""

uop_template = Template(uop_template_string)

def render_uop(first, uop):
    return uop_template.render(first=first, opcode=uop['opcode'], uop=uop['uop'], addr_mode=uop['addr_mode'], addr_mode_string=uop['addr_mode_string'])

header_preamble = """
#pragma once

#include <cstdint>
#include <memory>
#include <assert.h>
#include "memory_manager.hpp"
#include "register_file.hpp"
#include "addressing_modes.hpp"

class OpCode 
{
public:
    OpCode() = delete;
    OpCode(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : m_addrMode(addrMode), m_mem(mem), m_reg(reg) {}
    ~OpCode() {}

    virtual bool Execute() = 0;

protected:
    std::shared_ptr<MemoryManager> m_mem;
    std::shared_ptr<RegisterFile> m_reg;
    std::shared_ptr<AddressingMode> m_addrMode;

    bool get_c(uint32_t r) { return r & 0x10000; }
    bool get_n(uint32_t r) { return r & 0x8000; }
    bool get_z(uint32_t r) { return r == 0; }
};

"""

header_postamble = """
"""

header_uop_string = """
class {{ uop }} : public OpCode
{
public:
    {{ uop }}() = delete;
    {{ uop }}(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~{{ uop }}() {}

    virtual bool Execute();
};

"""

source_preamble = """
#include "generated_opcodes.hpp"

"""

source_uop_string = """
bool {{ uop }}::Execute()
{
    {{ op }}
}

"""

source_postamble = """
"""

hdr_uop_template = Template(header_uop_string)
src_uop_template = Template(source_uop_string)

def render_operation(next_uop):
    operation = "\n"
    for input in next_uop['in']:
        if input == 'o':
            operation = operation + "        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());\n"
        elif input == 'a':
            operation = operation + "        uint32_t a = static_cast<uint32_t>(m_reg->a());\n"
        elif input == 'x':
            operation = operation + "        uint32_t x = static_cast<uint32_t>(m_reg->x());\n"
        elif input == 'y':
            operation = operation + "        uint32_t y = static_cast<uint32_t>(m_reg->y());\n"
        elif input == 'c':
            operation = operation + "        uint32_t c = m_reg->c() ? 1 : 0;\n"
        elif input == 'n':
            operation = operation + "        uint32_t n = m_reg->n() ? 1 : 0;\n"
        elif input == 'z':
            operation = operation + "        uint32_t z = m_reg->z() ? 1 : 0;\n"
        elif input == 'm':
            operation = operation + "        uint32_t m = m_reg->m() ? 1 : 0;\n"
        elif input == 'v':
            operation = operation + "        uint32_t v = m_reg->v() ? 1 : 0;\n"
        elif input == 'pc':
            operation = operation + "        uint32_t pc = m_reg->pc();\n"

    # iterate through internal variables if internal exists in next_uop
    if 'internal' in next_uop:
        for var in next_uop['internal']:
            operation = operation + "        uint32_t " + var + ";\n"

    operation = operation + "        uint32_t r;\n\n"

    operation = operation + "        " + next_uop['op'] + "\n\n"

    for output in next_uop['out'].items():
        if output[0] == 'o':
            operation = operation + "        m_addrMode->operand({});\n".format(output[1])
        else:
            operation = operation + "        m_reg->{}({});\n".format(output[0], output[1])

    operation = operation + "        return true;\n"
    return operation

def render_hdr_uop(next_uop):
    return hdr_uop_template.render(uop=next_uop['uop'])

def render_src_uop(next_uop):
    return src_uop_template.render(uop=next_uop['uop'], op=render_operation(next_uop))

def generate_decoder(uops):
    with open("{}.cpp".format(FLAGS.decoder_filename), "w") as src:
        src.write(decoder_preamble)
        first = False
        for uop in uops['uop_decode']:
            src.write(render_uop(first, uop))
            first = True
        src.write(decoder_postable)

def generate_uops(uops):
    with open("{}.hpp".format(FLAGS.opcodes_filename), "w") as hdr:
        hdr.write(header_preamble)
        for uop in uops['uops_operation']:
            hdr.write(render_hdr_uop(uop))
        hdr.write(header_postamble)
        
    with open("{}.cpp".format(FLAGS.opcodes_filename), "w") as src:
        src.write(source_preamble)
        for uop in uops['uops_operation']:
            src.write(render_src_uop(uop))
        src.write(source_postamble)

def main(argv):
    del argv  # Unused.

    uops = {}

    with open(FLAGS.filename) as fp:
        uops = json.load(fp)

    generate_decoder(uops)
    # generate_uops(uops)
    
if __name__ == '__main__':
    app.run(main)

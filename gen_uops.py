from absl import app
from absl import flags
from jinja2 import Template
import json

FLAGS = flags.FLAGS
flags.DEFINE_string("filename", None, "Input definition file")

# Required flag.
flags.mark_flag_as_required("filename")

decoder_preamble = """
#pragma once

#include <cstdint>
#include <memory>
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

    bool get_c(uint32_t r) { return r & 0x10000 ? m_reg->setC() : m_reg->clrC(); }
    bool get_n(uint32_t r) { return r & 0x8000 ? m_reg->setN() : m_reg->clrN(); }
    bool get_z(uint32_t r) { return r == 0 ? m_reg->setZ() : m_reg->clrZ(); }
};

"""

decoder_postable = """
"""

uop_template_string = """
class {{ uop }} : public OpCode
{
public:
    {{ uop }}() = delete;
    {{ uop }}(std::shared_ptr<AddressingMode> addrMode, std::shared_ptr<MemoryManager> mem, std::shared_ptr<RegisterFile> reg) : OpCode(addrMode, mem, reg) {}
    ~{{ uop }}() {}

    virtual bool Execute(
        {{ op }}
    );

};

"""

uop_template = Template(uop_template_string)

def render_operation(next_uop):
    operation = "\n"
    for input in next_uop['in']:
        if input == 'o':
            operation = operation + "        uint32_t o = static_cast<uint32_t>(m_addrMode->operand());\n"
        elif input == 'a':
            operation = operation + "        uint32_t a = static_cast<uint32_t>(m_reg->a());\n"
        elif input == 'c':
            operation = operation + "        uint32_t c = c = m_reg->c() ? 1 : 0"

    operation = operation + "        uint32_t r;\n\n"

    operation = operation + "        " + next_uop['op'] + "\n\n"

    for output in next_uop['out'].items():
        if output[0] == 'o':
            operation = operation + "        m_addrMode->operand({});\n".format(output[1])
        else:
            operation = operation + "        m_reg->{}({});\n".format(output[0], output[1])

    return operation

def render_uop(next_uop):
    return uop_template.render(uop=next_uop['uop'], op=render_operation(next_uop))
    
def main(argv):
    del argv  # Unused.

    uops = {}

    with open(FLAGS.filename) as fp:
        uops = json.load(fp)

    print(decoder_preamble)
    for uop in uops['uops']:
        print(render_uop(uop))
    print(decoder_postable)
    
if __name__ == '__main__':
    app.run(main)

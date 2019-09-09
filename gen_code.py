from absl import app
from absl import flags
from jinja2 import Template
import json

FLAGS = flags.FLAGS
flags.DEFINE_string("filename", None, "Input definition file")

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
    else {
        std::cout << "UNKNOW UOP : " << std::hex << static_cast<uint32_t>(uop) << std::dec << std::endl;
        exit(1);
    }

}"""

uop_template_string = """
    {% if first == True %} else {% endif %} if (uop == {{ opcode }} ) { // {{ uop }} {{ addr_mode }}
        std::cout << "{{ uop }}  {{ addr_mode }}" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new {{addr_mode}}Mode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new {{ uop }}(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
"""

uop_template = Template(uop_template_string)

def render_uop(first, uop):
    return uop_template.render(first=first, opcode=uop['opcode'], uop=uop['uop'], addr_mode=uop['addr_mode'])
    
def main(argv):
    del argv  # Unused.

    uops = {}

    with open(FLAGS.filename) as fp:
        uops = json.load(fp)

    print(decoder_preamble)
    first = False
    for uop in uops['uop_decode']:
        print(render_uop(first, uop))
        first = True
    print(decoder_postable)
    
if __name__ == '__main__':
    app.run(main)

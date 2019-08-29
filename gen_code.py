from absl import app
from absl import flags
from jinja2 import Template
import json

FLAGS = flags.FLAGS
flags.DEFINE_string("filename", None, "Input definition file")

# Required flag.
flags.mark_flag_as_required("filename")

uop_template_string = """
    if (uop == {{ opcode }} ) { // {{ uop }} {{ addr_mode }}
        std::cout << "{{ uop }}  {{ addr_mode }}" << std::endl;
        std::shared_ptr<AddressingMode> addressingMode(new {{addr_mode}}Mode(m_mem, m_reg));
        std::shared_ptr<OpCode> opCode(new {{ uop }}(addressingMode, m_mem, m_reg));
        m_reg->pc(m_reg->pc() + 1);
        return opCode;
    }
"""

uop_template = Template(uop_template_string)

def render_uop(uop):
    return uop_template.render(opcode=uop['opcode'], uop=uop['uop'], addr_mode=uop['addr_mode'])
    
def main(argv):
    del argv  # Unused.

    uops = {}

    with open(FLAGS.filename) as fp:
        uops = json.load(fp)

    for uop in uops['uop_decode']:
        print(render_uop(uop))

if __name__ == '__main__':
    app.run(main)

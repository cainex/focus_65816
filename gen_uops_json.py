from absl import app
from absl import flags

FLAGS = flags.FLAGS
flags.DEFINE_string("filename", None, "Input definition file")

# Required flag.
flags.mark_flag_as_required("filename")

def addressing_mode(addr_mode_string):
    if addr_mode_string == "#" :
        return "Immediate"
    elif addr_mode_string == "A":
        return "Accumulator"
    elif addr_mode_string == "r":
        return "ProgramCounterRelative"
    elif addr_mode_string == "rl":
        return "ProgramCounterRelativeLong"
    elif addr_mode_string == "i":
        return "Implied"
    elif addr_mode_string == "s":
        return "Stack"
    elif addr_mode_string == "d":
        return "Direct"
    elif addr_mode_string == "d,x":
        return "DirectIndexedWithX"
    elif addr_mode_string == "d,y":
        return "DirectIndexedWithY"
    elif addr_mode_string == "(d)":
        return "DirectIndirect"
    elif addr_mode_string == "(d,x)":
        return "DirectIndexedIndirect"
    elif addr_mode_string == "(d),y":
        return "DirectIndirectIndexed"
    elif addr_mode_string == "[d]":
        return "DirectIndirectLong"
    elif addr_mode_string == "[d],y":
        return "DirectIndirectLongIndexed"
    elif addr_mode_string == "a":
        return "Absolute"
    elif addr_mode_string == "a,x":
        return "AbsoluteIndexedWithX"
    elif addr_mode_string == "a,y":
        return "AbsoluteIndexedWithY"
    elif addr_mode_string == "al":
        return "AbsoluteLong"
    elif addr_mode_string == "al,x":
        return "AbsoluteLongIndexed"
    elif addr_mode_string == "d,s":
        return "StackRelative"
    elif addr_mode_string == "(d,s),y":
        return "StackRelativeIndirectIndexed"
    elif addr_mode_string == "(a)":
        return "AbsoluteIndirect"
    elif addr_mode_string == "(a,x)":
        return "AbsoluteIndexedIndirect"
    elif addr_mode_string == "xyc":
        return "BlockMove"
    else:
        print("Invalid Addressing Mode '{}'".format(addr_mode_string))
        raise ValueError

def main(argv):
    del argv  # Unused.

    uops = {}

    with open(FLAGS.filename) as fp:
        line = fp.readline()
        while line:
            split_line = line.split()
            uops[split_line[0]] = {'uop' : split_line[1], 'addr_mode' : addressing_mode(split_line[2]), 'cycles' : split_line[3]}
            line = fp.readline()

    num_uops = len(uops)
    print("{")
    print("\t\"uop_decode\": [")
    i = 0
    for k,v in uops.items():
        uop_string = "\t\t{{\"opcode\":\"0x{}\", \"uop\":\"{}\", \"addr_mode\":\"{}\", \"cycles\":\"{}\"}}".format(k, v["uop"].upper(), v['addr_mode'], v['cycles'])
        if i < num_uops - 1:
            uop_string = uop_string + ","
        print(uop_string)
        i = i + 1
    print("\t]")
    print("}")

if __name__ == '__main__':
    app.run(main)

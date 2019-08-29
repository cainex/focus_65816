from absl import app
from absl import flags

FLAGS = flags.FLAGS
flags.DEFINE_string("filename", None, "Input definition file")

# Required flag.
flags.mark_flag_as_required("filename")

def main(argv):
    del argv  # Unused.

    uops = {}

    with open(FLAGS.filename) as fp:
        line = fp.readline()
        while line:
            split_line = line.split()
            uops[split_line[0]] = {'uop' : split_line[1], 'addr_mode' : split_line[2], 'cycles' : split_line[3]}
            line = fp.readline()

    print("{")
    print("\t\"uops\": [")
    for k,v in uops.items():
        print("\t\t{{\"uop\":\"{}\", \"opcode\":\"{}\", \"addr_mode\":\"{}\", \"cycles\":\"{}\"}},".format(v["uop"], k, v['addr_mode'], v['cycles']))
    print("\t]")
    print("}")

if __name__ == '__main__':
    app.run(main)

from absl import app
from absl import flags
import json

FLAGS = flags.FLAGS
flags.DEFINE_string("filename", None, "Input definition file")

# Required flag.
flags.mark_flag_as_required("filename")

def main(argv):
    del argv  # Unused.

    uops = {}

    with open(FLAGS.filename) as fp:
        uops = json.load(fp)

    print("DECODER INFORMATION")
    for uop in uops['uop_decode']:
        print(uop)
    print("END DECODER")

if __name__ == '__main__':
    app.run(main)

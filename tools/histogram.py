# This small tool calculates line lengths of a specified file and prints
# it out to {filename}.histo.{maxline}. Usage:
#
# python histo.py somefile.cc
#
# If the maximum length in somefile.cc is say 92, the histogram
# will be written to somefile.cc.histo.92.
#
# That way this tool can easily be used to generate histograms for large
# number of files. To get the overall data, you can use find command,
# without even looking into the file contents.
#
# If you want to know more about the lengths distribution within a file,
# you need to look inside.
#
# To get a list of all Kea C++ files legths, do this:
#
# find . -name '*.h' -or -name '*.cc' -exec python3 tools/histo.py {} \;


histogram = {}

import sys

if len(sys.argv) !=2:
    print("Exactly one parameter is needed: the file to be processed")
    sys.exit(1)

with open(sys.argv[1], "r") as fp:
    lines = fp.readlines()
    for line in lines:
        l = len(line)
        if l in histogram.keys():
            histogram[l] = histogram[l] + 1
        else:
            histogram[l] = 1

# Now print the output

max = sorted(histogram.keys())[-1]

with open(sys.argv[1] + ".histo." + str(max), "w") as f:
    for k in sorted(histogram.keys()):
        f.write(f"{k},{histogram[k]}\n")

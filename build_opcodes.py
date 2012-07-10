#! /usr/bin/env python

f_in = open("opcodes.txt")
f_h = open("opcodes2.h", "w")
counter = 1


for line in f_in:
    if len(line) > 0:
        if line[0] not in "#;":
            f_h.write("#define OP_")
            f_h.write(line.strip().upper())
            f_h.write(" ")
            f_h.write(str(counter))
            f_h.write("\n")
#! /usr/bin/env python
# coding: utf-8
import struct
from opcodes import Opcodes


class Assembler:

    def __init__(self):
        self.clean()

    def clean(self):
        self.labels = {}
        self.address = 0

    def __call__(self, arg):
        return self.parse(arg)

    def parse_labels(self, asm):
        for i in asm:
            if type(i) == str:
                line = i.strip()
                if line[-1] == ":":
                    self.labels[line[:-1]] = self.address
                elif line[0] == "#":
                    continue
                elif line[:3] == ".b ":
                    self.address += 1
                elif line[:3] == ".s ":
                    self.address += 2
                elif line[:3] == ".i ":
                    self.address += 4
                elif line[:3] == ".l ":
                    self.address += 8
                elif line[:3] == ".a ":
                    self.address += len(line)-2
                elif line[0] == "@":
                    self.address += 4
                elif line.isdigit():
                    self.address += 4
                else:
                    self.address += 1
            else:
                self.address += 4

    def parse(self, asm):
        self.parse_labels(asm)
        try:
            asm.seek(0)
        except:
            pass
        out = []
        for i in asm:
            if type(i) == str:
                line = i.strip()
                if len(line) == 0:
                    break
                if line[0] == '#':
                    continue
                elif line.isdigit():
                    for d in [(int(line) & (0xff << i)) >> i for i in range(0, 25, 8)]:
                        out.append(d)
                    self.address += 4
                elif line[:3] == ".b ":
                    # TODO in range of byte
                    d = int(line[3:])
                    out.append(d)
                    self.address += 1
                elif line[:3] == ".s ":
                    for d in [(int(line[3:]) & (0xff << i)) >> i for i in range(0, 9, 8)]:
                        out.append(d)
                    self.address += 2
                elif line[:3] == ".i ":
                    for d in [(int(line[3:]) & (0xff << i)) >> i for i in range(0, 25, 8)]:
                        out.append(d)
                    self.address += 4
                elif line[:3] == ".l ":
                    # TODO pas sur...
                    for d in [(int(line[3:]) & (0xff << i)) >> i for i in range(0, 57, 8)]:
                        out.append(d)
                    self.address += 8


                elif line[:3] == ".f ":
                    for c in struct.pack("f", float(line[3:])):
                        out.append(ord(c))
                    self.address += 4


                elif line[:3] == ".a ":
                    for c in line[3:]:
                        out.append(ord(c))
                        self.address += 1
                    out.append(0)
                    self.address += 1
                elif line[0] == "@":
                    for d in [(int(self.labels[line[1:]]) & (0xff << i)) >> i for i in range(0, 25, 8)]:
                        out.append(d)
                    self.address += 4
                elif line[-1] != ":":
                    out.append(Opcodes[line])
                    self.address += 1
            else:
                print "WARNING: Not string !!"
                out.append(i)
                self.address += 1
        return out

if __name__ == "__main__":
    import sys
    mode_verbose = False

    if len(sys.argv) == 1:
        fasm = sys.stdin
        fbytecode = sys.stdout
    elif len(sys.argv) == 2:
        if sys.argv[1] == '-':
            fasm = sys.stdin
        else:
            fasm = open(sys.argv[1], "r")
        fbytecode = sys.stdout
    elif len(sys.argv) >= 3:
        if sys.argv[1] == '-':
            fasm = sys.stdin
        else:
            fasm = open(sys.argv[1], "r")
        fbytecode = open(sys.argv[2], "w")

    asmb = Assembler()
    out = asmb([i for i in fasm])
    fasm.close()

    for i in out:
        fbytecode.write(chr(int(i)))

    if mode_verbose:
        print "Labels:"
        for lbl in asmb.labels:
            print lbl, ":", asmb.labels[lbl], "%X" % asmb.labels[lbl]
        print " "

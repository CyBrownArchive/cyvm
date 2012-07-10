import CompilerGlobal
import json
from SymbolTable import SymbolTable
from StatementCompiler import StatementCompiler
from ExpressionCompiler import ExpressionCompiler
from CompilerExceptions import ExpressionException

out = ""
out_func_def = ""
out_constant = []


class StringCollection(object):

    def __init__(self):
        self.strings = []
        self.size = 0

    def append(self, value):
        ret = self.size
        self.strings.append(value)
        self.size += len(value) + 1
        return ret


out_constant = StringCollection()

# MISC FUNCTIONS


def output(line):
    global out
    global out_func_def
    if CompilerGlobal.to_func != 0:
        out_func_def += str(line)
        out_func_def += "\n"
    else:
        out += str(line)
        out += "\n"


def output_constant(value):
    global out_constant
    return out_constant.append(value)


def compile_program(program):
    sc = StatementCompiler()
    sc.output = output
    sc.symt = SymbolTable()

    ec = ExpressionCompiler()
    ec.output = output
    ec.symt = sc.symt
    ec.output_constant = output_constant

    sc.expr_compiler = ec
    for instr in program:
        sc.compile(instr)

# Main program

try:
    f = open("out.json")
    program = json.load(f)
    compile_program(program)
    fout = open("out.asm", "w")
    fout.write("jp\n")
    fout.write("@__main__\n")
    for s in out_constant.strings:
        fout.write(".a ")
        fout.write(s)
        fout.write("\n")
    fout.write(out_func_def)
    fout.write("__main__:\n")
    fout.write(out)
except ExpressionException as e:
    print e.getMsg()
    quit(1)

print "Functions:"
for f in CompilerGlobal.functions:
    o = "  " + f + "(" + CompilerGlobal.functions[f]["data_type"] + ")" + ": "
    if len(CompilerGlobal.functions[f]["signature"].sig) == 0:
        o += "void"
    else:
        for s in CompilerGlobal.functions[f]["signature"].sig:
            o += s + " "
    print o


quit(0)

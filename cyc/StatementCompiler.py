import CompilerGlobal
import SymbolTable


class StatementCompiler(object):

    def __init__(self):
        self.stm_num = 0

    def compile(self, stm):
        self.stm_num += 1
        if stm["type"] == "expr":
            self.compile_stm_expr(stm)
        elif stm["type"] == "compound":
            self.compile_stm_compound(stm)
        elif stm["type"] == "if":
            self.compile_stm_if(stm)
        elif stm["type"] == "switch":
            self.compile_stm_switch(stm)
        elif stm["type"] == "for":
            self.compile_stm_for(stm)
        elif stm["type"] == "while":
            self.compile_stm_while(stm)
        elif stm["type"] == "do":
            self.compile_stm_do(stm)
        elif stm["type"] == "nop":
            self.compile_stm_nop(stm)
        elif stm["type"] == "decl":
            self.compile_stm_decl(stm)
        elif stm["type"] == "return":
            self.compile_stm_return(stm)
        elif stm["type"] == "asm":
            self.compile_stm_asm(stm)
        else:
            print "UNKNOWN_STATEMENT_TYPE: [" + stm["type"] + "]"

    def compile_stm_expr(self, stm):
        self.expr_compiler.compile(stm["value"])

    def compile_stm_compound(self, stm):
        for instr in stm["statements"]:
            self.compile(instr)

    def compile_stm_if(self, stm):
        lbl_end   = "_" + str(self.stm_num) + "_if_end"
        if "if_false" in stm:
            lbl_false = "_" + str(self.stm_num) + "_if_end"
        else:
            lbl_false = lbl_end
        lbl_start = "_" + str(self.stm_num) + "_if_start"
        self.expr_compiler.compile(stm["condition"])
        self.output("jpz")
        self.output("@"+lbl_false)
        self.compile(stm["if_true"])
        self.output("jp")
        self.output("@"+lbl_end)
        if "if_false" in stm:
            self.output(lbl_false+":")
            self.compile(stm["if_false"])
        self.output(lbl_end+":")


    def compile_stm_switch(self, stm):
        print stm

    def compile_stm_for(self, stm):
        lbl_start = "_"+str(self.stm_num)+"_for_start"
        lbl_end = "_"+str(self.stm_num)+"_for_end"
        self.compile(stm["init"])
        self.output(lbl_start+":")
        self.expr_compiler.compile(stm["condition"]["value"])
        self.output("jpz")
        self.output("@"+lbl_end)
        self.compile(stm["body"])
        self.expr_compiler.compile(stm["loop"])
        self.output("jp")
        self.output("@"+lbl_start)
        self.output(lbl_end+":")

    def compile_stm_while(self, stm):
        lbl_start = "_"+str(self.stm_num)+"_while_start"
        lbl_end   = "_"+str(self.stm_num)+"_while_end"
        self.output(lbl_start+":")
        self.expr_compiler.compile(stm["condition"])
        self.output("jpz")
        self.output("@"+lbl_end)
        self.compile(stm["body"])
        self.output("jp")
        self.output("@"+lbl_start)
        self.output(lbl_end+":")

    def compile_stm_do(self, stm):
        lbl_start = "_"+str(self.stm_num)+"_do_start"
        lbl_end   = "_"+str(self.stm_num)+"_do_end"
        self.output(lbl_start+":")
        self.compile(stm["body"])
        self.expr_compiler.compile(stm["condition"])
        self.output("jpz")
        self.output("@"+lbl_end)
        self.output("jp")
        self.output("@"+lbl_start)
        self.output(lbl_end+":")

    def compile_stm_nop(self, stm):
        print stm

    def compile_stm_decl(self, stm):
        # If declaration has a body, its a function, parse it's body and arguments
        if stm["body"] is None:
            self.symt.declare(stm["name"], stm["data_type"])
        else:
            CompilerGlobal.functions[stm["name"]] = {"data_type": stm["data_type"], "body": stm["body"]}
            CompilerGlobal.to_func += 1
            self.symt.push()
            types = []
            for arg in stm["args"]:
                self.symt.declare(arg["name"], arg["type"])
                types.append(arg["type"])
            CompilerGlobal.functions[stm["name"]]["signature"] = SymbolTable.Signature(types)
            self.output("_func_"+stm["name"]+":")
            # Allocating space for pc register
            self.symt.tables[-1]["addr"] += 4
            self.compile(stm["body"])
            self.symt.pop()
            CompilerGlobal.to_func -=1

    def compile_stm_return(self, stm):
        # TODO Verify with declaration return type
        if "return_value" in stm:
            self.expr_compiler.compile(stm["return_value"])
            data_size_on_stack = SymbolTable.DataType.stack_size(SymbolTable.DataType.from_string(stm["return_value"]["data_type"]))
            if data_size_on_stack == 1:
                self.output("b2i")
                self.output("ret1")
            elif data_size_on_stack == 2:
                self.output("s2i")
                self.output("ret1")
            elif data_size_on_stack == 4:
                self.output("ret1")
            elif data_size_on_stack == 8:
                self.output("ret2")
        else:
            self.output("ret")

    def compile_stm_asm(self, stm):
        self.output(stm["assembly"])

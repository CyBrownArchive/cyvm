import CompilerGlobal
import SymbolTable
from CompilerExceptions import ExpressionException


class ExpressionCompiler(object):

    def __init__(self):
        self.expr_num = 0

    def compile(self, expr):
        if expr["type"] == "op1":
            self.compile_expr_op1(expr)
        elif expr["type"] == "op2":
            self.compile_expr_op2(expr)
        elif expr["type"] == "op3":
            self.compile_expr_op3(expr)
        elif expr["type"] == "call":
            self.compile_expr_call(expr)
        elif expr["type"] == "literal":
            self.compile_expr_literal(expr)
        elif expr["type"] == "identifier":
            self.compile_expr_identifier(expr)
        else:
            print "UNKNOWN_EXPR_TYPE: ", expr["type"]

    def compile_expr_op1(self, expr):
        self.compile(expr["expr"])
        expr["data_type"] = self.op1_type(expr["op"], expr["expr"]["data_type"])
        if expr["data_type"] is False:
            raise ExpressionException("Exception:" + str(expr["line"]) + ":" + str(expr["col"]) + " Operator '" + expr["op"] + "' can not use type '" + str(expr["expr"]["data_type"]) + "'")
        self.output(expr["op"])

    def compile_expr_op2(self, expr):
        if "assign" == expr["op"]:
            # Affectation
            if expr["left"]["type"] != "identifier":
                raise "Left hand expression not affectable."
            self.compile(expr["right"])
            self.output(expr["right"]["data_type"][0] + "store")
            self.output(self.symt.address_of(expr["left"]["name"]))
        else:
            # Compute expressions and put results on the stack
            self.compile(expr["left"])
            self.compile(expr["right"])
            # Compute expression data type
            expr["data_type"] = self.op2_type(expr["op"], expr["left"]["data_type"], expr["right"]["data_type"])
            if expr["op"] != "sub":
                t = self.op2_type("sub", expr["left"]["data_type"], expr["right"]["data_type"])
            else:
                t = expr["data_type"]
            if expr["data_type"] is False or t is False:
                raise ExpressionException("Exception:" + str(expr["line"]) + ":" + str(expr["col"]) + " Operator '" + op + "' can not use type '" + str(t1) + "'")
            if expr["op"] in ["add", "sub", "mul", "div"]:
                # ACCEPT: int long float double
                self.output(expr["data_type"][0] + expr["op"])
            elif expr["op"] == "mod":
                # ACCEPT: int long
                self.output(expr["data_type"][0] + expr["op"])
            elif expr["op"] in ["b_and", "b_or", "b_xor"]:
                # ACCEPT: int long
                self.output(expr["data_type"][0] + expr["op"][2:])
            elif expr["op"] == "eq":
                # ACCEPT: int long float double
                self.output(t[0] + "sub")
                # TODO optimize
                # TODO works only with int...
                self.output("i2bool")
                self.output("inot")
                self.output("ipush")
                self.output("1")
                self.output("iand")
            elif expr["op"] == "neq":
                # ACCEPT: int long float double
                self.output(t[0] + "sub")
            elif expr["op"] == "lt":
                # ACCEPT: int long float double
                self.output(t[0] + "sub")
                self.output(t[0] + "isneg")
            elif expr["op"] == "lte":
                # ACCEPT: int long float double
                self.output(t[0] + "sub")
                self.output(t[0] + "iszneg")
            elif expr["op"] == "gt":
                # ACCEPT: int long float double
                self.output(t[0] + "sub")
                self.output(t[0] + "ispos")
            elif expr["op"] == "gte":
                # ACCEPT: int long float double
                self.output(t[0] + "sub")
                self.output(t[0] + "iszpos")
            else:
                raise "UNKNOWN op2 operator."

    def compile_expr_op3(self, expr):
        lbl_false = "_" + str(self.expr_num) + "_op3_false"
        lbl_end = "_" + str(self.expr_num) + "_op3_end"
        self.compile(expr["condition"])
        self.output("jpz")
        self.output("@" + lbl_false)
        self.compile(expr["if_true"])
        self.output("jp")
        self.output("@" + lbl_end)
        self.output(lbl_false + ":")
        self.compile(expr["if_false"])
        if (expr["if_true"]["data_type"] != expr["if_false"]["data_type"]):
            pass
            # TYPE EXCEPTION
        self.output(lbl_end + ":")
        expr["data_type"] = expr["if_true"]["data_type"]

    def compile_expr_call(self, expr):
        self.output("prepcall")
        stack_offset = 4
        types = []
        #Add size of value to stack
        for o in expr["args"]:
            self.compile(o)
            stack_offset += SymbolTable.SymbolTable.sizeof_type(o["data_type"])
            types.append(o["data_type"])
        # Verify if signature matches function definitions signature
        if not CompilerGlobal.functions[expr["caller"]["name"]]["signature"].match(types):
            raise Exception("Wrong signature.")
        # Add arguments, fp and old pc on the stack
        self.symt.tables[-1]["addr"] = stack_offset
        expr["data_type"] = CompilerGlobal.functions[expr["caller"]["name"]]["data_type"]
        self.output("call")
        self.output("@_func_" + expr["caller"]["name"])

    def compile_expr_literal(self, expr):
        if expr["data_type"] in ["byte", "short", "int", "long", "float", "double"]:
            self.output(expr["data_type"][0] + "push")
            self.output("." + expr["data_type"][0] + " " + str(expr["value"]))
        elif expr["data_type"] == "string":
            offset = self.output_constant(expr["value"])

    def compile_expr_identifier(self, expr):
        try:
            expr["data_type"] = self.symt.type_of(expr["name"])
            # TODO Verify type is a value and not function / class
            if self.symt.is_local(expr["name"]):
                self.output(expr["data_type"][0] + "loadfp")
            else:
                self.output(expr["data_type"][0] + "load")
            self.output(self.symt.address_of(expr["name"]))
        except:
            pass
            # var does not exists

    # return true if node is type byte, short, int or long
    @classmethod
    def is_type_integer(cls, t):
        return t in ["byte", "short", "int", "long"]

    # return true if node is type float or double
    @classmethod
    def is_type_float(cls, t):
        return t in ["float", "double"]

    # for promotion type calculation, return the greatest type
    # return false on incompatible types
    @classmethod
    def type_greater(cls, t1, t2):
        if (cls.is_type_integer(t1) and cls.is_type_integer(t2)):
            if ((t1 == "long") or (t2 == "long")):
                return "long"
            elif ((t1 == "int") or (t2 == "int")):
                return "int"
            elif ((t1 == "short") or (t2 == "short")):
                return "short"
            return "byte"
        elif (cls.is_type_float(t1) and cls.is_type_float(t2)):
            if (t1 == "float") and (t2 == "float"):
                return "float"
            return "double"
        return False

    # Compute the type of a op2 expression node
    # return false if operator is not defined for those types
    @classmethod
    def op2_type(cls, op, t1, t2):
        if op in ["lt", "lte", "gt", "gte"]:
            if (not((t1 == "bool") or (t2 == "bool"))):
                return "bool"
        elif op in ["eq", "neq"]:
            if (((t1 == "bool") and (t2 == "bool")) or (cls.is_type_integer(t1) and cls.is_type_integer(t2)) or (cls.is_type_float(t1) and cls.is_type_float(t2))):
                return "bool"
        elif op in ["add", "sub", "mul", "div", "mod"]:
            if not((cls.is_type_float(t1) or cls.is_type_float(t2)) and op == "mod"):
                t = cls.type_greater(t1, t2)
                if t is not False:
                    return t
        elif op in ["b_and", "b_xor", "b_or", "left", "right"]:
            if (cls.is_type_integer(t1) and cls.is_type_integer(t2)):
                t = cls.type_greater(t1, t2)
                if t is not False:
                    return t
            elif ((t1 == "bool") and (t2 == "bool")):
                return "bool"
        elif op in ["or", "and"]:
            if ((t1 == "bool") and (t2 == "bool")):
                return "bool"
        return False

    # Return type of unary expression
    # return false if not defined
    @classmethod
    def op1_type(cls, op, t1):
        if ((op == "not") and (t1 == "bool")):
            return "bool"
        if ((op == "b_not") and cls.is_type_integer(t1)):
            return t1
        if op in ["pre_inc", "pre_dec", "pos", "neg", "post_inc", "post_dec"]:
            if (cls.is_type_float(t1) or cls.is_type_integer(t1)):
                return t1
        return False

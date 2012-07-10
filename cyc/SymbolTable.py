import CompilerGlobal



class Signature(object):

    def __init__(self, arr = []):
        self.sig = arr

    def match(self, arg):
        mx = max(len(self.sig), len(arg))
        for i in xrange(mx):
            if arg[i] != self.sig[i]:
                return False
        return True


class DataType(object):

    OBJECT = 0
    BYTE   = 1
    SHORT  = 2
    INT    = 3
    LONG   = 4
    FLOAT  = 5
    DOUBLE = 6

    def __init__(self):
        self.array_dim = []             # Dimensions of array, [] if not an array
        self.data_type = self.OBJECT    # Type of final variable, even if array
        self.class_def = None           # Link to class definition if object
        self.args = []                  # Links to template types

    def is_object(self):
        return self.data_type == self.OBJECT

    def is_array(self):
        return self.array_dim == 0

    @classmethod
    def stack_size(cls, _type):
        if _type == cls.OBJECT:
            return 4
        if _type == cls.BYTE:
            return 1
        if _type == cls.SHORT:
            return 2
        if _type == cls.INT:
            return 4
        if _type == cls.LONG:
            return 8
        if _type == cls.FLOAT:
            return 4
        if _type == cls.DOUBLE:
            return 8

    @classmethod
    def from_string(cls, s):
        # Convert string to constant
        if s == "byte":
            return cls.BYTE
        if s == "short":
            return cls.SHORT
        if s == "int":
            return cls.INT
        if s == "long":
            return cls.LONG
        if s == "float":
            return cls.FLOAT
        if s == "double":
            return cls.DOUBLE
        return cls.OBJECT


class FunctionArgument(object):

    def __init_(self):
        self.data_type = DataType()
        self.name = ""
        self.optional = False



class FunctionDefinition(object):

    def __init__(self):
        self.return_type = DataType()
        self.arguments = {}
        self.body = None



class ClassDefinition(object):

    def __init__(self):
        self.attributes = {}
        self.methods = {}



class Variable(object):

    def __init__(self, name, data_type):
        self.name = name
        self.data_type = data_type



class SymbolTable(object):

    @staticmethod
    def sizeof_type(t):
        if t == "byte":
            return 1
        if t == "short":
            return 2
        if t == "int" or t == "float":
            return 4
        if t == "long" or t == "double":
            return 8

    def __init__(self):
        self.tables = []
        self.tables.append({"vars": {}, "addr": 0})

    def push(self):
        # Append a symbol table
        self.tables.append({"vars": {}, "addr": 4})

    def pop(self):
        # Pop the last symbol table
        self.tables.pop()

    def declare(self, name, data_type):
        # Declare a new var in the current symbol table
        self.tables[-1]["vars"][name] = {"type": "val",
                                         "data_type" : data_type,
                                         "addr" : self.tables[-1]["addr"]}
        self.tables[-1]["addr"] += self.sizeof_type(data_type)

    def address_of(self, name):
        # Get relative address of var in all symbol tables
        res = None
        i = len(self.tables) - 1
        while i >= 0:
            try:
                res = self.tables[i]["vars"][name]
                break
            except KeyError:
                pass
            i -= 1
        return res["addr"]

    def type_of(self, name):
        # Get relative address of var in all symbol tables
        res = None
        i = len(self.tables) - 1
        while i >= 0:
            try:
                res = self.tables[i]["vars"][name]
                break
            except KeyError:
                pass
            i -= 1
        if res is None:
            raise Exception("Exception: " + name + " unknown symbol.")
        return res["data_type"]

    def is_local(self, name):
        # Get relative address of var in all symbol tables
        if len(self.tables) == 1:
            return False
        try:
            res = self.tables[len(self.tables)-1]["vars"][name]
            return True
        except KeyError:
            pass
        return False

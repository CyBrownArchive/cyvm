class ExpressionException(Exception):

    def __init__(self, msg):
        self.msg = msg

    def getMsg(self):
        return self.msg

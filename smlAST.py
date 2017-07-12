from antlr4 import *
from io import StringIO
from typing.io import TextIO
from smlParser import smlParser as sp
from smlLexer import smlLexer as sl
import sys

off = 4

class ASTnode:
    def __init__(self):
        self.children = []

    def addChild(self, child):
        if child != None:
            self.children.append(child)

    def printNumChild():
        print(len(children))

class CommSeq(ASTnode):
    def __init__(self):
        super(CommSeq, self).__init__()

    def visit(self, offset):
        print(" "*offset, "CommSeq:")
        for com in self.children:
            com.visit(offset+off)

class Block(ASTnode):
    def __init__(self):
        super(Block, self).__init__()

    def visit(self, offset):
        print(" "*offset, "Block:")
        for bcom in self.children:
            bcom.visit(offset+off)

class Decl(ASTnode):
    def __init__(self, data_type, idname):
        self.data_type = data_type
        self.idname = idname
        self.arity = 2

    def visit(self, offset):
        print(" "*offset, "Decl:")
        self.data_type.visit(offset+off)
        self.idname.visit(offset+off)

class IdentType(ASTnode):
    def __init__(self, idtype):
        self.idtype = idtype
        self.arity = 0

    def visit(self, offset):
        print(" "*offset, "IdentType:", self.idtype)

class Ident(ASTnode):
    def __init__(self, name):
        self.name = name
        self.arity = 0

    def visit(self, offset):
        print(" "*offset, "Ident:", self.name)

class Assign(ASTnode):
    def __init__(self, lhs, rhs):
        self.lhs = lhs
        self.rhs = rhs
        self.arity = 2

    def visit(self, offset):
        print(" "*offset, "Assign:")
        self.lhs.visit(offset+off)
        self.rhs.visit(offset+off)

class For(ASTnode):
    def __init__(self, idname, start, end, step):
        self.idname = idname
        self.start = start
        self.end = end
        self.step = step
        self.arity = 4

    def visit(self, offset):
        print(" "*offset, "For:")
        idname.visit(offset+off)
        start.visit(offset+off)
        end.visit(offset+off)
        step.visit(offset+off)

class BinOp(ASTnode):
    def __init__(self, lhs, op, optype, rhs):
        self.lhs = lhs
        self.op = op
        self.optype = optype
        self.rhs = rhs
        self.arity = 2

    def visit(self, offset):
        print(" "*offset, "BinOp:", self.op)
        self.lhs.visit(offset+off)
        self.rhs.visit(offset+off)

class UnOp(ASTnode):
    def __init__(self, optype, op, expr):
        self.optype = optype
        self.op = op
        self.expr = expr
        self.arity = 1

    def visit(self, offset):
        print(" "*offset, "UnOp:", self.op)
        self.expr.visit(offset+off)

class RelOp(ASTnode):
    def __init__(self, op, lhs, rhs):
        self.lhs = lhs
        self.op = op
        self.rhs = rhs
        self.arity = 2

    def visit(self, offset):
        print(" "*offset, "RelOp:", self.op)
        self.lhs.visit(offset+off)
        self.rhs.visit(offset+off)

class Constant(ASTnode):
    def __init__(self, idtype, value):
        self.idtype = idtype
        self.value = value
        self.arity = 0

    def visit(self, offset):
        print(" "*offset, "Constant:", self.idtype, self.value)

class CondExpr(ASTnode):
    def __init__(self, condition, expr1, expr2):
        self.condition = condition
        self.expr1 = expr1
        self.expr2 = expr2
        self.arity = 3

    def visit(self, offset):
        print(" "*offset, "CondExpr:")
        self.condition.visit(offset+off)
        self.expr1.visit(offset+off)
        self.expr2.visit(offset+off)

class InpExpr(ASTnode):
    def __init__(self, partynum, expr, exprText):
        self.partynum = partynum
        self.expr = expr
        self.exprText = exprText
        self.arity = 1

    def visit(self, offset):
        print(" "*offset, "InpExpr:", self.partynum)
        self.expr.visit(offset+off)

class OutExpr(ASTnode):
    def __init__(self, expr):
        self.expr = expr
        self.arity = 1

    def visit(self, offset):
        print(" "*offset, "OutExpr:")
        self.expr.visit(offset+off)

def getAST(rule):
    if isinstance(rule, sp.CommandSeqContext): # commandSeq
        node = CommSeq()
        for com in rule.getChildren():
            node.addChild(getAST(com))
        return node

    elif isinstance(rule, sp.BlockContext): # block
        node = Block()
        n = rule.getChildCount()
        for i in range(1,n-1):
            node.addChild(getAST(rule.getChild(i)))
        return node

    elif isinstance(rule, sp.CommandContext): # command
        return getAST(rule.getChild(0))

    elif isinstance(rule, sp.BlockCommContext): # blockComm
        return getAST(rule.getChild(0))

    elif isinstance(rule, sp.DeclarationContext): # declaration
        if rule.getText() != ';':
            return Decl(getAST(rule.getChild(0)), Ident(rule.getChild(1).getText()))
        else:
            return None

    elif isinstance(rule, sp.VarTypeContext): # varType
        return IdentType(rule.getText())

    elif isinstance(rule, sp.AssignmentContext): # assignment
        return Assign(Ident(rule.getChild(0).getText()), getAST(rule.getChild(2)))

    elif isinstance(rule, sp.OutputContext): # output
        return OutExpr(getAST(rule.getChild(2)))

    elif isinstance(rule, sp.ExprContext): # expr
        return getAST(rule.getChild(0))

    elif isinstance(rule, sp.ArithExprContext): # arithExpr
        if rule.getChildCount() == 1: # Constant or Ident
            if rule.getChild(0).symbol.type == sp.IntegerConstant:
                return Constant('uint64_t', rule.getText()) # convert to int or not?
            else: # - Ident
                return Ident(rule.getText())

        elif rule.getChildCount() == 2: # UnaryOp=- arithExpr 
            return UnOp('uint64_t', rule.getChild(0).getText(),
                        getAST(rule.getChild(1)))

        else:
            if rule.getChild(0).getText() == '(': # ( arithExpr )
                return getAST(rule.getChild(1))
            else: # arithExpr BinOp arithExpr
                return BinOp(getAST(rule.getChild(0)), rule.getChild(1).getText(),
                        'uint64_t', getAST(rule.getChild(2)))

    elif isinstance(rule, sp.ConditionalExprContext): # conditionalExpr
        return CondExpr(getAST(rule.getChild(0)), getAST(rule.getChild(2)),
                        getAST(rule.getChild(4)))

    elif isinstance(rule, sp.BoolExprContext): # boolExpr
        if rule.getChildCount() == 1: # Constant or Ident
            if rule.getChild(0).symbol.type == sp.BoolConstant:
                return Constant('bool', rule.getText())
            else: # - Ident
                return Ident(rule.getText())

        elif rule.getChildCount() == 2: # UnaryOp=! boolExpr 
            return UnOp('bool', rule.getChild(0).getText(),
                        getAST(rule.getChild(1)))

        else:
            if rule.getChild(0).getText() == '(': # ( boolExpr )
                return getAST(rule.getChild(1))
            else: # boolExpr BinOp boolExpr
                return BinOp(getAST(rule.getChild(0)), rule.getChild(1).getText(),
                        'bool', getAST(rule.getChild(2)))

    elif isinstance(rule, sp.InputExprContext): # inputExpr
        return InpExpr(rule.getChild(0).getText(), getAST(rule.getChild(2)), 
                        rule.getChild(2).getText())

    else:
        print("I'm not supposed to be here")
        
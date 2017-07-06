from antlr4 import *
from io import StringIO
from typing.io import TextIO
from smlParser import smlParser as sp
import sys

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

class Decl(ASTnode):
    def __init__(self, data_type, idname):
        self.data_type = data_type
        self.idname = idname
        self.arity = 2


class IdentType(ASTnode):
    def __init__(self, idtype):
        self.idtype = idtype
        self.arity = 0

class Ident(ASTnode):
    def __init__(self, name):
        self.name = name
        self.arity = 0

class Assign(ASTnode):
    def __init__(self, lvalue, rvalue):
        self.lvalue = lvalue
        self.rvalue = rvalue
        self.arity = 2

class BinOp(ASTnode):
    def __init__(self, lhs, op, rhs):
        self.lhs = lhs
        self.op = op
        self.rhs = rhs
        self.arity = 2

class UnOp(ASTnode):
    def __init__(self, idtype, op, expr):
        self.idtype = idtype
        self.op = op
        self.expr = expr
        self.arity = 1

class RelOp(ASTnode):
    def __init__(self, op, lhs, rhs):
        self.lhs = lhs
        self.op = op
        self.rhs = rhs
        self.arity = 2

class Constant(ASTnode):
    def __init__(self, idtype, value):
        self.idtype = idtype
        self.value = value
        self.arity = 0

class CondExpr(ASTnode):
    def __init__(self, condition, expr1, expr2):
        self.condition = condition
        self.expr1 = expr1
        self.expr2 = expr2
        self.arity = 3

class InpExpr(ASTnode):
    def __init__(self, partynum, expr):
        self.partynum = partynum
        self.expr = expr
        self.arity = 1

class OutExpr(ASTnode):
    def __init__(self, expr):
        self.expr = expr
        self.arity = 1

def getAST(rule):
    if isinstance(rule, sp.CommandSeqContext): # commandSeq
        node = CommSeq()
        for com in rule.getChildren():
            node.addChild(getAST(com))
        return node

    elif isinstance(rule, sp.CommandContext): # command
        if rule.getChild(0).getText() != '{':
            return getAST(rule.getChild(0))
        else:
            return getAST(rule.getChild(1))

    elif isinstance(rule, sp.DeclarationContext): # declaration
        if rule.getText() != ';':
            return Decl(getAST(rule.getChild(0)), Ident(rule.getChild(1).getText()))
        else:
            return None

    elif isinstance(rule, sp.AssignmentContext): # assignment
        return Assign(Ident(rule.getChild(0).getText()), getAST(rule.getChild(2)))

    elif isinstance(rule, sp.VarTypeContext): # varType
        return IdentType(rule.getText())

    elif isinstance(rule, sp.OutputContext): # output
        return OutExpr(getAST(rule.getChild(2)))

    elif isinstance(rule, sp.ExprContext): # expr
        if rule.getChild(0).getText() != '(':
            return getAST(rule.getChild(0))
        else:
            return getAST(rule.getChild(1))

    elif isinstance(rule, sp.ArithExprContext): # arithExpr
        if rule.getChild(0).getText() != '-': # not unary op
            if rule.getChildCount() == 3:
                if isinstance(rule.getChild(1), sp.ArithExprContext): # ( arithExpr )
                    return getAST(rule.getChild(1))
                else:   # arithExpr BinOp arithExpr
                    return BinOp(getAST(rule.getChild(0)), rule.getChild(1).getText(),
                                getAST(rule.getChild(2)))
            else: # Constant
                if getSymbolicName(rule.getChild(0).getType()) == 'Constant':
                    return Constant('uint64_t', rule.getText())
                else: # Ident
                    return Ident(rule.getText())
        else:
            if rule.getChildCount() == 4:
                if isinstance(rule.getChild(1), sp.ArithExprContext): # - ( arithExpr )
                    return UnOp('uint64_t', rule.getChild(0).getText(), 
                                getAST(rule.getChild(2)))
            else: # - Constant
                if getSymbolicName(rule.getChild(1).getType()) == 'Constant':
                    return Constant('uint64_t', rule.getText())
                else: # - Ident
                    return Ident(rule.getText())

    else:
        pass

# prog = CommSeq()
# idtype = IdentType("uint64_t")
# name = Ident("x")
# prog.addChild(Decl(idtype,name))
        
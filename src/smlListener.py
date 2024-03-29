# Generated from sml.g4 by ANTLR 4.7
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .smlParser import smlParser
else:
    from smlParser import smlParser

# This class defines a complete listener for a parse tree produced by smlParser.
class smlListener(ParseTreeListener):

    # Enter a parse tree produced by smlParser#commandSeq.
    def enterCommandSeq(self, ctx:smlParser.CommandSeqContext):
        pass

    # Exit a parse tree produced by smlParser#commandSeq.
    def exitCommandSeq(self, ctx:smlParser.CommandSeqContext):
        pass


    # Enter a parse tree produced by smlParser#command.
    def enterCommand(self, ctx:smlParser.CommandContext):
        pass

    # Exit a parse tree produced by smlParser#command.
    def exitCommand(self, ctx:smlParser.CommandContext):
        pass


    # Enter a parse tree produced by smlParser#block.
    def enterBlock(self, ctx:smlParser.BlockContext):
        pass

    # Exit a parse tree produced by smlParser#block.
    def exitBlock(self, ctx:smlParser.BlockContext):
        pass


    # Enter a parse tree produced by smlParser#blockComm.
    def enterBlockComm(self, ctx:smlParser.BlockCommContext):
        pass

    # Exit a parse tree produced by smlParser#blockComm.
    def exitBlockComm(self, ctx:smlParser.BlockCommContext):
        pass


    # Enter a parse tree produced by smlParser#declaration.
    def enterDeclaration(self, ctx:smlParser.DeclarationContext):
        pass

    # Exit a parse tree produced by smlParser#declaration.
    def exitDeclaration(self, ctx:smlParser.DeclarationContext):
        pass


    # Enter a parse tree produced by smlParser#varType.
    def enterVarType(self, ctx:smlParser.VarTypeContext):
        pass

    # Exit a parse tree produced by smlParser#varType.
    def exitVarType(self, ctx:smlParser.VarTypeContext):
        pass


    # Enter a parse tree produced by smlParser#assignment.
    def enterAssignment(self, ctx:smlParser.AssignmentContext):
        pass

    # Exit a parse tree produced by smlParser#assignment.
    def exitAssignment(self, ctx:smlParser.AssignmentContext):
        pass


    # Enter a parse tree produced by smlParser#arrDecl.
    def enterArrDecl(self, ctx:smlParser.ArrDeclContext):
        pass

    # Exit a parse tree produced by smlParser#arrDecl.
    def exitArrDecl(self, ctx:smlParser.ArrDeclContext):
        pass


    # Enter a parse tree produced by smlParser#intRef.
    def enterIntRef(self, ctx:smlParser.IntRefContext):
        pass

    # Exit a parse tree produced by smlParser#intRef.
    def exitIntRef(self, ctx:smlParser.IntRefContext):
        pass


    # Enter a parse tree produced by smlParser#arrExpr.
    def enterArrExpr(self, ctx:smlParser.ArrExprContext):
        pass

    # Exit a parse tree produced by smlParser#arrExpr.
    def exitArrExpr(self, ctx:smlParser.ArrExprContext):
        pass


    # Enter a parse tree produced by smlParser#intIdRef.
    def enterIntIdRef(self, ctx:smlParser.IntIdRefContext):
        pass

    # Exit a parse tree produced by smlParser#intIdRef.
    def exitIntIdRef(self, ctx:smlParser.IntIdRefContext):
        pass


    # Enter a parse tree produced by smlParser#forLoop.
    def enterForLoop(self, ctx:smlParser.ForLoopContext):
        pass

    # Exit a parse tree produced by smlParser#forLoop.
    def exitForLoop(self, ctx:smlParser.ForLoopContext):
        pass


    # Enter a parse tree produced by smlParser#rangeList.
    def enterRangeList(self, ctx:smlParser.RangeListContext):
        pass

    # Exit a parse tree produced by smlParser#rangeList.
    def exitRangeList(self, ctx:smlParser.RangeListContext):
        pass


    # Enter a parse tree produced by smlParser#ifElse.
    def enterIfElse(self, ctx:smlParser.IfElseContext):
        pass

    # Exit a parse tree produced by smlParser#ifElse.
    def exitIfElse(self, ctx:smlParser.IfElseContext):
        pass


    # Enter a parse tree produced by smlParser#expr.
    def enterExpr(self, ctx:smlParser.ExprContext):
        pass

    # Exit a parse tree produced by smlParser#expr.
    def exitExpr(self, ctx:smlParser.ExprContext):
        pass


    # Enter a parse tree produced by smlParser#arithExpr.
    def enterArithExpr(self, ctx:smlParser.ArithExprContext):
        pass

    # Exit a parse tree produced by smlParser#arithExpr.
    def exitArithExpr(self, ctx:smlParser.ArithExprContext):
        pass


    # Enter a parse tree produced by smlParser#conditionalExpr.
    def enterConditionalExpr(self, ctx:smlParser.ConditionalExprContext):
        pass

    # Exit a parse tree produced by smlParser#conditionalExpr.
    def exitConditionalExpr(self, ctx:smlParser.ConditionalExprContext):
        pass


    # Enter a parse tree produced by smlParser#boolExpr.
    def enterBoolExpr(self, ctx:smlParser.BoolExprContext):
        pass

    # Exit a parse tree produced by smlParser#boolExpr.
    def exitBoolExpr(self, ctx:smlParser.BoolExprContext):
        pass


    # Enter a parse tree produced by smlParser#inputExpr.
    def enterInputExpr(self, ctx:smlParser.InputExprContext):
        pass

    # Exit a parse tree produced by smlParser#inputExpr.
    def exitInputExpr(self, ctx:smlParser.InputExprContext):
        pass


    # Enter a parse tree produced by smlParser#output.
    def enterOutput(self, ctx:smlParser.OutputContext):
        pass

    # Exit a parse tree produced by smlParser#output.
    def exitOutput(self, ctx:smlParser.OutputContext):
        pass



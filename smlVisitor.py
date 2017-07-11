# Generated from sml.g4 by ANTLR 4.7
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .smlParser import smlParser
else:
    from smlParser import smlParser

# This class defines a complete generic visitor for a parse tree produced by smlParser.

class smlVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by smlParser#commandSeq.
    def visitCommandSeq(self, ctx:smlParser.CommandSeqContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#command.
    def visitCommand(self, ctx:smlParser.CommandContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#block.
    def visitBlock(self, ctx:smlParser.BlockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#blockComm.
    def visitBlockComm(self, ctx:smlParser.BlockCommContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#declaration.
    def visitDeclaration(self, ctx:smlParser.DeclarationContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#varType.
    def visitVarType(self, ctx:smlParser.VarTypeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#assignment.
    def visitAssignment(self, ctx:smlParser.AssignmentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#forLoop.
    def visitForLoop(self, ctx:smlParser.ForLoopContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#rangeList.
    def visitRangeList(self, ctx:smlParser.RangeListContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#expr.
    def visitExpr(self, ctx:smlParser.ExprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#arithExpr.
    def visitArithExpr(self, ctx:smlParser.ArithExprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#conditionalExpr.
    def visitConditionalExpr(self, ctx:smlParser.ConditionalExprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#boolExpr.
    def visitBoolExpr(self, ctx:smlParser.BoolExprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#inputExpr.
    def visitInputExpr(self, ctx:smlParser.InputExprContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by smlParser#output.
    def visitOutput(self, ctx:smlParser.OutputContext):
        return self.visitChildren(ctx)



del smlParser
# Generated from sml.g4 by ANTLR 4.7
# encoding: utf-8
from antlr4 import *
from io import StringIO
from typing.io import TextIO
import sys

def serializedATN():
    with StringIO() as buf:
        buf.write("\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\25")
        buf.write("m\4\2\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b")
        buf.write("\t\b\4\t\t\t\4\n\t\n\3\2\7\2\26\n\2\f\2\16\2\31\13\2\3")
        buf.write("\3\3\3\3\3\3\3\3\3\3\3\5\3!\n\3\3\4\3\4\3\4\5\4&\n\4\3")
        buf.write("\4\3\4\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7")
        buf.write("\3\7\3\7\5\78\n\7\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b")
        buf.write("\5\bC\n\b\3\b\3\b\3\b\7\bH\n\b\f\b\16\bK\13\b\3\t\3\t")
        buf.write("\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\5\tZ\n\t")
        buf.write("\3\t\3\t\3\t\3\t\3\t\3\t\7\tb\n\t\f\t\16\te\13\t\3\n\3")
        buf.write("\n\3\n\3\n\3\n\3\n\3\n\2\4\16\20\13\2\4\6\b\n\f\16\20")
        buf.write("\22\2\3\3\2\6\7\2t\2\27\3\2\2\2\4 \3\2\2\2\6%\3\2\2\2")
        buf.write("\b)\3\2\2\2\n+\3\2\2\2\f\67\3\2\2\2\16B\3\2\2\2\20Y\3")
        buf.write("\2\2\2\22f\3\2\2\2\24\26\5\4\3\2\25\24\3\2\2\2\26\31\3")
        buf.write("\2\2\2\27\25\3\2\2\2\27\30\3\2\2\2\30\3\3\2\2\2\31\27")
        buf.write("\3\2\2\2\32!\5\6\4\2\33!\5\n\6\2\34\35\7\3\2\2\35\36\5")
        buf.write("\2\2\2\36\37\7\4\2\2\37!\3\2\2\2 \32\3\2\2\2 \33\3\2\2")
        buf.write("\2 \34\3\2\2\2!\5\3\2\2\2\"#\5\b\5\2#$\7\23\2\2$&\3\2")
        buf.write("\2\2%\"\3\2\2\2%&\3\2\2\2&\'\3\2\2\2\'(\7\5\2\2(\7\3\2")
        buf.write("\2\2)*\t\2\2\2*\t\3\2\2\2+,\7\23\2\2,-\7\b\2\2-.\5\f\7")
        buf.write("\2./\7\5\2\2/\13\3\2\2\2\608\5\16\b\2\618\5\20\t\2\62")
        buf.write("8\5\22\n\2\63\64\7\t\2\2\64\65\5\f\7\2\65\66\7\n\2\2\66")
        buf.write("8\3\2\2\2\67\60\3\2\2\2\67\61\3\2\2\2\67\62\3\2\2\2\67")
        buf.write("\63\3\2\2\28\r\3\2\2\29:\b\b\1\2:C\7\24\2\2;C\7\23\2\2")
        buf.write("<=\7\21\2\2=C\5\16\b\4>?\7\t\2\2?@\5\16\b\2@A\7\n\2\2")
        buf.write("AC\3\2\2\2B9\3\2\2\2B;\3\2\2\2B<\3\2\2\2B>\3\2\2\2CI\3")
        buf.write("\2\2\2DE\f\5\2\2EF\7\20\2\2FH\5\16\b\6GD\3\2\2\2HK\3\2")
        buf.write("\2\2IG\3\2\2\2IJ\3\2\2\2J\17\3\2\2\2KI\3\2\2\2LM\b\t\1")
        buf.write("\2MZ\7\23\2\2NZ\7\24\2\2OP\5\16\b\2PQ\7\22\2\2QR\5\16")
        buf.write("\b\2RZ\3\2\2\2ST\7\13\2\2TZ\5\20\t\6UV\7\t\2\2VW\5\20")
        buf.write("\t\2WX\7\n\2\2XZ\3\2\2\2YL\3\2\2\2YN\3\2\2\2YO\3\2\2\2")
        buf.write("YS\3\2\2\2YU\3\2\2\2Zc\3\2\2\2[\\\f\5\2\2\\]\7\f\2\2]")
        buf.write("b\5\20\t\6^_\f\4\2\2_`\7\r\2\2`b\5\20\t\5a[\3\2\2\2a^")
        buf.write("\3\2\2\2be\3\2\2\2ca\3\2\2\2cd\3\2\2\2d\21\3\2\2\2ec\3")
        buf.write("\2\2\2fg\5\20\t\2gh\7\16\2\2hi\5\f\7\2ij\7\17\2\2jk\5")
        buf.write("\f\7\2k\23\3\2\2\2\13\27 %\67BIYac")
        return buf.getvalue()


class smlParser ( Parser ):

    grammarFileName = "sml.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "'{'", "'}'", "';'", "'uint64_t'", "'bool'", 
                     "'='", "'('", "')'", "'!'", "'&'", "'|'", "'?'", "':'" ]

    symbolicNames = [ "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "BinaryOp", "UnaryOp", "RelationalOp", 
                      "Ident", "Constant", "WS" ]

    RULE_commandSeq = 0
    RULE_command = 1
    RULE_declaration = 2
    RULE_varType = 3
    RULE_assignment = 4
    RULE_expr = 5
    RULE_arithExpr = 6
    RULE_boolExpr = 7
    RULE_conditionalExpr = 8

    ruleNames =  [ "commandSeq", "command", "declaration", "varType", "assignment", 
                   "expr", "arithExpr", "boolExpr", "conditionalExpr" ]

    EOF = Token.EOF
    T__0=1
    T__1=2
    T__2=3
    T__3=4
    T__4=5
    T__5=6
    T__6=7
    T__7=8
    T__8=9
    T__9=10
    T__10=11
    T__11=12
    T__12=13
    BinaryOp=14
    UnaryOp=15
    RelationalOp=16
    Ident=17
    Constant=18
    WS=19

    def __init__(self, input:TokenStream, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.7")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None



    class CommandSeqContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def command(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(smlParser.CommandContext)
            else:
                return self.getTypedRuleContext(smlParser.CommandContext,i)


        def getRuleIndex(self):
            return smlParser.RULE_commandSeq

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterCommandSeq" ):
                listener.enterCommandSeq(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitCommandSeq" ):
                listener.exitCommandSeq(self)




    def commandSeq(self):

        localctx = smlParser.CommandSeqContext(self, self._ctx, self.state)
        self.enterRule(localctx, 0, self.RULE_commandSeq)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 21
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            while (((_la) & ~0x3f) == 0 and ((1 << _la) & ((1 << smlParser.T__0) | (1 << smlParser.T__2) | (1 << smlParser.T__3) | (1 << smlParser.T__4) | (1 << smlParser.Ident))) != 0):
                self.state = 18
                self.command()
                self.state = 23
                self._errHandler.sync(self)
                _la = self._input.LA(1)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class CommandContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def declaration(self):
            return self.getTypedRuleContext(smlParser.DeclarationContext,0)


        def assignment(self):
            return self.getTypedRuleContext(smlParser.AssignmentContext,0)


        def commandSeq(self):
            return self.getTypedRuleContext(smlParser.CommandSeqContext,0)


        def getRuleIndex(self):
            return smlParser.RULE_command

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterCommand" ):
                listener.enterCommand(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitCommand" ):
                listener.exitCommand(self)




    def command(self):

        localctx = smlParser.CommandContext(self, self._ctx, self.state)
        self.enterRule(localctx, 2, self.RULE_command)
        try:
            self.state = 30
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [smlParser.T__2, smlParser.T__3, smlParser.T__4]:
                self.enterOuterAlt(localctx, 1)
                self.state = 24
                self.declaration()
                pass
            elif token in [smlParser.Ident]:
                self.enterOuterAlt(localctx, 2)
                self.state = 25
                self.assignment()
                pass
            elif token in [smlParser.T__0]:
                self.enterOuterAlt(localctx, 3)
                self.state = 26
                self.match(smlParser.T__0)
                self.state = 27
                self.commandSeq()
                self.state = 28
                self.match(smlParser.T__1)
                pass
            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class DeclarationContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def varType(self):
            return self.getTypedRuleContext(smlParser.VarTypeContext,0)


        def Ident(self):
            return self.getToken(smlParser.Ident, 0)

        def getRuleIndex(self):
            return smlParser.RULE_declaration

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterDeclaration" ):
                listener.enterDeclaration(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitDeclaration" ):
                listener.exitDeclaration(self)




    def declaration(self):

        localctx = smlParser.DeclarationContext(self, self._ctx, self.state)
        self.enterRule(localctx, 4, self.RULE_declaration)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 35
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            if _la==smlParser.T__3 or _la==smlParser.T__4:
                self.state = 32
                self.varType()
                self.state = 33
                self.match(smlParser.Ident)


            self.state = 37
            self.match(smlParser.T__2)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class VarTypeContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return smlParser.RULE_varType

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterVarType" ):
                listener.enterVarType(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitVarType" ):
                listener.exitVarType(self)




    def varType(self):

        localctx = smlParser.VarTypeContext(self, self._ctx, self.state)
        self.enterRule(localctx, 6, self.RULE_varType)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 39
            _la = self._input.LA(1)
            if not(_la==smlParser.T__3 or _la==smlParser.T__4):
                self._errHandler.recoverInline(self)
            else:
                self._errHandler.reportMatch(self)
                self.consume()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class AssignmentContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def Ident(self):
            return self.getToken(smlParser.Ident, 0)

        def expr(self):
            return self.getTypedRuleContext(smlParser.ExprContext,0)


        def getRuleIndex(self):
            return smlParser.RULE_assignment

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterAssignment" ):
                listener.enterAssignment(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitAssignment" ):
                listener.exitAssignment(self)




    def assignment(self):

        localctx = smlParser.AssignmentContext(self, self._ctx, self.state)
        self.enterRule(localctx, 8, self.RULE_assignment)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 41
            self.match(smlParser.Ident)
            self.state = 42
            self.match(smlParser.T__5)
            self.state = 43
            self.expr()
            self.state = 44
            self.match(smlParser.T__2)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class ExprContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def arithExpr(self):
            return self.getTypedRuleContext(smlParser.ArithExprContext,0)


        def boolExpr(self):
            return self.getTypedRuleContext(smlParser.BoolExprContext,0)


        def conditionalExpr(self):
            return self.getTypedRuleContext(smlParser.ConditionalExprContext,0)


        def expr(self):
            return self.getTypedRuleContext(smlParser.ExprContext,0)


        def getRuleIndex(self):
            return smlParser.RULE_expr

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExpr" ):
                listener.enterExpr(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExpr" ):
                listener.exitExpr(self)




    def expr(self):

        localctx = smlParser.ExprContext(self, self._ctx, self.state)
        self.enterRule(localctx, 10, self.RULE_expr)
        try:
            self.state = 53
            self._errHandler.sync(self)
            la_ = self._interp.adaptivePredict(self._input,3,self._ctx)
            if la_ == 1:
                self.enterOuterAlt(localctx, 1)
                self.state = 46
                self.arithExpr(0)
                pass

            elif la_ == 2:
                self.enterOuterAlt(localctx, 2)
                self.state = 47
                self.boolExpr(0)
                pass

            elif la_ == 3:
                self.enterOuterAlt(localctx, 3)
                self.state = 48
                self.conditionalExpr()
                pass

            elif la_ == 4:
                self.enterOuterAlt(localctx, 4)
                self.state = 49
                self.match(smlParser.T__6)
                self.state = 50
                self.expr()
                self.state = 51
                self.match(smlParser.T__7)
                pass


        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class ArithExprContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def Constant(self):
            return self.getToken(smlParser.Constant, 0)

        def Ident(self):
            return self.getToken(smlParser.Ident, 0)

        def UnaryOp(self):
            return self.getToken(smlParser.UnaryOp, 0)

        def arithExpr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(smlParser.ArithExprContext)
            else:
                return self.getTypedRuleContext(smlParser.ArithExprContext,i)


        def BinaryOp(self):
            return self.getToken(smlParser.BinaryOp, 0)

        def getRuleIndex(self):
            return smlParser.RULE_arithExpr

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterArithExpr" ):
                listener.enterArithExpr(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitArithExpr" ):
                listener.exitArithExpr(self)



    def arithExpr(self, _p:int=0):
        _parentctx = self._ctx
        _parentState = self.state
        localctx = smlParser.ArithExprContext(self, self._ctx, _parentState)
        _prevctx = localctx
        _startState = 12
        self.enterRecursionRule(localctx, 12, self.RULE_arithExpr, _p)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 64
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [smlParser.Constant]:
                self.state = 56
                self.match(smlParser.Constant)
                pass
            elif token in [smlParser.Ident]:
                self.state = 57
                self.match(smlParser.Ident)
                pass
            elif token in [smlParser.UnaryOp]:
                self.state = 58
                self.match(smlParser.UnaryOp)
                self.state = 59
                self.arithExpr(2)
                pass
            elif token in [smlParser.T__6]:
                self.state = 60
                self.match(smlParser.T__6)
                self.state = 61
                self.arithExpr(0)
                self.state = 62
                self.match(smlParser.T__7)
                pass
            else:
                raise NoViableAltException(self)

            self._ctx.stop = self._input.LT(-1)
            self.state = 71
            self._errHandler.sync(self)
            _alt = self._interp.adaptivePredict(self._input,5,self._ctx)
            while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                if _alt==1:
                    if self._parseListeners is not None:
                        self.triggerExitRuleEvent()
                    _prevctx = localctx
                    localctx = smlParser.ArithExprContext(self, _parentctx, _parentState)
                    self.pushNewRecursionContext(localctx, _startState, self.RULE_arithExpr)
                    self.state = 66
                    if not self.precpred(self._ctx, 3):
                        from antlr4.error.Errors import FailedPredicateException
                        raise FailedPredicateException(self, "self.precpred(self._ctx, 3)")
                    self.state = 67
                    self.match(smlParser.BinaryOp)
                    self.state = 68
                    self.arithExpr(4) 
                self.state = 73
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,5,self._ctx)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.unrollRecursionContexts(_parentctx)
        return localctx

    class BoolExprContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def Ident(self):
            return self.getToken(smlParser.Ident, 0)

        def Constant(self):
            return self.getToken(smlParser.Constant, 0)

        def arithExpr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(smlParser.ArithExprContext)
            else:
                return self.getTypedRuleContext(smlParser.ArithExprContext,i)


        def RelationalOp(self):
            return self.getToken(smlParser.RelationalOp, 0)

        def boolExpr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(smlParser.BoolExprContext)
            else:
                return self.getTypedRuleContext(smlParser.BoolExprContext,i)


        def getRuleIndex(self):
            return smlParser.RULE_boolExpr

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterBoolExpr" ):
                listener.enterBoolExpr(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitBoolExpr" ):
                listener.exitBoolExpr(self)



    def boolExpr(self, _p:int=0):
        _parentctx = self._ctx
        _parentState = self.state
        localctx = smlParser.BoolExprContext(self, self._ctx, _parentState)
        _prevctx = localctx
        _startState = 14
        self.enterRecursionRule(localctx, 14, self.RULE_boolExpr, _p)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 87
            self._errHandler.sync(self)
            la_ = self._interp.adaptivePredict(self._input,6,self._ctx)
            if la_ == 1:
                self.state = 75
                self.match(smlParser.Ident)
                pass

            elif la_ == 2:
                self.state = 76
                self.match(smlParser.Constant)
                pass

            elif la_ == 3:
                self.state = 77
                self.arithExpr(0)
                self.state = 78
                self.match(smlParser.RelationalOp)
                self.state = 79
                self.arithExpr(0)
                pass

            elif la_ == 4:
                self.state = 81
                self.match(smlParser.T__8)
                self.state = 82
                self.boolExpr(4)
                pass

            elif la_ == 5:
                self.state = 83
                self.match(smlParser.T__6)
                self.state = 84
                self.boolExpr(0)
                self.state = 85
                self.match(smlParser.T__7)
                pass


            self._ctx.stop = self._input.LT(-1)
            self.state = 97
            self._errHandler.sync(self)
            _alt = self._interp.adaptivePredict(self._input,8,self._ctx)
            while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                if _alt==1:
                    if self._parseListeners is not None:
                        self.triggerExitRuleEvent()
                    _prevctx = localctx
                    self.state = 95
                    self._errHandler.sync(self)
                    la_ = self._interp.adaptivePredict(self._input,7,self._ctx)
                    if la_ == 1:
                        localctx = smlParser.BoolExprContext(self, _parentctx, _parentState)
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_boolExpr)
                        self.state = 89
                        if not self.precpred(self._ctx, 3):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 3)")
                        self.state = 90
                        self.match(smlParser.T__9)
                        self.state = 91
                        self.boolExpr(4)
                        pass

                    elif la_ == 2:
                        localctx = smlParser.BoolExprContext(self, _parentctx, _parentState)
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_boolExpr)
                        self.state = 92
                        if not self.precpred(self._ctx, 2):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 2)")
                        self.state = 93
                        self.match(smlParser.T__10)
                        self.state = 94
                        self.boolExpr(3)
                        pass

             
                self.state = 99
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,8,self._ctx)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.unrollRecursionContexts(_parentctx)
        return localctx

    class ConditionalExprContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def boolExpr(self):
            return self.getTypedRuleContext(smlParser.BoolExprContext,0)


        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(smlParser.ExprContext)
            else:
                return self.getTypedRuleContext(smlParser.ExprContext,i)


        def getRuleIndex(self):
            return smlParser.RULE_conditionalExpr

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterConditionalExpr" ):
                listener.enterConditionalExpr(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitConditionalExpr" ):
                listener.exitConditionalExpr(self)




    def conditionalExpr(self):

        localctx = smlParser.ConditionalExprContext(self, self._ctx, self.state)
        self.enterRule(localctx, 16, self.RULE_conditionalExpr)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 100
            self.boolExpr(0)
            self.state = 101
            self.match(smlParser.T__11)
            self.state = 102
            self.expr()
            self.state = 103
            self.match(smlParser.T__12)
            self.state = 104
            self.expr()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx



    def sempred(self, localctx:RuleContext, ruleIndex:int, predIndex:int):
        if self._predicates == None:
            self._predicates = dict()
        self._predicates[6] = self.arithExpr_sempred
        self._predicates[7] = self.boolExpr_sempred
        pred = self._predicates.get(ruleIndex, None)
        if pred is None:
            raise Exception("No predicate with index:" + str(ruleIndex))
        else:
            return pred(localctx, predIndex)

    def arithExpr_sempred(self, localctx:ArithExprContext, predIndex:int):
            if predIndex == 0:
                return self.precpred(self._ctx, 3)
         

    def boolExpr_sempred(self, localctx:BoolExprContext, predIndex:int):
            if predIndex == 1:
                return self.precpred(self._ctx, 3)
         

            if predIndex == 2:
                return self.precpred(self._ctx, 2)
         





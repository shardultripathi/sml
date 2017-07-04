// Generated from sml.g4 by ANTLR 4.7
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class smlParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, InputA=14, InputB=15, Output=16, 
		BinaryOp=17, UnaryOp=18, RelationalOp=19, Ident=20, Constant=21, WS=22;
	public static final int
		RULE_commandSeq = 0, RULE_command = 1, RULE_declaration = 2, RULE_varType = 3, 
		RULE_assignment = 4, RULE_expr = 5, RULE_arithExpr = 6, RULE_boolExpr = 7, 
		RULE_conditionalExpr = 8, RULE_inputExpr = 9, RULE_output = 10;
	public static final String[] ruleNames = {
		"commandSeq", "command", "declaration", "varType", "assignment", "expr", 
		"arithExpr", "boolExpr", "conditionalExpr", "inputExpr", "output"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'{'", "'}'", "';'", "'uint64_t'", "'bool'", "'='", "'('", "')'", 
		"'!'", "'&'", "'|'", "'?'", "':'", "'input1'", "'input2'", "'output'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, "InputA", "InputB", "Output", "BinaryOp", "UnaryOp", "RelationalOp", 
		"Ident", "Constant", "WS"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "sml.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public smlParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class CommandSeqContext extends ParserRuleContext {
		public List<CommandContext> command() {
			return getRuleContexts(CommandContext.class);
		}
		public CommandContext command(int i) {
			return getRuleContext(CommandContext.class,i);
		}
		public CommandSeqContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_commandSeq; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterCommandSeq(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitCommandSeq(this);
		}
	}

	public final CommandSeqContext commandSeq() throws RecognitionException {
		CommandSeqContext _localctx = new CommandSeqContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_commandSeq);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(25);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__2) | (1L << T__3) | (1L << T__4) | (1L << Output) | (1L << Ident))) != 0)) {
				{
				{
				setState(22);
				command();
				}
				}
				setState(27);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CommandContext extends ParserRuleContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public CommandSeqContext commandSeq() {
			return getRuleContext(CommandSeqContext.class,0);
		}
		public OutputContext output() {
			return getRuleContext(OutputContext.class,0);
		}
		public CommandContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_command; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterCommand(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitCommand(this);
		}
	}

	public final CommandContext command() throws RecognitionException {
		CommandContext _localctx = new CommandContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_command);
		try {
			setState(35);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
			case T__3:
			case T__4:
				enterOuterAlt(_localctx, 1);
				{
				setState(28);
				declaration();
				}
				break;
			case Ident:
				enterOuterAlt(_localctx, 2);
				{
				setState(29);
				assignment();
				}
				break;
			case T__0:
				enterOuterAlt(_localctx, 3);
				{
				setState(30);
				match(T__0);
				setState(31);
				commandSeq();
				setState(32);
				match(T__1);
				}
				break;
			case Output:
				enterOuterAlt(_localctx, 4);
				{
				setState(34);
				output();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationContext extends ParserRuleContext {
		public VarTypeContext varType() {
			return getRuleContext(VarTypeContext.class,0);
		}
		public TerminalNode Ident() { return getToken(smlParser.Ident, 0); }
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitDeclaration(this);
		}
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(40);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__3 || _la==T__4) {
				{
				setState(37);
				varType();
				setState(38);
				match(Ident);
				}
			}

			setState(42);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VarTypeContext extends ParserRuleContext {
		public VarTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterVarType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitVarType(this);
		}
	}

	public final VarTypeContext varType() throws RecognitionException {
		VarTypeContext _localctx = new VarTypeContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_varType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(44);
			_la = _input.LA(1);
			if ( !(_la==T__3 || _la==T__4) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignmentContext extends ParserRuleContext {
		public TerminalNode Ident() { return getToken(smlParser.Ident, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterAssignment(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitAssignment(this);
		}
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_assignment);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(46);
			match(Ident);
			setState(47);
			match(T__5);
			setState(48);
			expr();
			setState(49);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public ArithExprContext arithExpr() {
			return getRuleContext(ArithExprContext.class,0);
		}
		public BoolExprContext boolExpr() {
			return getRuleContext(BoolExprContext.class,0);
		}
		public ConditionalExprContext conditionalExpr() {
			return getRuleContext(ConditionalExprContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public InputExprContext inputExpr() {
			return getRuleContext(InputExprContext.class,0);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitExpr(this);
		}
	}

	public final ExprContext expr() throws RecognitionException {
		ExprContext _localctx = new ExprContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_expr);
		try {
			setState(59);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(51);
				arithExpr(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(52);
				boolExpr(0);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(53);
				conditionalExpr();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(54);
				match(T__6);
				setState(55);
				expr();
				setState(56);
				match(T__7);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(58);
				inputExpr();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArithExprContext extends ParserRuleContext {
		public TerminalNode Constant() { return getToken(smlParser.Constant, 0); }
		public TerminalNode UnaryOp() { return getToken(smlParser.UnaryOp, 0); }
		public TerminalNode Ident() { return getToken(smlParser.Ident, 0); }
		public List<ArithExprContext> arithExpr() {
			return getRuleContexts(ArithExprContext.class);
		}
		public ArithExprContext arithExpr(int i) {
			return getRuleContext(ArithExprContext.class,i);
		}
		public TerminalNode BinaryOp() { return getToken(smlParser.BinaryOp, 0); }
		public ArithExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arithExpr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterArithExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitArithExpr(this);
		}
	}

	public final ArithExprContext arithExpr() throws RecognitionException {
		return arithExpr(0);
	}

	private ArithExprContext arithExpr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArithExprContext _localctx = new ArithExprContext(_ctx, _parentState);
		ArithExprContext _prevctx = _localctx;
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_arithExpr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(77);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				{
				setState(63);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==UnaryOp) {
					{
					setState(62);
					match(UnaryOp);
					}
				}

				setState(65);
				match(Constant);
				}
				break;
			case 2:
				{
				setState(67);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==UnaryOp) {
					{
					setState(66);
					match(UnaryOp);
					}
				}

				setState(69);
				match(Ident);
				}
				break;
			case 3:
				{
				setState(71);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==UnaryOp) {
					{
					setState(70);
					match(UnaryOp);
					}
				}

				setState(73);
				match(T__6);
				setState(74);
				arithExpr(0);
				setState(75);
				match(T__7);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(84);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArithExprContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_arithExpr);
					setState(79);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(80);
					match(BinaryOp);
					setState(81);
					arithExpr(3);
					}
					} 
				}
				setState(86);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class BoolExprContext extends ParserRuleContext {
		public TerminalNode Ident() { return getToken(smlParser.Ident, 0); }
		public TerminalNode Constant() { return getToken(smlParser.Constant, 0); }
		public List<ArithExprContext> arithExpr() {
			return getRuleContexts(ArithExprContext.class);
		}
		public ArithExprContext arithExpr(int i) {
			return getRuleContext(ArithExprContext.class,i);
		}
		public TerminalNode RelationalOp() { return getToken(smlParser.RelationalOp, 0); }
		public List<BoolExprContext> boolExpr() {
			return getRuleContexts(BoolExprContext.class);
		}
		public BoolExprContext boolExpr(int i) {
			return getRuleContext(BoolExprContext.class,i);
		}
		public BoolExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolExpr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterBoolExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitBoolExpr(this);
		}
	}

	public final BoolExprContext boolExpr() throws RecognitionException {
		return boolExpr(0);
	}

	private BoolExprContext boolExpr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		BoolExprContext _localctx = new BoolExprContext(_ctx, _parentState);
		BoolExprContext _prevctx = _localctx;
		int _startState = 14;
		enterRecursionRule(_localctx, 14, RULE_boolExpr, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(100);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				{
				setState(88);
				match(Ident);
				}
				break;
			case 2:
				{
				setState(89);
				match(Constant);
				}
				break;
			case 3:
				{
				setState(90);
				arithExpr(0);
				setState(91);
				match(RelationalOp);
				setState(92);
				arithExpr(0);
				}
				break;
			case 4:
				{
				setState(94);
				match(T__8);
				setState(95);
				boolExpr(4);
				}
				break;
			case 5:
				{
				setState(96);
				match(T__6);
				setState(97);
				boolExpr(0);
				setState(98);
				match(T__7);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(110);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(108);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
					case 1:
						{
						_localctx = new BoolExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolExpr);
						setState(102);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(103);
						match(T__9);
						setState(104);
						boolExpr(4);
						}
						break;
					case 2:
						{
						_localctx = new BoolExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolExpr);
						setState(105);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(106);
						match(T__10);
						setState(107);
						boolExpr(3);
						}
						break;
					}
					} 
				}
				setState(112);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ConditionalExprContext extends ParserRuleContext {
		public BoolExprContext boolExpr() {
			return getRuleContext(BoolExprContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ConditionalExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditionalExpr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterConditionalExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitConditionalExpr(this);
		}
	}

	public final ConditionalExprContext conditionalExpr() throws RecognitionException {
		ConditionalExprContext _localctx = new ConditionalExprContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_conditionalExpr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(113);
			boolExpr(0);
			setState(114);
			match(T__11);
			setState(115);
			expr();
			setState(116);
			match(T__12);
			setState(117);
			expr();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InputExprContext extends ParserRuleContext {
		public TerminalNode InputA() { return getToken(smlParser.InputA, 0); }
		public ArithExprContext arithExpr() {
			return getRuleContext(ArithExprContext.class,0);
		}
		public TerminalNode InputB() { return getToken(smlParser.InputB, 0); }
		public InputExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inputExpr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterInputExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitInputExpr(this);
		}
	}

	public final InputExprContext inputExpr() throws RecognitionException {
		InputExprContext _localctx = new InputExprContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_inputExpr);
		try {
			setState(129);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case InputA:
				enterOuterAlt(_localctx, 1);
				{
				setState(119);
				match(InputA);
				setState(120);
				match(T__6);
				setState(121);
				arithExpr(0);
				setState(122);
				match(T__7);
				}
				break;
			case InputB:
				enterOuterAlt(_localctx, 2);
				{
				setState(124);
				match(InputB);
				setState(125);
				match(T__6);
				setState(126);
				arithExpr(0);
				setState(127);
				match(T__7);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OutputContext extends ParserRuleContext {
		public TerminalNode Output() { return getToken(smlParser.Output, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public OutputContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_output; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterOutput(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitOutput(this);
		}
	}

	public final OutputContext output() throws RecognitionException {
		OutputContext _localctx = new OutputContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_output);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(131);
			match(Output);
			setState(132);
			match(T__6);
			setState(133);
			expr();
			setState(134);
			match(T__7);
			setState(135);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 6:
			return arithExpr_sempred((ArithExprContext)_localctx, predIndex);
		case 7:
			return boolExpr_sempred((BoolExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean arithExpr_sempred(ArithExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean boolExpr_sempred(BoolExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 3);
		case 2:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\30\u008c\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\3\2\7\2\32\n\2\f\2\16\2\35\13\2\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\5\3&\n\3\3\4\3\4\3\4\5\4+\n\4\3\4\3\4\3\5\3\5\3\6\3\6\3\6\3\6\3\6"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\5\7>\n\7\3\b\3\b\5\bB\n\b\3\b\3\b\5\b"+
		"F\n\b\3\b\3\b\5\bJ\n\b\3\b\3\b\3\b\3\b\5\bP\n\b\3\b\3\b\3\b\7\bU\n\b\f"+
		"\b\16\bX\13\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\5\t"+
		"g\n\t\3\t\3\t\3\t\3\t\3\t\3\t\7\to\n\t\f\t\16\tr\13\t\3\n\3\n\3\n\3\n"+
		"\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\5\13\u0084"+
		"\n\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\2\4\16\20\r\2\4\6\b\n\f\16\20\22\24"+
		"\26\2\3\3\2\6\7\2\u0096\2\33\3\2\2\2\4%\3\2\2\2\6*\3\2\2\2\b.\3\2\2\2"+
		"\n\60\3\2\2\2\f=\3\2\2\2\16O\3\2\2\2\20f\3\2\2\2\22s\3\2\2\2\24\u0083"+
		"\3\2\2\2\26\u0085\3\2\2\2\30\32\5\4\3\2\31\30\3\2\2\2\32\35\3\2\2\2\33"+
		"\31\3\2\2\2\33\34\3\2\2\2\34\3\3\2\2\2\35\33\3\2\2\2\36&\5\6\4\2\37&\5"+
		"\n\6\2 !\7\3\2\2!\"\5\2\2\2\"#\7\4\2\2#&\3\2\2\2$&\5\26\f\2%\36\3\2\2"+
		"\2%\37\3\2\2\2% \3\2\2\2%$\3\2\2\2&\5\3\2\2\2\'(\5\b\5\2()\7\26\2\2)+"+
		"\3\2\2\2*\'\3\2\2\2*+\3\2\2\2+,\3\2\2\2,-\7\5\2\2-\7\3\2\2\2./\t\2\2\2"+
		"/\t\3\2\2\2\60\61\7\26\2\2\61\62\7\b\2\2\62\63\5\f\7\2\63\64\7\5\2\2\64"+
		"\13\3\2\2\2\65>\5\16\b\2\66>\5\20\t\2\67>\5\22\n\289\7\t\2\29:\5\f\7\2"+
		":;\7\n\2\2;>\3\2\2\2<>\5\24\13\2=\65\3\2\2\2=\66\3\2\2\2=\67\3\2\2\2="+
		"8\3\2\2\2=<\3\2\2\2>\r\3\2\2\2?A\b\b\1\2@B\7\24\2\2A@\3\2\2\2AB\3\2\2"+
		"\2BC\3\2\2\2CP\7\27\2\2DF\7\24\2\2ED\3\2\2\2EF\3\2\2\2FG\3\2\2\2GP\7\26"+
		"\2\2HJ\7\24\2\2IH\3\2\2\2IJ\3\2\2\2JK\3\2\2\2KL\7\t\2\2LM\5\16\b\2MN\7"+
		"\n\2\2NP\3\2\2\2O?\3\2\2\2OE\3\2\2\2OI\3\2\2\2PV\3\2\2\2QR\f\4\2\2RS\7"+
		"\23\2\2SU\5\16\b\5TQ\3\2\2\2UX\3\2\2\2VT\3\2\2\2VW\3\2\2\2W\17\3\2\2\2"+
		"XV\3\2\2\2YZ\b\t\1\2Zg\7\26\2\2[g\7\27\2\2\\]\5\16\b\2]^\7\25\2\2^_\5"+
		"\16\b\2_g\3\2\2\2`a\7\13\2\2ag\5\20\t\6bc\7\t\2\2cd\5\20\t\2de\7\n\2\2"+
		"eg\3\2\2\2fY\3\2\2\2f[\3\2\2\2f\\\3\2\2\2f`\3\2\2\2fb\3\2\2\2gp\3\2\2"+
		"\2hi\f\5\2\2ij\7\f\2\2jo\5\20\t\6kl\f\4\2\2lm\7\r\2\2mo\5\20\t\5nh\3\2"+
		"\2\2nk\3\2\2\2or\3\2\2\2pn\3\2\2\2pq\3\2\2\2q\21\3\2\2\2rp\3\2\2\2st\5"+
		"\20\t\2tu\7\16\2\2uv\5\f\7\2vw\7\17\2\2wx\5\f\7\2x\23\3\2\2\2yz\7\20\2"+
		"\2z{\7\t\2\2{|\5\16\b\2|}\7\n\2\2}\u0084\3\2\2\2~\177\7\21\2\2\177\u0080"+
		"\7\t\2\2\u0080\u0081\5\16\b\2\u0081\u0082\7\n\2\2\u0082\u0084\3\2\2\2"+
		"\u0083y\3\2\2\2\u0083~\3\2\2\2\u0084\25\3\2\2\2\u0085\u0086\7\22\2\2\u0086"+
		"\u0087\7\t\2\2\u0087\u0088\5\f\7\2\u0088\u0089\7\n\2\2\u0089\u008a\7\5"+
		"\2\2\u008a\27\3\2\2\2\17\33%*=AEIOVfnp\u0083";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
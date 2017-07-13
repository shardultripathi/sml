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
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		InputA=32, InputB=33, Output=34, BoolConstant=35, Ident=36, IntegerConstant=37, 
		WS=38;
	public static final int
		RULE_commandSeq = 0, RULE_command = 1, RULE_block = 2, RULE_blockComm = 3, 
		RULE_declaration = 4, RULE_varType = 5, RULE_assignment = 6, RULE_forLoop = 7, 
		RULE_rangeList = 8, RULE_expr = 9, RULE_arithExpr = 10, RULE_conditionalExpr = 11, 
		RULE_boolExpr = 12, RULE_inputExpr = 13, RULE_output = 14;
	public static final String[] ruleNames = {
		"commandSeq", "command", "block", "blockComm", "declaration", "varType", 
		"assignment", "forLoop", "rangeList", "expr", "arithExpr", "conditionalExpr", 
		"boolExpr", "inputExpr", "output"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'{'", "'}'", "';'", "'uint32_t'", "'='", "'for'", "'['", "':'", 
		"']'", "'('", "')'", "'-'", "'*'", "'/'", "'%'", "'+'", "'<<'", "'>>'", 
		"'&'", "'^'", "'|'", "'?'", "'!'", "'<'", "'<='", "'>'", "'>='", "'=='", 
		"'!='", "'&&'", "'||'", "'input1'", "'input2'", "'output'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, null, "InputA", "InputB", "Output", 
		"BoolConstant", "Ident", "IntegerConstant", "WS"
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
			setState(33);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__2) | (1L << T__3) | (1L << T__5) | (1L << Output) | (1L << Ident))) != 0)) {
				{
				{
				setState(30);
				command();
				}
				}
				setState(35);
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
		public ForLoopContext forLoop() {
			return getRuleContext(ForLoopContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
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
			setState(41);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
			case T__3:
				enterOuterAlt(_localctx, 1);
				{
				setState(36);
				declaration();
				}
				break;
			case Ident:
				enterOuterAlt(_localctx, 2);
				{
				setState(37);
				assignment();
				}
				break;
			case T__5:
				enterOuterAlt(_localctx, 3);
				{
				setState(38);
				forLoop();
				}
				break;
			case T__0:
				enterOuterAlt(_localctx, 4);
				{
				setState(39);
				block();
				}
				break;
			case Output:
				enterOuterAlt(_localctx, 5);
				{
				setState(40);
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

	public static class BlockContext extends ParserRuleContext {
		public List<BlockCommContext> blockComm() {
			return getRuleContexts(BlockCommContext.class);
		}
		public BlockCommContext blockComm(int i) {
			return getRuleContext(BlockCommContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitBlock(this);
		}
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(43);
			match(T__0);
			setState(47);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__5) | (1L << Ident))) != 0)) {
				{
				{
				setState(44);
				blockComm();
				}
				}
				setState(49);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(50);
			match(T__1);
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

	public static class BlockCommContext extends ParserRuleContext {
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public ForLoopContext forLoop() {
			return getRuleContext(ForLoopContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public BlockCommContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockComm; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterBlockComm(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitBlockComm(this);
		}
	}

	public final BlockCommContext blockComm() throws RecognitionException {
		BlockCommContext _localctx = new BlockCommContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_blockComm);
		try {
			setState(55);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Ident:
				enterOuterAlt(_localctx, 1);
				{
				setState(52);
				assignment();
				}
				break;
			case T__5:
				enterOuterAlt(_localctx, 2);
				{
				setState(53);
				forLoop();
				}
				break;
			case T__0:
				enterOuterAlt(_localctx, 3);
				{
				setState(54);
				block();
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
		enterRule(_localctx, 8, RULE_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(60);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__3) {
				{
				setState(57);
				varType();
				setState(58);
				match(Ident);
				}
			}

			setState(62);
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
		enterRule(_localctx, 10, RULE_varType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(64);
			match(T__3);
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
		public InputExprContext inputExpr() {
			return getRuleContext(InputExprContext.class,0);
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
		enterRule(_localctx, 12, RULE_assignment);
		try {
			setState(76);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(66);
				match(Ident);
				setState(67);
				match(T__4);
				setState(68);
				expr();
				setState(69);
				match(T__2);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(71);
				match(Ident);
				setState(72);
				match(T__4);
				setState(73);
				inputExpr();
				setState(74);
				match(T__2);
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

	public static class ForLoopContext extends ParserRuleContext {
		public TerminalNode Ident() { return getToken(smlParser.Ident, 0); }
		public RangeListContext rangeList() {
			return getRuleContext(RangeListContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ForLoopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forLoop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterForLoop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitForLoop(this);
		}
	}

	public final ForLoopContext forLoop() throws RecognitionException {
		ForLoopContext _localctx = new ForLoopContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_forLoop);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(78);
			match(T__5);
			setState(79);
			match(T__3);
			setState(80);
			match(Ident);
			setState(81);
			match(T__4);
			setState(82);
			rangeList();
			setState(83);
			block();
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

	public static class RangeListContext extends ParserRuleContext {
		public List<TerminalNode> IntegerConstant() { return getTokens(smlParser.IntegerConstant); }
		public TerminalNode IntegerConstant(int i) {
			return getToken(smlParser.IntegerConstant, i);
		}
		public RangeListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rangeList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).enterRangeList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smlListener ) ((smlListener)listener).exitRangeList(this);
		}
	}

	public final RangeListContext rangeList() throws RecognitionException {
		RangeListContext _localctx = new RangeListContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_rangeList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(85);
			match(T__6);
			setState(86);
			match(IntegerConstant);
			setState(87);
			match(T__7);
			setState(88);
			match(IntegerConstant);
			setState(91);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__7) {
				{
				setState(89);
				match(T__7);
				setState(90);
				match(IntegerConstant);
				}
			}

			setState(93);
			match(T__8);
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
		public ConditionalExprContext conditionalExpr() {
			return getRuleContext(ConditionalExprContext.class,0);
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
		enterRule(_localctx, 18, RULE_expr);
		try {
			setState(97);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(95);
				arithExpr(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(96);
				conditionalExpr();
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
		public List<ArithExprContext> arithExpr() {
			return getRuleContexts(ArithExprContext.class);
		}
		public ArithExprContext arithExpr(int i) {
			return getRuleContext(ArithExprContext.class,i);
		}
		public TerminalNode IntegerConstant() { return getToken(smlParser.IntegerConstant, 0); }
		public TerminalNode Ident() { return getToken(smlParser.Ident, 0); }
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
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_arithExpr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(108);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__9:
				{
				setState(100);
				match(T__9);
				setState(101);
				arithExpr(0);
				setState(102);
				match(T__10);
				}
				break;
			case T__11:
				{
				setState(104);
				match(T__11);
				setState(105);
				arithExpr(9);
				}
				break;
			case IntegerConstant:
				{
				setState(106);
				match(IntegerConstant);
				}
				break;
			case Ident:
				{
				setState(107);
				match(Ident);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(130);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(128);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
					case 1:
						{
						_localctx = new ArithExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_arithExpr);
						setState(110);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(111);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__12) | (1L << T__13) | (1L << T__14))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(112);
						arithExpr(9);
						}
						break;
					case 2:
						{
						_localctx = new ArithExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_arithExpr);
						setState(113);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(114);
						_la = _input.LA(1);
						if ( !(_la==T__11 || _la==T__15) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(115);
						arithExpr(8);
						}
						break;
					case 3:
						{
						_localctx = new ArithExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_arithExpr);
						setState(116);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(117);
						_la = _input.LA(1);
						if ( !(_la==T__16 || _la==T__17) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(118);
						arithExpr(7);
						}
						break;
					case 4:
						{
						_localctx = new ArithExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_arithExpr);
						setState(119);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(120);
						match(T__18);
						setState(121);
						arithExpr(6);
						}
						break;
					case 5:
						{
						_localctx = new ArithExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_arithExpr);
						setState(122);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(123);
						match(T__19);
						setState(124);
						arithExpr(5);
						}
						break;
					case 6:
						{
						_localctx = new ArithExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_arithExpr);
						setState(125);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(126);
						match(T__20);
						setState(127);
						arithExpr(4);
						}
						break;
					}
					} 
				}
				setState(132);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
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
		enterRule(_localctx, 22, RULE_conditionalExpr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(133);
			boolExpr(0);
			setState(134);
			match(T__21);
			setState(135);
			expr();
			setState(136);
			match(T__7);
			setState(137);
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

	public static class BoolExprContext extends ParserRuleContext {
		public List<BoolExprContext> boolExpr() {
			return getRuleContexts(BoolExprContext.class);
		}
		public BoolExprContext boolExpr(int i) {
			return getRuleContext(BoolExprContext.class,i);
		}
		public List<ArithExprContext> arithExpr() {
			return getRuleContexts(ArithExprContext.class);
		}
		public ArithExprContext arithExpr(int i) {
			return getRuleContext(ArithExprContext.class,i);
		}
		public TerminalNode BoolConstant() { return getToken(smlParser.BoolConstant, 0); }
		public TerminalNode Ident() { return getToken(smlParser.Ident, 0); }
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
		int _startState = 24;
		enterRecursionRule(_localctx, 24, RULE_boolExpr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(156);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				{
				setState(140);
				match(T__9);
				setState(141);
				boolExpr(0);
				setState(142);
				match(T__10);
				}
				break;
			case 2:
				{
				setState(144);
				match(T__22);
				setState(145);
				boolExpr(8);
				}
				break;
			case 3:
				{
				setState(146);
				arithExpr(0);
				setState(147);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__23) | (1L << T__24) | (1L << T__25) | (1L << T__26))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(148);
				arithExpr(0);
				}
				break;
			case 4:
				{
				setState(150);
				arithExpr(0);
				setState(151);
				_la = _input.LA(1);
				if ( !(_la==T__27 || _la==T__28) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(152);
				arithExpr(0);
				}
				break;
			case 5:
				{
				setState(154);
				match(BoolConstant);
				}
				break;
			case 6:
				{
				setState(155);
				match(Ident);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(169);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(167);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
					case 1:
						{
						_localctx = new BoolExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolExpr);
						setState(158);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(159);
						match(T__19);
						setState(160);
						boolExpr(6);
						}
						break;
					case 2:
						{
						_localctx = new BoolExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolExpr);
						setState(161);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(162);
						match(T__29);
						setState(163);
						boolExpr(5);
						}
						break;
					case 3:
						{
						_localctx = new BoolExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolExpr);
						setState(164);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(165);
						match(T__30);
						setState(166);
						boolExpr(4);
						}
						break;
					}
					} 
				}
				setState(171);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
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

	public static class InputExprContext extends ParserRuleContext {
		public TerminalNode InputA() { return getToken(smlParser.InputA, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
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
		enterRule(_localctx, 26, RULE_inputExpr);
		try {
			setState(182);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case InputA:
				enterOuterAlt(_localctx, 1);
				{
				setState(172);
				match(InputA);
				setState(173);
				match(T__9);
				setState(174);
				expr();
				setState(175);
				match(T__10);
				}
				break;
			case InputB:
				enterOuterAlt(_localctx, 2);
				{
				setState(177);
				match(InputB);
				setState(178);
				match(T__9);
				setState(179);
				expr();
				setState(180);
				match(T__10);
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
		enterRule(_localctx, 28, RULE_output);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(184);
			match(Output);
			setState(185);
			match(T__9);
			setState(186);
			expr();
			setState(187);
			match(T__10);
			setState(188);
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
		case 10:
			return arithExpr_sempred((ArithExprContext)_localctx, predIndex);
		case 12:
			return boolExpr_sempred((BoolExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean arithExpr_sempred(ArithExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 8);
		case 1:
			return precpred(_ctx, 7);
		case 2:
			return precpred(_ctx, 6);
		case 3:
			return precpred(_ctx, 5);
		case 4:
			return precpred(_ctx, 4);
		case 5:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean boolExpr_sempred(BoolExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 5);
		case 7:
			return precpred(_ctx, 4);
		case 8:
			return precpred(_ctx, 3);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3(\u00c1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\3\2\7\2\"\n\2\f\2\16"+
		"\2%\13\2\3\3\3\3\3\3\3\3\3\3\5\3,\n\3\3\4\3\4\7\4\60\n\4\f\4\16\4\63\13"+
		"\4\3\4\3\4\3\5\3\5\3\5\5\5:\n\5\3\6\3\6\3\6\5\6?\n\6\3\6\3\6\3\7\3\7\3"+
		"\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\5\bO\n\b\3\t\3\t\3\t\3\t\3\t\3"+
		"\t\3\t\3\n\3\n\3\n\3\n\3\n\3\n\5\n^\n\n\3\n\3\n\3\13\3\13\5\13d\n\13\3"+
		"\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\5\fo\n\f\3\f\3\f\3\f\3\f\3\f\3\f\3"+
		"\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\7\f\u0083\n\f\f\f\16\f"+
		"\u0086\13\f\3\r\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3\16\3\16"+
		"\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\5\16\u009f\n\16\3\16"+
		"\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\7\16\u00aa\n\16\f\16\16\16\u00ad"+
		"\13\16\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\5\17\u00b9\n"+
		"\17\3\20\3\20\3\20\3\20\3\20\3\20\3\20\2\4\26\32\21\2\4\6\b\n\f\16\20"+
		"\22\24\26\30\32\34\36\2\7\3\2\17\21\4\2\16\16\22\22\3\2\23\24\3\2\32\35"+
		"\3\2\36\37\2\u00cf\2#\3\2\2\2\4+\3\2\2\2\6-\3\2\2\2\b9\3\2\2\2\n>\3\2"+
		"\2\2\fB\3\2\2\2\16N\3\2\2\2\20P\3\2\2\2\22W\3\2\2\2\24c\3\2\2\2\26n\3"+
		"\2\2\2\30\u0087\3\2\2\2\32\u009e\3\2\2\2\34\u00b8\3\2\2\2\36\u00ba\3\2"+
		"\2\2 \"\5\4\3\2! \3\2\2\2\"%\3\2\2\2#!\3\2\2\2#$\3\2\2\2$\3\3\2\2\2%#"+
		"\3\2\2\2&,\5\n\6\2\',\5\16\b\2(,\5\20\t\2),\5\6\4\2*,\5\36\20\2+&\3\2"+
		"\2\2+\'\3\2\2\2+(\3\2\2\2+)\3\2\2\2+*\3\2\2\2,\5\3\2\2\2-\61\7\3\2\2."+
		"\60\5\b\5\2/.\3\2\2\2\60\63\3\2\2\2\61/\3\2\2\2\61\62\3\2\2\2\62\64\3"+
		"\2\2\2\63\61\3\2\2\2\64\65\7\4\2\2\65\7\3\2\2\2\66:\5\16\b\2\67:\5\20"+
		"\t\28:\5\6\4\29\66\3\2\2\29\67\3\2\2\298\3\2\2\2:\t\3\2\2\2;<\5\f\7\2"+
		"<=\7&\2\2=?\3\2\2\2>;\3\2\2\2>?\3\2\2\2?@\3\2\2\2@A\7\5\2\2A\13\3\2\2"+
		"\2BC\7\6\2\2C\r\3\2\2\2DE\7&\2\2EF\7\7\2\2FG\5\24\13\2GH\7\5\2\2HO\3\2"+
		"\2\2IJ\7&\2\2JK\7\7\2\2KL\5\34\17\2LM\7\5\2\2MO\3\2\2\2ND\3\2\2\2NI\3"+
		"\2\2\2O\17\3\2\2\2PQ\7\b\2\2QR\7\6\2\2RS\7&\2\2ST\7\7\2\2TU\5\22\n\2U"+
		"V\5\6\4\2V\21\3\2\2\2WX\7\t\2\2XY\7\'\2\2YZ\7\n\2\2Z]\7\'\2\2[\\\7\n\2"+
		"\2\\^\7\'\2\2][\3\2\2\2]^\3\2\2\2^_\3\2\2\2_`\7\13\2\2`\23\3\2\2\2ad\5"+
		"\26\f\2bd\5\30\r\2ca\3\2\2\2cb\3\2\2\2d\25\3\2\2\2ef\b\f\1\2fg\7\f\2\2"+
		"gh\5\26\f\2hi\7\r\2\2io\3\2\2\2jk\7\16\2\2ko\5\26\f\13lo\7\'\2\2mo\7&"+
		"\2\2ne\3\2\2\2nj\3\2\2\2nl\3\2\2\2nm\3\2\2\2o\u0084\3\2\2\2pq\f\n\2\2"+
		"qr\t\2\2\2r\u0083\5\26\f\13st\f\t\2\2tu\t\3\2\2u\u0083\5\26\f\nvw\f\b"+
		"\2\2wx\t\4\2\2x\u0083\5\26\f\tyz\f\7\2\2z{\7\25\2\2{\u0083\5\26\f\b|}"+
		"\f\6\2\2}~\7\26\2\2~\u0083\5\26\f\7\177\u0080\f\5\2\2\u0080\u0081\7\27"+
		"\2\2\u0081\u0083\5\26\f\6\u0082p\3\2\2\2\u0082s\3\2\2\2\u0082v\3\2\2\2"+
		"\u0082y\3\2\2\2\u0082|\3\2\2\2\u0082\177\3\2\2\2\u0083\u0086\3\2\2\2\u0084"+
		"\u0082\3\2\2\2\u0084\u0085\3\2\2\2\u0085\27\3\2\2\2\u0086\u0084\3\2\2"+
		"\2\u0087\u0088\5\32\16\2\u0088\u0089\7\30\2\2\u0089\u008a\5\24\13\2\u008a"+
		"\u008b\7\n\2\2\u008b\u008c\5\24\13\2\u008c\31\3\2\2\2\u008d\u008e\b\16"+
		"\1\2\u008e\u008f\7\f\2\2\u008f\u0090\5\32\16\2\u0090\u0091\7\r\2\2\u0091"+
		"\u009f\3\2\2\2\u0092\u0093\7\31\2\2\u0093\u009f\5\32\16\n\u0094\u0095"+
		"\5\26\f\2\u0095\u0096\t\5\2\2\u0096\u0097\5\26\f\2\u0097\u009f\3\2\2\2"+
		"\u0098\u0099\5\26\f\2\u0099\u009a\t\6\2\2\u009a\u009b\5\26\f\2\u009b\u009f"+
		"\3\2\2\2\u009c\u009f\7%\2\2\u009d\u009f\7&\2\2\u009e\u008d\3\2\2\2\u009e"+
		"\u0092\3\2\2\2\u009e\u0094\3\2\2\2\u009e\u0098\3\2\2\2\u009e\u009c\3\2"+
		"\2\2\u009e\u009d\3\2\2\2\u009f\u00ab\3\2\2\2\u00a0\u00a1\f\7\2\2\u00a1"+
		"\u00a2\7\26\2\2\u00a2\u00aa\5\32\16\b\u00a3\u00a4\f\6\2\2\u00a4\u00a5"+
		"\7 \2\2\u00a5\u00aa\5\32\16\7\u00a6\u00a7\f\5\2\2\u00a7\u00a8\7!\2\2\u00a8"+
		"\u00aa\5\32\16\6\u00a9\u00a0\3\2\2\2\u00a9\u00a3\3\2\2\2\u00a9\u00a6\3"+
		"\2\2\2\u00aa\u00ad\3\2\2\2\u00ab\u00a9\3\2\2\2\u00ab\u00ac\3\2\2\2\u00ac"+
		"\33\3\2\2\2\u00ad\u00ab\3\2\2\2\u00ae\u00af\7\"\2\2\u00af\u00b0\7\f\2"+
		"\2\u00b0\u00b1\5\24\13\2\u00b1\u00b2\7\r\2\2\u00b2\u00b9\3\2\2\2\u00b3"+
		"\u00b4\7#\2\2\u00b4\u00b5\7\f\2\2\u00b5\u00b6\5\24\13\2\u00b6\u00b7\7"+
		"\r\2\2\u00b7\u00b9\3\2\2\2\u00b8\u00ae\3\2\2\2\u00b8\u00b3\3\2\2\2\u00b9"+
		"\35\3\2\2\2\u00ba\u00bb\7$\2\2\u00bb\u00bc\7\f\2\2\u00bc\u00bd\5\24\13"+
		"\2\u00bd\u00be\7\r\2\2\u00be\u00bf\7\5\2\2\u00bf\37\3\2\2\2\21#+\619>"+
		"N]cn\u0082\u0084\u009e\u00a9\u00ab\u00b8";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
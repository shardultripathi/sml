// Generated from sml.g4 by ANTLR 4.7
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class smlLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, InputA=14, InputB=15, Output=16, 
		BinaryOp=17, UnaryOp=18, RelationalOp=19, Ident=20, Constant=21, WS=22;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
		"T__9", "T__10", "T__11", "T__12", "InputA", "InputB", "Output", "BinaryOp", 
		"UnaryOp", "RelationalOp", "Ident", "IdentNondigit", "Nondigit", "Digit", 
		"Constant", "IntegerConstant", "DecimalConstant", "NonzeroDigit", "BoolConstant", 
		"WS"
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


	public smlLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "sml.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\30\u00bd\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\3\2\3\2\3\3\3"+
		"\3\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\7"+
		"\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17"+
		"\3\17\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\21"+
		"\3\21\3\21\3\21\3\21\3\21\3\21\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22"+
		"\3\22\3\22\5\22\u0081\n\22\3\23\3\23\3\24\3\24\3\24\3\24\3\24\3\24\3\24"+
		"\3\24\3\24\3\24\5\24\u008f\n\24\3\25\3\25\3\25\7\25\u0094\n\25\f\25\16"+
		"\25\u0097\13\25\3\26\3\26\3\27\3\27\3\30\3\30\3\31\3\31\5\31\u00a1\n\31"+
		"\3\32\3\32\3\33\6\33\u00a6\n\33\r\33\16\33\u00a7\3\34\3\34\3\35\3\35\3"+
		"\35\3\35\3\35\3\35\3\35\3\35\3\35\5\35\u00b5\n\35\3\36\6\36\u00b8\n\36"+
		"\r\36\16\36\u00b9\3\36\3\36\2\2\37\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n"+
		"\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\2-\2/\2"+
		"\61\27\63\2\65\2\67\29\2;\30\3\2\b\b\2((,-//\61\61``~~\4\2##\u0080\u0080"+
		"\5\2C\\aac|\3\2\62;\3\2\63;\5\2\13\f\17\17\"\"\2\u00c5\2\3\3\2\2\2\2\5"+
		"\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2"+
		"\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33"+
		"\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2"+
		"\'\3\2\2\2\2)\3\2\2\2\2\61\3\2\2\2\2;\3\2\2\2\3=\3\2\2\2\5?\3\2\2\2\7"+
		"A\3\2\2\2\tC\3\2\2\2\13L\3\2\2\2\rQ\3\2\2\2\17S\3\2\2\2\21U\3\2\2\2\23"+
		"W\3\2\2\2\25Y\3\2\2\2\27[\3\2\2\2\31]\3\2\2\2\33_\3\2\2\2\35a\3\2\2\2"+
		"\37h\3\2\2\2!o\3\2\2\2#\u0080\3\2\2\2%\u0082\3\2\2\2\'\u008e\3\2\2\2)"+
		"\u0090\3\2\2\2+\u0098\3\2\2\2-\u009a\3\2\2\2/\u009c\3\2\2\2\61\u00a0\3"+
		"\2\2\2\63\u00a2\3\2\2\2\65\u00a5\3\2\2\2\67\u00a9\3\2\2\29\u00b4\3\2\2"+
		"\2;\u00b7\3\2\2\2=>\7}\2\2>\4\3\2\2\2?@\7\177\2\2@\6\3\2\2\2AB\7=\2\2"+
		"B\b\3\2\2\2CD\7w\2\2DE\7k\2\2EF\7p\2\2FG\7v\2\2GH\78\2\2HI\7\66\2\2IJ"+
		"\7a\2\2JK\7v\2\2K\n\3\2\2\2LM\7d\2\2MN\7q\2\2NO\7q\2\2OP\7n\2\2P\f\3\2"+
		"\2\2QR\7?\2\2R\16\3\2\2\2ST\7*\2\2T\20\3\2\2\2UV\7+\2\2V\22\3\2\2\2WX"+
		"\7#\2\2X\24\3\2\2\2YZ\7(\2\2Z\26\3\2\2\2[\\\7~\2\2\\\30\3\2\2\2]^\7A\2"+
		"\2^\32\3\2\2\2_`\7<\2\2`\34\3\2\2\2ab\7k\2\2bc\7p\2\2cd\7r\2\2de\7w\2"+
		"\2ef\7v\2\2fg\7\63\2\2g\36\3\2\2\2hi\7k\2\2ij\7p\2\2jk\7r\2\2kl\7w\2\2"+
		"lm\7v\2\2mn\7\64\2\2n \3\2\2\2op\7q\2\2pq\7w\2\2qr\7v\2\2rs\7r\2\2st\7"+
		"w\2\2tu\7v\2\2u\"\3\2\2\2v\u0081\t\2\2\2wx\7~\2\2x\u0081\7~\2\2yz\7(\2"+
		"\2z\u0081\7(\2\2{\u0081\7\'\2\2|}\7>\2\2}\u0081\7>\2\2~\177\7@\2\2\177"+
		"\u0081\7@\2\2\u0080v\3\2\2\2\u0080w\3\2\2\2\u0080y\3\2\2\2\u0080{\3\2"+
		"\2\2\u0080|\3\2\2\2\u0080~\3\2\2\2\u0081$\3\2\2\2\u0082\u0083\t\3\2\2"+
		"\u0083&\3\2\2\2\u0084\u008f\7>\2\2\u0085\u0086\7>\2\2\u0086\u008f\7?\2"+
		"\2\u0087\u008f\7@\2\2\u0088\u0089\7@\2\2\u0089\u008f\7?\2\2\u008a\u008b"+
		"\7?\2\2\u008b\u008f\7?\2\2\u008c\u008d\7#\2\2\u008d\u008f\7?\2\2\u008e"+
		"\u0084\3\2\2\2\u008e\u0085\3\2\2\2\u008e\u0087\3\2\2\2\u008e\u0088\3\2"+
		"\2\2\u008e\u008a\3\2\2\2\u008e\u008c\3\2\2\2\u008f(\3\2\2\2\u0090\u0095"+
		"\5+\26\2\u0091\u0094\5+\26\2\u0092\u0094\5/\30\2\u0093\u0091\3\2\2\2\u0093"+
		"\u0092\3\2\2\2\u0094\u0097\3\2\2\2\u0095\u0093\3\2\2\2\u0095\u0096\3\2"+
		"\2\2\u0096*\3\2\2\2\u0097\u0095\3\2\2\2\u0098\u0099\5-\27\2\u0099,\3\2"+
		"\2\2\u009a\u009b\t\4\2\2\u009b.\3\2\2\2\u009c\u009d\t\5\2\2\u009d\60\3"+
		"\2\2\2\u009e\u00a1\5\63\32\2\u009f\u00a1\59\35\2\u00a0\u009e\3\2\2\2\u00a0"+
		"\u009f\3\2\2\2\u00a1\62\3\2\2\2\u00a2\u00a3\5\65\33\2\u00a3\64\3\2\2\2"+
		"\u00a4\u00a6\5/\30\2\u00a5\u00a4\3\2\2\2\u00a6\u00a7\3\2\2\2\u00a7\u00a5"+
		"\3\2\2\2\u00a7\u00a8\3\2\2\2\u00a8\66\3\2\2\2\u00a9\u00aa\t\6\2\2\u00aa"+
		"8\3\2\2\2\u00ab\u00ac\7v\2\2\u00ac\u00ad\7t\2\2\u00ad\u00ae\7w\2\2\u00ae"+
		"\u00b5\7g\2\2\u00af\u00b0\7h\2\2\u00b0\u00b1\7c\2\2\u00b1\u00b2\7n\2\2"+
		"\u00b2\u00b3\7u\2\2\u00b3\u00b5\7g\2\2\u00b4\u00ab\3\2\2\2\u00b4\u00af"+
		"\3\2\2\2\u00b5:\3\2\2\2\u00b6\u00b8\t\7\2\2\u00b7\u00b6\3\2\2\2\u00b8"+
		"\u00b9\3\2\2\2\u00b9\u00b7\3\2\2\2\u00b9\u00ba\3\2\2\2\u00ba\u00bb\3\2"+
		"\2\2\u00bb\u00bc\b\36\2\2\u00bc<\3\2\2\2\13\2\u0080\u008e\u0093\u0095"+
		"\u00a0\u00a7\u00b4\u00b9\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
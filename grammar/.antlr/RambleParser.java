// Generated from c:\Users\lreut\Desktop\Programs\Ramble\grammar\RambleParser.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class RambleParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		IDENT=1, NEWLINE=2, WS=3, BLOCK_COMMENT=4, COMMENT=5, ADD=6, SUB=7, MUL=8, 
		DIV=9, MOD=10, POW=11, EQ=12, OR=13, AND=14, LSS=15, GRT=16, INCR=17, 
		DECR=18, EEQ=19, NEQ=20, PEQ=21, SEQ=22, MEQ=23, DEQ=24, REQ=25, LEQ=26, 
		GEQ=27, NOT=28, XOR=29, BNOT=30, BAND=31, BOR=32, LSHFT=33, RSHFT=34, 
		COLON=35, COMMA=36, SEMI=37, LPAREN=38, RPAREN=39, LCURL=40, RCURL=41, 
		LBRACK=42, RBRACK=43, UNSIGNED=44, CONST=45, INT=46, FLOAT=47, CHAR=48, 
		STRING=49, BOOL=50, LET=51, FUNC=52, RETURN=53, IF=54, ELIF=55, ELSE=56, 
		SWITCH=57, CASE=58, DEFAULT=59, WHILE=60, FOR=61, IN=62, CONTINUE=63, 
		BREAK=64, STRUCT=65, ENUM=66, TYPEDEF=67, FLOAT_LIT=68, INT_LIT=69, STRING_LIT=70, 
		CHAR_LIT=71, BOOL_LIT=72;
	public static final int
		RULE_file = 0, RULE_line = 1, RULE_statement = 2, RULE_variable = 3, RULE_expression = 4, 
		RULE_group = 5, RULE_varType = 6, RULE_literal = 7;
	private static String[] makeRuleNames() {
		return new String[] {
			"file", "line", "statement", "variable", "expression", "group", "varType", 
			"literal"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, "'+'", "'-'", "'*'", "'/'", "'%'", 
			"'**'", "'='", "'||'", "'&&'", "'<'", "'>'", "'++'", "'--'", "'=='", 
			"'!='", "'+='", "'-='", "'*='", "'/='", "'%='", "'<='", "'>='", "'!'", 
			"'^'", "'~'", "'&'", "'|'", "'<<'", "'>>'", "':'", "','", "';'", "'('", 
			"')'", "'{'", "'}'", "'['", "']'", "'unsigned'", "'const'", "'int'", 
			"'float'", "'char'", "'string'", "'bool'", "'let'", "'func'", "'return'", 
			"'if'", "'elif'", "'else'", "'switch'", "'case'", "'default'", "'while'", 
			"'for'", "'in'", "'continue'", "'break'", "'struct'", "'enum'", "'typedef'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "IDENT", "NEWLINE", "WS", "BLOCK_COMMENT", "COMMENT", "ADD", "SUB", 
			"MUL", "DIV", "MOD", "POW", "EQ", "OR", "AND", "LSS", "GRT", "INCR", 
			"DECR", "EEQ", "NEQ", "PEQ", "SEQ", "MEQ", "DEQ", "REQ", "LEQ", "GEQ", 
			"NOT", "XOR", "BNOT", "BAND", "BOR", "LSHFT", "RSHFT", "COLON", "COMMA", 
			"SEMI", "LPAREN", "RPAREN", "LCURL", "RCURL", "LBRACK", "RBRACK", "UNSIGNED", 
			"CONST", "INT", "FLOAT", "CHAR", "STRING", "BOOL", "LET", "FUNC", "RETURN", 
			"IF", "ELIF", "ELSE", "SWITCH", "CASE", "DEFAULT", "WHILE", "FOR", "IN", 
			"CONTINUE", "BREAK", "STRUCT", "ENUM", "TYPEDEF", "FLOAT_LIT", "INT_LIT", 
			"STRING_LIT", "CHAR_LIT", "BOOL_LIT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
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
	public String getGrammarFileName() { return "RambleParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public RambleParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class FileContext extends ParserRuleContext {
		public LineContext lines;
		public List<LineContext> line() {
			return getRuleContexts(LineContext.class);
		}
		public LineContext line(int i) {
			return getRuleContext(LineContext.class,i);
		}
		public FileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file; }
	}

	public final FileContext file() throws RecognitionException {
		FileContext _localctx = new FileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_file);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(17); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(16);
				((FileContext)_localctx).lines = line();
				}
				}
				setState(19); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INT) | (1L << FLOAT) | (1L << CHAR) | (1L << STRING) | (1L << BOOL) | (1L << LET))) != 0) );
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

	public static class LineContext extends ParserRuleContext {
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(RambleParser.SEMI, 0); }
		public TerminalNode NEWLINE() { return getToken(RambleParser.NEWLINE, 0); }
		public TerminalNode EOF() { return getToken(RambleParser.EOF, 0); }
		public LineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_line; }
	}

	public final LineContext line() throws RecognitionException {
		LineContext _localctx = new LineContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_line);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(21);
			statement();
			setState(22);
			_la = _input.LA(1);
			if ( !(((((_la - -1)) & ~0x3f) == 0 && ((1L << (_la - -1)) & ((1L << (EOF - -1)) | (1L << (NEWLINE - -1)) | (1L << (SEMI - -1)))) != 0)) ) {
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

	public static class StatementContext extends ParserRuleContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_statement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(24);
			variable();
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

	public static class VariableContext extends ParserRuleContext {
		public VarTypeContext varType() {
			return getRuleContext(VarTypeContext.class,0);
		}
		public TerminalNode IDENT() { return getToken(RambleParser.IDENT, 0); }
		public TerminalNode EQ() { return getToken(RambleParser.EQ, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_variable);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(26);
			varType();
			setState(27);
			match(IDENT);
			setState(30);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==EQ) {
				{
				setState(28);
				match(EQ);
				setState(29);
				expression(0);
				}
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

	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext left;
		public Token operator;
		public ExpressionContext right;
		public Token comparator;
		public GroupContext group() {
			return getRuleContext(GroupContext.class,0);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode SUB() { return getToken(RambleParser.SUB, 0); }
		public TerminalNode NOT() { return getToken(RambleParser.NOT, 0); }
		public TerminalNode INCR() { return getToken(RambleParser.INCR, 0); }
		public TerminalNode DECR() { return getToken(RambleParser.DECR, 0); }
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public TerminalNode EQ() { return getToken(RambleParser.EQ, 0); }
		public TerminalNode NEQ() { return getToken(RambleParser.NEQ, 0); }
		public TerminalNode LSS() { return getToken(RambleParser.LSS, 0); }
		public TerminalNode GRT() { return getToken(RambleParser.GRT, 0); }
		public TerminalNode LEQ() { return getToken(RambleParser.LEQ, 0); }
		public TerminalNode GEQ() { return getToken(RambleParser.GEQ, 0); }
		public TerminalNode AND() { return getToken(RambleParser.AND, 0); }
		public TerminalNode OR() { return getToken(RambleParser.OR, 0); }
		public TerminalNode POW() { return getToken(RambleParser.POW, 0); }
		public TerminalNode MUL() { return getToken(RambleParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(RambleParser.DIV, 0); }
		public TerminalNode MOD() { return getToken(RambleParser.MOD, 0); }
		public TerminalNode ADD() { return getToken(RambleParser.ADD, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 8;
		enterRecursionRule(_localctx, 8, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(37);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
				{
				setState(33);
				group();
				}
				break;
			case SUB:
			case INCR:
			case DECR:
			case NOT:
				{
				setState(34);
				((ExpressionContext)_localctx).operator = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SUB) | (1L << INCR) | (1L << DECR) | (1L << NOT))) != 0)) ) {
					((ExpressionContext)_localctx).operator = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(35);
				((ExpressionContext)_localctx).right = expression(2);
				}
				break;
			case FLOAT_LIT:
			case INT_LIT:
			case STRING_LIT:
			case CHAR_LIT:
			case BOOL_LIT:
				{
				setState(36);
				literal();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(53);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(51);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						_localctx.left = _prevctx;
						_localctx.left = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(39);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(40);
						((ExpressionContext)_localctx).comparator = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << EQ) | (1L << OR) | (1L << AND) | (1L << LSS) | (1L << GRT) | (1L << NEQ) | (1L << LEQ) | (1L << GEQ))) != 0)) ) {
							((ExpressionContext)_localctx).comparator = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(41);
						((ExpressionContext)_localctx).right = expression(7);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						_localctx.left = _prevctx;
						_localctx.left = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(42);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(43);
						((ExpressionContext)_localctx).operator = match(POW);
						setState(44);
						((ExpressionContext)_localctx).right = expression(6);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						_localctx.left = _prevctx;
						_localctx.left = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(45);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(46);
						((ExpressionContext)_localctx).operator = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << MUL) | (1L << DIV) | (1L << MOD))) != 0)) ) {
							((ExpressionContext)_localctx).operator = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(47);
						((ExpressionContext)_localctx).right = expression(5);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						_localctx.left = _prevctx;
						_localctx.left = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(48);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(49);
						((ExpressionContext)_localctx).operator = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==ADD || _la==SUB) ) {
							((ExpressionContext)_localctx).operator = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(50);
						((ExpressionContext)_localctx).right = expression(4);
						}
						break;
					}
					} 
				}
				setState(55);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
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

	public static class GroupContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(RambleParser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(RambleParser.RPAREN, 0); }
		public GroupContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_group; }
	}

	public final GroupContext group() throws RecognitionException {
		GroupContext _localctx = new GroupContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_group);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(56);
			match(LPAREN);
			setState(57);
			expression(0);
			setState(58);
			match(RPAREN);
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
		public TerminalNode INT() { return getToken(RambleParser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(RambleParser.FLOAT, 0); }
		public TerminalNode STRING() { return getToken(RambleParser.STRING, 0); }
		public TerminalNode CHAR() { return getToken(RambleParser.CHAR, 0); }
		public TerminalNode BOOL() { return getToken(RambleParser.BOOL, 0); }
		public TerminalNode LET() { return getToken(RambleParser.LET, 0); }
		public VarTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varType; }
	}

	public final VarTypeContext varType() throws RecognitionException {
		VarTypeContext _localctx = new VarTypeContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_varType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(60);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INT) | (1L << FLOAT) | (1L << CHAR) | (1L << STRING) | (1L << BOOL) | (1L << LET))) != 0)) ) {
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

	public static class LiteralContext extends ParserRuleContext {
		public TerminalNode INT_LIT() { return getToken(RambleParser.INT_LIT, 0); }
		public TerminalNode FLOAT_LIT() { return getToken(RambleParser.FLOAT_LIT, 0); }
		public TerminalNode STRING_LIT() { return getToken(RambleParser.STRING_LIT, 0); }
		public TerminalNode CHAR_LIT() { return getToken(RambleParser.CHAR_LIT, 0); }
		public TerminalNode BOOL_LIT() { return getToken(RambleParser.BOOL_LIT, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(62);
			_la = _input.LA(1);
			if ( !(((((_la - 68)) & ~0x3f) == 0 && ((1L << (_la - 68)) & ((1L << (FLOAT_LIT - 68)) | (1L << (INT_LIT - 68)) | (1L << (STRING_LIT - 68)) | (1L << (CHAR_LIT - 68)) | (1L << (BOOL_LIT - 68)))) != 0)) ) {
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 4:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 6);
		case 1:
			return precpred(_ctx, 5);
		case 2:
			return precpred(_ctx, 4);
		case 3:
			return precpred(_ctx, 3);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3JC\4\2\t\2\4\3\t\3"+
		"\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\3\2\6\2\24\n\2\r\2\16"+
		"\2\25\3\3\3\3\3\3\3\4\3\4\3\5\3\5\3\5\3\5\5\5!\n\5\3\6\3\6\3\6\3\6\3\6"+
		"\5\6(\n\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\7\6\66\n\6\f"+
		"\6\16\69\13\6\3\7\3\7\3\7\3\7\3\b\3\b\3\t\3\t\3\t\2\3\n\n\2\4\6\b\n\f"+
		"\16\20\2\t\4\3\4\4\'\'\5\2\t\t\23\24\36\36\5\2\16\22\26\26\34\35\3\2\n"+
		"\f\3\2\b\t\3\2\60\65\3\2FJ\2B\2\23\3\2\2\2\4\27\3\2\2\2\6\32\3\2\2\2\b"+
		"\34\3\2\2\2\n\'\3\2\2\2\f:\3\2\2\2\16>\3\2\2\2\20@\3\2\2\2\22\24\5\4\3"+
		"\2\23\22\3\2\2\2\24\25\3\2\2\2\25\23\3\2\2\2\25\26\3\2\2\2\26\3\3\2\2"+
		"\2\27\30\5\6\4\2\30\31\t\2\2\2\31\5\3\2\2\2\32\33\5\b\5\2\33\7\3\2\2\2"+
		"\34\35\5\16\b\2\35 \7\3\2\2\36\37\7\16\2\2\37!\5\n\6\2 \36\3\2\2\2 !\3"+
		"\2\2\2!\t\3\2\2\2\"#\b\6\1\2#(\5\f\7\2$%\t\3\2\2%(\5\n\6\4&(\5\20\t\2"+
		"\'\"\3\2\2\2\'$\3\2\2\2\'&\3\2\2\2(\67\3\2\2\2)*\f\b\2\2*+\t\4\2\2+\66"+
		"\5\n\6\t,-\f\7\2\2-.\7\r\2\2.\66\5\n\6\b/\60\f\6\2\2\60\61\t\5\2\2\61"+
		"\66\5\n\6\7\62\63\f\5\2\2\63\64\t\6\2\2\64\66\5\n\6\6\65)\3\2\2\2\65,"+
		"\3\2\2\2\65/\3\2\2\2\65\62\3\2\2\2\669\3\2\2\2\67\65\3\2\2\2\678\3\2\2"+
		"\28\13\3\2\2\29\67\3\2\2\2:;\7(\2\2;<\5\n\6\2<=\7)\2\2=\r\3\2\2\2>?\t"+
		"\7\2\2?\17\3\2\2\2@A\t\b\2\2A\21\3\2\2\2\7\25 \'\65\67";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
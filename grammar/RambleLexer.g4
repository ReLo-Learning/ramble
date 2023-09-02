lexer grammar RambleLexer;

fragment DIGIT  : [0-9];
IDENT : [_a-zA-Z][_a-zA-Z0-9]*;

//Whitespace and Comments
NEWLINE : '\r'? '\n';
WS : [ \t]+  -> skip;
BLOCK_COMMENT : '/*' .*? '*/' -> skip;
COMMENT : '//' ~[\r\n]* -> skip;

//Symbols
ADD     : '+';
SUB     : '-';
MUL     : '*';
DIV     : '/';
MOD     : '%';
POW     : '**';
EQ      : '=';

OR      : '||';
AND     : '&&';
LSS     : '<';
GRT     : '>';

INCR    : '++';
DECR    : '--';

EEQ     : '==';
NEQ     : '!=';
PEQ     : '+=';
SEQ     : '-=';
MEQ     : '*=';
DEQ     : '/=';
REQ     : '%=';
LEQ     : '<=';
GEQ     : '>=';

NOT     : '!';
XOR     : '^';
BNOT    : '~';
BAND    : '&';
BOR     : '|';
LSHFT   : '<<';
RSHFT   : '>>';

COLON   : ':';
COMMA   : ',';
SEMI    : ';';
LPAREN  : '(';
RPAREN  : ')';
LCURL   : '{';
RCURL   : '}';
LBRACK  : '[';
RBRACK  : ']';

// Keywords
UNSIGNED    : 'unsigned';
CONST       : 'const';
INT         : 'int';
FLOAT       : 'float';
CHAR        : 'char';
STRING      : 'string';
BOOL        : 'bool';
LET         : 'let';

FUNC        : 'func';
RETURN      : 'return';

IF          : 'if';
ELIF        : 'elif';
ELSE        : 'else';
SWITCH      : 'switch';
CASE        : 'case';
DEFAULT     : 'default';

WHILE       : 'while';
FOR         : 'for';
IN          : 'in';
CONTINUE    : 'continue';
BREAK       : 'break';

STRUCT      : 'struct';
ENUM        : 'enum';
TYPEDEF     : 'typedef';

// Type Literals
FLOAT_LIT   : DIGIT+ ([.,] DIGIT+)?;
INT_LIT     : DIGIT+;
STRING_LIT  : '"' .*? '"';
CHAR_LIT    : '\'' . '\'';
BOOL_LIT    : 'true' | 'false'; 
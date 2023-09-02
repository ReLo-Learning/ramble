parser grammar RambleParser;

options {
    tokenVocab = RambleLexer;
}

file: lines = line+;
line: statement (SEMI | NEWLINE | EOF);

statement:
    variable;

variable:
    varType IDENT (EQ expression)?;

expression:
    group
    | left = expression comparator = (
        EQ | NEQ | LSS | GRT | LEQ | GEQ | AND | OR
    ) right = expression
    | left = expression operator = POW right = expression
    | left = expression operator = (MUL | DIV | MOD) right = expression
    | left = expression operator = (ADD | SUB) right = expression
    | operator = (SUB | NOT | INCR | DECR) right = expression
    | literal;

group: LPAREN expression RPAREN;

varType : INT | FLOAT | STRING | CHAR | BOOL | LET;
literal : INT_LIT | FLOAT_LIT | STRING_LIT | CHAR_LIT | BOOL_LIT;
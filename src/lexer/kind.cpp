#include "kind.hpp"

std::map<Kind, std::string> TokenKind = {
    {ILLEGAL, "ILLEGAL"},
    {eof, "EOF"},

    /*Literals*/
    {IDENT, "IDENT"},
    {INT_LIT, "INT_LIT"},
    {FLOAT_LIT, "FLOAT_LIT"},
    {STRING_LIT, "STRING_LIT"},
    {RUNE_LIT, "RUNE_LIT"},

    /*Operators*/
    {ADD, "+"},
    {SUB, "-"},
    {MUL, "*"},
    {DIV, "/"},
    {MOD, "%"},
    {POW, "**"},
    {EQ, "="},

    {OR, "||"},
    {AND, "&&"},
    {LSS, "<"},
    {GRT, ">"},
    {NOT, "!"},
    {XOR, "^"},
    {bNOT, "~"},
    {bAND, "&"},
    {bOR, "|"},
    {SHL, "<<"},
    {SHR, ">>"},

    {INCR, "++"},
    {DECR, "--"},

    {ARWL, "<-"},
    {ARWR, "->"},

    {EEQ, "=="},
    {NEQ, "!="},
    {PEQ, "+="},
    {SEQ, "-="},
    {MEQ, "*="},
    {DEQ, "/="},
    {REQ, "%="},
    {LEQ, "<="},
    {GEQ, ">="},

    {AEQ, "&="},
    {OEQ, "|="},
    {XEQ, "^="},
    {SHLEQ, "<<="},
    {SHREQ, ">>="},

    {COLON, ":"},
    {COMMA, ","},
    {SEMI, ";"},
    {LPAREN, "("},
    {RPAREN, ")"},
    {LCURL, "{"},
    {RCURL, "}"},
    {LBRACK, "["},
    {RBRACK, "]"},
    {PERIOD, "."},
    {ELLIPSIS, "..."},
    
    /*Keywords*/
    {LET, "LET"},
    {CONST, "CONST"},
    {UNSIGNED, "UNSIGNED"},
    {EXTERN, "EXTERN"},
    {PRIVATE, "PRIVATE"},
    {SWITCH, "SWITCH"},
    {CASE, "CASE"},
    {DEFAULT, "DEFAULT"},
    {FOR, "FOR"},
    {WHILE, "WHILE"},
    {CONTINUE, "CONTINUE"},
    {BREAK, "BREAK"},
    {IF, "IF"},
    {ELIF, "ELIF"},
    {ELSE, "ELSE"},
    {STRUCT, "STRUCT"},
    {TYPEDEF, "TYPEDEF"},
    {UNION, "UNION"},
    {ENUM, "ENUM"},
    {INTERFACE, "INTERFACE"},
    {FUNC, "FUNC"},
    {RETURN, "RETURN"},
    {IMPORT, "IMPORT"},
};

std::string getType(Kind kind)
{
    return TokenKind[kind];
}

#include "kind.hpp"

std::map<Kind, std::string> TokenKind = {
    {ILLEGAL, "ILLEGAL"},
    {eof, "EOF"},

    /*Literals*/
    {IDENT, "IDENT"},
    {INT_LIT, "INT_LIT"},
    {FLOAT_LIT, "FLOAT_LIT"},

    /*Symbols*/
    {EQ, "="},
    {ADD, "+"},
    {SUB, "-"},
    {MUL, "*"},
    {DIV, "/"},
    {MOD, "%"},
    {SEMI, ";"},

    {INCR, "++"},

    /*Keywords*/
    {LET, "LET"},
    {INT, "INT"},
    {FLOAT, "FLOAT"},
};

std::string getType(Kind kind)
{
    return TokenKind[kind];
}

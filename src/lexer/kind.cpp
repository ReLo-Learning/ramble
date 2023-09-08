#include "kind.hpp"

std::map<Kind, std::string> TokenKind = {
    {ILLEGAL, "ILLEGAL"},
    {eof, "EOF"},

    /*Literals*/
    {IDENT, "IDENT"},
    {INT, "INT"},
    {FLOAT, "FLOAT"},

    /*Symbols*/
    {EQ, "="},
    {SEMI, ";"},

    {INCR, "++"},

    /*Keywords*/
    {LET, "LET"},
};

std::string getType(Kind kind)
{
    return TokenKind[kind];
}

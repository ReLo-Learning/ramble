#pragma once

#ifndef KIND_HPP
#define KIND_HPP

#include <map>
#include <string>

enum Kind
{
    ILLEGAL,
    eof,

    literal_begin,
    IDENT,
    INT,
    FLOAT,
    CHAR,
    STRING,
    literal_end,

    operator_begin,
    ADD,    // +
    SUB,    // -
    MUL,    // *
    DIV,    // /
    MOD,    // %
    POW,    // **
    EQ,     // =

    OR,     // ||
    AND,    // &&
    LSS,    // <
    GRT,    // >
    NOT,    // !
    XOR,    // ^
    bNOT,   // ~
    bAND,   // &
    bOR,    // |
    SHL,    // << 
    SHR,    // >>

    INCR,   // ++
    DECR,   // --

    ARWL,   // <-
    ARWR,   // ->

    EEQ,    // ==
    NEQ,    // !=
    PEQ,    // +=
    SEQ,    // -=
    MEQ,    // *=
    DEQ,    // /=
    REQ,    // %=
    LEQ,    // <=
    GEQ,    // >=

    AEQ,    // &=
    OEQ,    // |=
    XEQ,    // ^=
    SHLEQ,  // <<=
    SHREQ,  // >>=

    COLON,  // :
    COMMA,  // ,
    SEMI,   // ;
    LPAREN, // (
    RPAREN, // )
    LCURL,  // {
    RCURL,  // }
    LBRACK, // [
    RBRACK, // ]
    ELLIPSIS, // ...
    operator_end,

    keyword_begin,
    LET,

    BREAK,
    CASE,
    SWITCH,
    keyword_end,
};

static std::map<Kind, std::string> TokenKind = {
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



#endif
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
    INT_LIT,
    FLOAT_LIT,
    CHAR_LIT,
    STRING_LIT,
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
    INT,
    FLOAT,
    CHAR,
    BOOL,
    CONST,
    UNSIGNED,
    EXTERN,
    PRIVATE,

    SWITCH,
    CASE,
    BREAK,
    DEFAULT,
    FOR,
    WHILE,
    CONTINUE,
    IF,
    ELIF,
    ELSE,

    STRUCT,
    TYPEDEF,
    UNION,
    ENUM,

    FUNC,
    RETURN,

    keyword_end,
};

std::string getType(Kind kind);


#endif
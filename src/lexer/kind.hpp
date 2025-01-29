// Copyright 2025 Logan Reuter. All rights reserved.

// Kind.hpp defines the different types of tokens used in Ramble
#pragma once

#ifndef KIND_HPP
#define KIND_HPP

#include <map>
#include <string>

// List of kinds
enum Kind
{
    ILLEGAL,
    eof,

    literal_begin,
    IDENT,          // [a-zA-Z][a-zA-Z0-9]+
    INT_LIT,        // xxx
    FLOAT_LIT,      // x.xx
    RUNE_LIT,       // 'A'
    STRING_LIT,     // "This is a string"
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
    PERIOD, // .
    ELLIPSIS, // ...
    operator_end,

    keyword_begin,
    LET,
    CONST,
    UNSIGNED,
    EXTERN,
    PRIVATE,

    SWITCH,
    CASE,
    DEFAULT,
    FOR,
    WHILE,
    CONTINUE,
    BREAK,
    IF,
    ELIF,
    ELSE,

    STRUCT,
    TYPEDEF,
    UNION,
    ENUM,
    INTERFACE,

    FUNC,
    RETURN,

    IMPORT,

    keyword_end,
};

std::string getType(Kind kind);


#endif
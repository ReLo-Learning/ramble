#pragma once

#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>

#include "../errors/error.hpp"

enum Kind
{
    /*
    Symbols
    */
    //Arithmetic
    ADD,    // +
    SUB,    // -
    MUL,    // *
    DIV,    // /
    MOD,    // %
    POW,    // **
    EQ,     // =

    //Logical
    OR,
    AND,
    LSS,
    GRT,
    NOT,
    XOR,
    bNOT,
    bAND,
    LSHFT,
    RSHIFT,

    INCR,
    DECR,

    EEQ,
    NEQ,
    PEQ,
    SEQ,
    MEQ,
    DEQ,
    REQ,
    LEQ,
    GEQ,

    //Syntax
    COLON,
    COMMA,
    SEMI,
    LPAREN,
    RPAREN,
    LCURL,
    RCURL,
    LBRACK,
    RBRACK,

    KEYWORD,
    IDENT,
    LITERAL,

    END,

    COUNT
};

struct Token
{};

class Lexer
{
    private:

    public:
        Lexer(std::string str);

        Lexer(std::ifstream& file);
};

#endif
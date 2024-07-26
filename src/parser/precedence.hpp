#pragma once

#ifndef PRECEDENCE_HPP
#define PRECEDENCE_HPP

enum Precedence
{
    P_DEFAULT = 1,
    P_COMMA,            // ,
    ASSIGNMENT,         // = += -= *= /= %= <<= >>= &= ^= |=
    LOGICAL_OR,         // ||
    LOGICAL_AND,        // && 
    BITWISE_OR,         // | 
    BITWISE_XOR,        // ^
    BITWISE_AND,        // &
    EQUALITY,           // == !=
    RELATIONAL,         // < <= >= >
    SHIFT,              // << >>
    ADDITIVE,           // + -
    MULTIPLICATIVE,     // * / %
    POWER,              // **
    UNARY,              // - ! ~ ++ -- &
    POSTFIX,            // ++ -- []
    CALL,               // ()
    MEMBER,             // -> .
    PRIMARY             
};

#endif
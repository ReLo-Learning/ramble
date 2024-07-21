#pragma once

#ifndef PRECEDENCE_HPP
#define PRECEDENCE_HPP

enum Precedence
{
    P_DEFAULT,
    P_COMMA,
    ASSIGNMENT,
    LOGICAL,
    RELATIONAL,
    ADDITIVE,
    MULTIPLICATIVE,
    UNARY,
    CALL,
    MEMBER,
    PRIMARY
};

#endif
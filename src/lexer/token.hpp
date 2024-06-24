#pragma once

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include <iomanip>

#include "kind.hpp"

class Token
{
private:
    int line;
    int column;

    Kind type;
    int SubType;


public:
    std::string value;
    
    Token(Kind kind);
    Token(Kind kind, int line, int column);
    Token(Kind kind, std::string value, int line, int column);

    Kind kind();
    bool is(Kind kind);
    bool isAny(int len, const Kind *kinds);

    friend std::ostream &operator<<(std::ostream &os, const Token &token);
};

#endif
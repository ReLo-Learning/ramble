#pragma once

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "kind.hpp"

class Token
{
private:
    int line;
    int column;
    std::streampos filePos;

    Kind type;
    int SubType;

public:
    std::string value;
    
    Token() = default;
    Token(Kind kind);
    Token(Kind kind, int line, int column, std::streampos filePos);
    Token(Kind kind, std::string value, int line, int column, std::streampos filePos);

    Kind kind();
    bool is(Kind kind);
    bool isAny(int len, const Kind kinds[]);
    std::string kindStr();
    std::string str();
    std::string val();
    int getLine();
    int getColumn();
    std::streampos getFilePos();
};

#endif
#pragma once

#ifndef BUILTIN_HPP
#define BUILTIN_HPP

#include "IType.hpp"
#include "../lexer/token.hpp"

namespace Type
{

enum Basic;

int isBuiltinType(Token t);

class Void : public IType
{
public:
    Void() = default;
    std::string str();
    std::string codegen() { return ""; }
};

class Builtin : public IType
{
private:
    Basic m_type;
    std::string m_value;

public:
    Builtin(Basic type);
    std::string str();
    std::string codegen();
};

}


#endif
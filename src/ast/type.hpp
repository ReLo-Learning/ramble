#pragma once

#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>

namespace AST
{
class IType
{
public:
    virtual ~IType() = default;
    virtual std::string str() = 0;
};

class SymbolType: public IType
{
private:
    std::string m_type;

public:
    SymbolType(std::string type) : m_type(type) {};
    std::string str() { return this->m_type; };
};
}

#endif
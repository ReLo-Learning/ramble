#pragma once

#ifndef STRINGLITERAL_HPP
#define STRINGLITERAL_HPP

#include "../IVisitor.hpp"

namespace AST
{
    class StringLiteral : public IExpr
    {
    private:
        std::string m_value;

    public:
        StringLiteral(std::string value) : m_value(value) {};
        void accept(IVisitor *v);
        std::string str() { return m_value; }
    };
}

#endif
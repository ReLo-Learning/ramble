#pragma once

#ifndef STRINGLITERAL_HPP
#define STRINGLITERAL_HPP

#include "ExprVisitor.hpp"

namespace AST
{
    class StringLiteral : public IExpr
    {
    private:
        const char *m_value;

    public:
        StringLiteral(std::string value) : m_value(value.c_str()) {};
        void accept(ExprVisitor *v) { v->visit(this); }
        std::string str() { return m_value; }
    };
}

#endif
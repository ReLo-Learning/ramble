#pragma once

#ifndef INTLITERAL_HPP
#define INTLITERAL_HPP

#include "ExprVisitor.hpp"

namespace AST
{
    class IntLiteral : public IExpr
    {
    private:
        int m_value;

    public:
        IntLiteral(int value) : m_value(value) {};
        void accept(ExprVisitor *v) { v->visit(this); };
        std::string str() { return std::to_string(m_value); };
    };
}

#endif
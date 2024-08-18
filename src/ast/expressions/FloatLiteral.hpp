#pragma once

#ifndef FLOATLITERAL_HPP
#define FLOATLITERAL_HPP

#include "ExprVisitor.hpp"

namespace AST
{
    class FloatLiteral : public IExpr
    {
    private:
        float m_value;

    public:
        FloatLiteral(float value) : m_value(value) {};
        void accept(ExprVisitor *v) { v->visit(this); }
        std::string str() { return std::to_string(m_value); }
    };
}

#endif
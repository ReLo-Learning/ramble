#pragma once

#ifndef FLOATLITERAL_HPP
#define FLOATLITERAL_HPP

#include "../IVisitor.hpp"

namespace AST
{
    class FloatLiteral : public IExpr
    {
    private:
        float m_value;

    public:
        FloatLiteral(float value) : m_value(value) {};
        void accept(IVisitor *v);
        std::string str() { return std::to_string(m_value); }
    };
}

#endif
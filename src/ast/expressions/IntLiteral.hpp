#pragma once

#ifndef INTLITERAL_HPP
#define INTLITERAL_HPP

#include "../IVisitor.hpp"

namespace AST
{
    class IntLiteral : public IExpr
    {
    private:
        int m_value;

    public:
        IntLiteral(int value) : m_value(value) {};
        void accept(IVisitor *v);
        std::string str() { return std::to_string(m_value); };
    };
}

#endif
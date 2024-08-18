#pragma once

#ifndef RUNELITERAL_HPP
#define RUNELITERAL_HPP

#include "ExprVisitor.hpp"

namespace AST
{
    class RuneLiteral : public IExpr
    {
    private:
        uint32_t m_value;

    public:
        RuneLiteral(uint32_t value) : m_value(value) {};
        void accept(ExprVisitor *v) { v->visit(this); }
        std::string str() { return std::to_string(m_value); }
    };
}

#endif
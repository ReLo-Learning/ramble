#pragma once

#ifndef IDENTEXPR_HPP
#define IDENTEXPR_HPP

#include "../IVisitor.hpp"

namespace AST
{
    class IdentExpr : public IExpr
    {
    private:
        Token m_ident;

    public:
        IdentExpr(Token ident) : m_ident(ident) {}
        void accept(IVisitor *v);
        std::string str() { return m_ident.val(); }
    };
}

#endif
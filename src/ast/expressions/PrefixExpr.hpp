#pragma once

#ifndef PREFIXEXPR_HPP
#define PREFIXEXPR_HPP

#include "ExprVisitor.hpp"

namespace AST
{
    // (Op)(Expr)
    class PrefixExpr : public IExpr
    {
        Token Op;
        std::unique_ptr<IExpr> RHS;

    public:
        PrefixExpr(Token Op, std::unique_ptr<IExpr> RHS) : Op(Op), RHS(std::move(RHS)) {}
    };
} 

#endif
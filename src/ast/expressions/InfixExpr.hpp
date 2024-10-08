#pragma once

#ifndef INFIXEXPR_HPP
#define INFIXEXPR_HPP

#include "../IVisitor.hpp"

namespace AST
{
    // (Expr)(Op)(Expr)
    class InfixExpr : public IExpr
    {
    private:
        Token Op;
        std::unique_ptr<IExpr> LHS, RHS;

    public:
        InfixExpr(Token Op, std::unique_ptr<IExpr> LHS, std::unique_ptr<IExpr> RHS) : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
        void accept(IVisitor *v);
        std::string str() { return "( " + LHS->str() + " " + getType(Op.kind()) + " " + RHS->str() + " )"; }
    };
}

#endif
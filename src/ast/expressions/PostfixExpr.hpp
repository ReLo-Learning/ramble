#pragma once

#ifndef POSTFIX_HPP
#define POSTFIX_HPP

#include "../IVisitor.hpp"

namespace AST
{
    // (Expr)(Op)
    class PostfixExpr : public IExpr
    {
        Token Op;
        std::unique_ptr<IExpr> LHS;

    public:
        PostfixExpr(Token Op, std::unique_ptr<IExpr> LHS) : Op(Op), LHS(std::move(LHS)) {}
        void accept(IVisitor *v);
        std::string str() { return LHS->str() + Op.kindStr(); }
    };
}

#endif
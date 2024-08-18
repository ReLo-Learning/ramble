#pragma once

#ifndef EXPRVISITOR_HPP
#define EXPRVISITOR_HPP

#include "IExpr.hpp"

namespace AST
{
    class IntLiteral;
    class FloatLiteral;
    class RuneLiteral;
    class StringLiteral;
    class IdentExpr;
    class InfixExpr;
    class PrefixExpr;
    class PostfixExpr;
    class CallExpr;

    class ExprVisitor
    {
    public:
        ~ExprVisitor() = default;
        virtual void visit(IntLiteral *expr);
        virtual void visit(FloatLiteral *expr);
        virtual void visit(RuneLiteral *expr);
        virtual void visit(StringLiteral *expr);
        virtual void visit(IdentExpr *expr);
        virtual void visit(InfixExpr *expr);
        virtual void visit(PrefixExpr *expr);
        virtual void visit(PostfixExpr *expr);
        virtual void visit(CallExpr *expr);
    };
}

#endif
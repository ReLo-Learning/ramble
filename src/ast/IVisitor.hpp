#pragma once

#ifndef IVISITOR_HPP
#define IVISITOR_HPP

#include "statements/IStmt.hpp"
#include "expressions/IExpr.hpp"

namespace AST
{

    /*
    Statements
    */
    class VarDecl;
    class FuncDecl;
    class BlockStmt;
    class ExprStmt;
    class RetStmt;
    class ExternStmt;

    /*
    Expressions
    */
    class IntLiteral;
    class FloatLiteral;
    class RuneLiteral;
    class StringLiteral;
    class IdentExpr;
    class InfixExpr;
    class PrefixExpr;
    class PostfixExpr;
    class CallExpr;

    class IVisitor
    {
    public:
        IVisitor() = default;
        ~IVisitor() = default;

        virtual void visit(VarDecl *) = 0;
        virtual void visit(FuncDecl *) = 0;
        virtual void visit(BlockStmt *) = 0;
        virtual void visit(ExprStmt *) = 0;
        virtual void visit(RetStmt *) = 0;
        virtual void visit(ExternStmt *) = 0;

        virtual void visit(IntLiteral *) = 0;
        virtual void visit(FloatLiteral *) = 0;
        virtual void visit(RuneLiteral *) = 0;
        virtual void visit(StringLiteral *) = 0;
        virtual void visit(IdentExpr *) = 0;
        virtual void visit(InfixExpr *) = 0;
        virtual void visit(PrefixExpr *) = 0;
        virtual void visit(PostfixExpr *) = 0;
        virtual void visit(CallExpr *) = 0;
    };
}

#endif
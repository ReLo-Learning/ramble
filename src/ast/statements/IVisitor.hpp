#pragma once

#ifndef IVISITOR_HPP
#define IVISITOR_HPP

#include "IStmt.hpp"

namespace AST
{

    class VarDecl;
    class FuncDecl;
    class BlockStmt;
    class ExprStmt;
    class RetStmt;
    class ExternStmt;

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
    };
}

#endif
// Copyright 2025 Logan Reuter. All rights reserved


#pragma once

#ifndef HIR_VAR_DECL
#define HIR_VAR_DECL

#include "../hir.hpp"
#include "../HVisitor.hpp"

namespace HIR
{

    class VarDecl : public HStmt
    {
    public:
    Token ident;
    std::unique_ptr<Type::IType> type;
    std::unique_ptr<AST::IExpr> expr;

    VarDecl(Token ident, std::unique_ptr<Type::IType> type, std::unique_ptr<AST::IExpr> expr) : ident(ident), type(std::move(type)), expr(std::move(expr)) {}
    // ~VarDecl();

    void accept(HVisitor *v);
    std::string str();

    };
}

#endif
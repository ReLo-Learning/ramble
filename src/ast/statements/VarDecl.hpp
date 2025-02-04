#pragma once

#ifndef VARDECL_HPP
#define VARDECL_HPP

#include "../IVisitor.hpp"

namespace AST{
    /*
    [let | const] ident {: Type} {= Expr}
    */
    class VarDecl : public IStmt
    {
    public:
        Token Ident;
        std::unique_ptr<Type::IType> Type;
        std::unique_ptr<IExpr> expr;
        bool constant;
        bool uninitialized;
        
        VarDecl(Token Ident, std::unique_ptr<Type::IType> Type, bool constant, std::unique_ptr<IExpr> expr) : Ident(Ident), Type(std::move(Type)), constant(constant), expr(std::move(expr)) {}
        VarDecl(Token Ident, std::unique_ptr<Type::IType> Type, std::unique_ptr<IExpr> expr) : Ident(Ident), Type(std::move(Type)), expr(std::move(expr)) {}
        VarDecl(Token Ident, std::unique_ptr<Type::IType> Type) : Ident(Ident), Type(std::move(Type)) {}
        VarDecl(Token Ident, std::unique_ptr<IExpr> expr) : Ident(Ident), expr(std::move(expr)) {}
        bool isConstant();
        bool isUninitialized();
        void accept(IVisitor *);
        std::string str();
    };
}

#endif
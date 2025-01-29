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
    private:
        Token Ident;
        std::unique_ptr<Type::IType> Type;
        std::unique_ptr<IExpr> expr;
        bool isConstant;

    public:
        VarDecl(Token Ident, std::unique_ptr<Type::IType> Type, bool isConstant, std::unique_ptr<IExpr> expr) : Ident(Ident), Type(std::move(Type)), isConstant(isConstant), expr(std::move(expr)) {}
        VarDecl(Token Ident, std::unique_ptr<Type::IType> Type, std::unique_ptr<IExpr> expr) : Ident(Ident), Type(std::move(Type)), expr(std::move(expr)) {}
        VarDecl(Token Ident, std::unique_ptr<Type::IType> Type) : Ident(Ident), Type(std::move(Type)) {}
        VarDecl(Token Ident, std::unique_ptr<IExpr> expr) : Ident(Ident), expr(std::move(expr)) {}
        void accept(IVisitor *);
        std::string str();
    };
}

#endif
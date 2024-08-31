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
        Token Type;
        std::unique_ptr<IExpr> expr;
        bool isConstant;

    public:
        VarDecl(Token Ident, Token Type, bool isConstant, std::unique_ptr<IExpr> expr) : Ident(Ident), Type(Type), isConstant(isConstant), expr(std::move(expr)) {}
        VarDecl(Token Ident, Token Type, std::unique_ptr<IExpr> expr) : Ident(Ident), Type(Type), expr(std::move(expr)) {}
        VarDecl(Token Ident, Token Type) : Ident(Ident), Type(Type) {}
        VarDecl(Token Ident, std::unique_ptr<IExpr> expr) : Ident(Ident), expr(std::move(expr)) {}
        void accept(IVisitor *);
        std::string str();
    };
}

#endif
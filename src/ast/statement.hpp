#pragma once

#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <memory>

#include "expression.hpp"

class Stmt
{
public:
    virtual ~Stmt() = default;

    void print() {}
};

class VarDecl : public Stmt
{
    Token Ident;
    std::unique_ptr<Expr> expr;

public:
    VarDecl(Token Ident, std::unique_ptr<Expr> expr) : Ident(Ident), expr(std::move(expr)) {}

    void print()
    {
        std::cout << TokenKind[this->Ident.kind()]; 
        this->expr->print();
        std::cout << std::endl;
    }
};

#endif
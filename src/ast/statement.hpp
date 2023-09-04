#pragma once

#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <memory>

#include "expression.hpp"

class Stmt
{
public:
    virtual ~Stmt() = default;
};

class VarDecl : public Stmt
{
    Token Ident;
    std::unique_ptr<Expr> expr;

public:
    VarDecl(Token Ident, std::unique_ptr<Expr> expr) : Ident(Ident), expr(std::move(expr)) {}
};

#endif
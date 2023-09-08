#pragma once

#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <memory>
#include <iostream>

#include "../lexer/lexer.hpp"
#include "../hir/hir.hpp"

class Expr
{
public:
    virtual ~Expr() = default;

    virtual std::unique_ptr<HIR::Expr> lower() = 0;

    virtual std::string str() { return ""; } 
};

class IntExpr: public Expr
{
    int val;

public:
    IntExpr(int val) : val(val) {}

    std::unique_ptr<HIR::Expr> lower() { return std::make_unique<HIR::Literal<int>>(); };

    std::string str() { return std::to_string(val); }
};

class FloatExpr: public Expr
{
    double val;

public:
    FloatExpr(double val) : val(val) {}

    std::string str() { return std::to_string(val); }
};

class IdentExpr: public Expr
{
    std::string ident;

public:
    IdentExpr(std::string ident) : ident(ident) {}

    std::ostream &print(std::ostream &os) { return os << this->ident; }
};

// (Expr)(Op)(Expr)
class InfixExpr: public Expr
{
    Token Op;
    std::unique_ptr<Expr> LHS, RHS;

public:
    InfixExpr(Token Op, std::unique_ptr<Expr> LHS, std::unique_ptr<Expr> RHS) : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}

    std::ostream &print(std::ostream &os) { return os << LHS << getType(Op.kind()) << RHS; }
};

// (Op)(Expr)
class PrefixExpr: public Expr
{
    Token Op;
    std::unique_ptr<Expr> RHS;

public:
    PrefixExpr(Token Op, std::unique_ptr<Expr> RHS) : Op(Op), RHS(std::move(RHS)) {}
};

// (Expr)(Op)
class PostfixExpr: public Expr
{
    Token Op;
    std::unique_ptr<Expr> LHS;

public:
    PostfixExpr(Token Op, std::unique_ptr<Expr> LHS) : Op(Op), LHS(std::move(LHS)) {}
};

#endif
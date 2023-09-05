#pragma once

#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <memory>
#include <iostream>

#include "../lexer/lexer.hpp"

class Expr
{
public:
    virtual ~Expr() = default;

    virtual void print() {} 
};

class IntExpr: public Expr
{
    int val;

public:
    IntExpr(int val) : val(val) {} 

    void print() { std::cout << this->val; }
};

class FloatExpr: public Expr
{
    double val;

public:
    FloatExpr(double val) : val(val) {}
};

class IdentExpr: public Expr
{
    std::string ident;

public:
    IdentExpr(std::string ident) : ident(ident) {}
};

// (Expr)(Op)(Expr)
class InfixExpr: public Expr
{
    Token Op;
    std::unique_ptr<Expr> LHS, RHS;

public:
    InfixExpr(Token Op, std::unique_ptr<Expr> LHS, std::unique_ptr<Expr> RHS) : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
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
#pragma once

#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <memory>
#include <iostream>
#include <type_traits>

#include "../lexer/lexer.hpp"
#include "../hir/hir.hpp"

namespace AST
{

class ExprVisitor;

// Base class
class IExpr
{
public:
    virtual ~IExpr() = default;
    virtual void accept(ExprVisitor *v) = 0;
    virtual std::string str() = 0;
};

class EmptyExpr;
class IntLiteral;
class FloatLiteral;
class IdentExpr;
class InfixExpr;
class PrefixExpr;
class PostfixExpr;
class ExprVisitor
{
public:
    virtual void visit(EmptyExpr *expr);
    virtual void visit(IntLiteral *expr);
    virtual void visit(FloatLiteral *expr);
    virtual void visit(IdentExpr *expr);
    virtual void visit(InfixExpr *expr);
    virtual void visit(PrefixExpr *expr);
    virtual void visit(PostfixExpr *expr);
};

class EmptyExpr: public IExpr
{
public:
    EmptyExpr() {};
    void accept(ExprVisitor *v) { v->visit(this); };
    std::string str() { return ""; };
};

class IntLiteral: public IExpr
{
private:
    int m_value;

public:
    IntLiteral(int value) : m_value(value) {};
    void accept(ExprVisitor *v) { v->visit(this); };
    std::string str() { return std::to_string(m_value); };
};

class FloatLiteral : public IExpr
{
private:
    float m_value;

public:
    FloatLiteral(float value) : m_value(value) {};
    void accept(ExprVisitor *v) { v->visit(this); }
    std::string str() { return std::to_string(m_value); }
};

class IdentExpr: public IExpr
{
private:
    std::string m_ident;

public:
    IdentExpr(std::string ident) : m_ident(ident) {}
    void accept(ExprVisitor *v) { v->visit(this); }
    std::string str() { return m_ident; }
};

// (Expr)(Op)(Expr)
class InfixExpr: public IExpr
{
private:
    Token Op;
    std::unique_ptr<IExpr> LHS, RHS;

public:
    InfixExpr(Token Op, std::unique_ptr<IExpr> LHS, std::unique_ptr<IExpr> RHS) : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
    void accept(ExprVisitor *v) { v->visit(this); }
    std::string str() { return "( " + LHS->str() + " " + getType(Op.kind()) + " " + RHS->str() + " )"; }
};

// (Op)(Expr)
class PrefixExpr: public IExpr
{
    Token Op;
    std::unique_ptr<IExpr> RHS;

public:
    PrefixExpr(Token Op, std::unique_ptr<IExpr> RHS) : Op(Op), RHS(std::move(RHS)) {}
};

// (Expr)(Op)
class PostfixExpr: public IExpr
{
    Token Op;
    std::unique_ptr<IExpr> LHS;

public:
    PostfixExpr(Token Op, std::unique_ptr<IExpr> LHS) : Op(Op), LHS(std::move(LHS)) {}
};

}

#endif
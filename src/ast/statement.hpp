#pragma once

#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <memory>

#include "expression.hpp"

namespace AST
{
class Visitor;

class IStmt
{
public:
    virtual ~IStmt() = default;
    virtual void accept(class Visitor *) = 0;
};

class VarDecl;
class UninitVarDecl;

class Visitor
{
public:
    virtual void visit(VarDecl *) = 0;
    virtual void visit(UninitVarDecl *) = 0;
};

class VarDecl : public IStmt
{
private:
    Token Ident;
    std::unique_ptr<IExpr> expr;

public:
    VarDecl(Token Ident, std::unique_ptr<IExpr> expr) : Ident(Ident), expr(std::move(expr)) {}
    void accept(Visitor *);
};

class UninitVarDecl : public IStmt
{
private:
    Token Ident;
    Kind Type;

public:
    UninitVarDecl(Token Ident, Kind Type) : Ident(Ident), Type(Type) {}
    void accept(Visitor *);
};

}


#endif
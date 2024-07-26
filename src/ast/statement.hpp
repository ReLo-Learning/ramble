#pragma once

#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <memory>

#include "expression.hpp"
#include "type.hpp"

namespace AST
{
class Visitor;

class IStmt
{
public:
    virtual ~IStmt() = default;
    virtual void accept(class Visitor *) = 0;
    virtual std::string str() = 0;
};

class VarDecl;
class FuncDecl;
class BlockStmt;
class ExprStmt;

class Visitor
{
public:
    virtual void visit(VarDecl *) = 0;
    virtual void visit(FuncDecl *) = 0;
    virtual void visit(BlockStmt *) = 0;
    virtual void visit(ExprStmt *) = 0;
};

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
    void accept(Visitor *);
    std::string str() { return "{Variable: " + this->Ident.value + " " + this->expr->str() + "}"; };
};

class FuncParams
{
private:
    Token m_ident;
    std::unique_ptr<IType> m_type;
    std::unique_ptr<BlockStmt> m_body;

public:
    FuncParams(Token ident, std::unique_ptr<IType> type) : m_ident(ident), m_type(std::move(type)) {};
    std::string str() { return "{Param: " + m_ident.value + " : " + m_type->str() + " }"; };
};

class FuncDecl : public IStmt
{
private:
    Token m_ident;
    std::unique_ptr<IType> m_type;
    std::vector<FuncParams> m_params;
    std::unique_ptr<IStmt> m_body;

public:
    FuncDecl(Token ident) :  m_ident(ident) {};
    FuncDecl(Token ident, std::unique_ptr<IType> type) : m_ident(ident), m_type(std::move(type)) {};
    void accept(Visitor *v) { v->visit(this); }
    void addBody(std::unique_ptr<IStmt> body) { this->m_body = std::move(body); }
    std::string str() { return "{Func: " + m_ident.value + "\n" + this->m_body->str() + " }"; };
};

class BlockStmt : public IStmt
{
private:
    std::vector<std::unique_ptr<IStmt>> m_stmts;

public:
    BlockStmt() {};

    void accept(Visitor *v) { v->visit(this); }

    void addStmt(std::unique_ptr<IStmt> stmt) { this->m_stmts.push_back(std::move(stmt)); }

    std::string str()
    {
        std::stringstream ss;
        ss << "{BlockStmt: ";

        for (auto &stmt : this->m_stmts)
        {
            ss << "\n\t" << stmt->str();
        }

        ss << "\n}";

        return ss.str();
    }
};

class ExprStmt : public IStmt
{
private:
    std::unique_ptr<IExpr> expr;

public:
    ExprStmt(std::unique_ptr<IExpr> expr) : expr(std::move(expr)) {}
    void accept(Visitor *);
    std::string str() { return "{ " + this->expr->str() + " }"; }
};

}


#endif
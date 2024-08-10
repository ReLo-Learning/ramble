#pragma once

#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include "statements/IStmt.hpp"
#include "statements/IVisitor.hpp"

#include "statements/VarDecl.hpp"
#include "statements/FuncDecl.hpp"
#include "statements/BlockStmt.hpp"
#include "statements/ExprStmt.hpp"
#include "statements/RetStmt.hpp"

// #include <memory>

// #include "expression.hpp"
// #include "../types/type.hpp"

// namespace AST
// {
// class Visitor;

// class IStmt
// {
// public:
//     virtual ~IStmt() = default;
//     virtual void accept(class Visitor *) = 0;
//     virtual std::string str() = 0;
// };

// class VarDecl;
// class FuncDecl;
// class BlockStmt;
// class ExprStmt;

// class Visitor
// {
// public:
//     virtual void visit(VarDecl *) = 0;
//     virtual void visit(FuncDecl *) = 0;
//     virtual void visit(BlockStmt *) = 0;
//     virtual void visit(ExprStmt *) = 0;
// };

// /*
// [let | const] ident {: Type} {= Expr}
// */
// class VarDecl : public IStmt
// {
// private:
//     Token Ident;
//     Token Type;
//     std::unique_ptr<IExpr> expr;
//     bool isConstant;

// public:
//     VarDecl(Token Ident, Token Type, bool isConstant, std::unique_ptr<IExpr> expr) : Ident(Ident), Type(Type), isConstant(isConstant), expr(std::move(expr)) {}
//     VarDecl(Token Ident, Token Type, std::unique_ptr<IExpr> expr) : Ident(Ident), Type(Type), expr(std::move(expr)) {}
//     VarDecl(Token Ident, Token Type) : Ident(Ident), Type(Type) {}
//     VarDecl(Token Ident, std::unique_ptr<IExpr> expr) : Ident(Ident), expr(std::move(expr)) {}
//     void accept(Visitor *);
//     std::string str() { return "{Variable: " + this->Ident.value + " " + this->expr->str() + "}"; };
// };



// class BlockStmt : public IStmt
// {
// private:
//     std::vector<std::unique_ptr<IStmt>> m_stmts;

// public:
//     BlockStmt() {};

//     void accept(Visitor *v) { v->visit(this); }

//     void addStmt(std::unique_ptr<IStmt> stmt) { this->m_stmts.push_back(std::move(stmt)); }

//     std::string str()
//     {
//         std::stringstream ss;
//         ss << "{BlockStmt: ";

//         for (auto &stmt : this->m_stmts)
//         {
//             ss << "\n\t" << stmt->str();
//         }

//         ss << "\n}";

//         return ss.str();
//     }
// };

// class ExprStmt : public IStmt
// {
// private:
//     std::unique_ptr<IExpr> expr;

// public:
//     ExprStmt(std::unique_ptr<IExpr> expr) : expr(std::move(expr)) {}
//     void accept(Visitor *);
//     std::string str() { return "{ " + this->expr->str() + " }"; }
// };

// }


#endif
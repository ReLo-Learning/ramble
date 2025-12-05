#pragma once

#ifndef TYPE_CHECK_HPP
#define TYPE_CHECK_HPP

#include <memory>
#include <vector>
#include <unordered_map>

#include "../ast/ast.hpp"

enum SymbolType
{
    EMPTY,
    STRUCT,
    ENUM,
    UNION,
    FUNC,
    VARIABLE,
};

struct Symbol
{
    SymbolType type;
    std::unique_ptr<AST::IStmt> &entry;
    std::string ident;
};

class SymbolTable
{
private:
    std::string m_scope;
    std::unordered_map<std::string, Symbol> table;

public:
    SymbolTable(std::string scope) : m_scope(scope) {};

    int insert(std::string name, Symbol sym);

    bool lookup(std::string name);

    Symbol get(std::string name);
};

class TypeChecker : AST::IVisitor {
private:
    std::vector<SymbolTable> scope;
    unsigned int depth;

    int insert(std::string name, Symbol sym);

    int lookup(std::string name);

    Symbol get(std::string name);

    void remove();

public:
    TypeChecker(AST::Program &prog);

    void visit(AST::VarDecl *) = 0;
    void visit(AST::FuncDecl *) = 0;
    void visit(AST::BlockStmt *) = 0;
    void visit(AST::ExprStmt *) = 0;
    void visit(AST::RetStmt *) = 0;
    void visit(AST::ExternStmt *) = 0;

    void visit(AST::IntLiteral *) = 0;
    void visit(AST::FloatLiteral *) = 0;
    void visit(AST::RuneLiteral *) = 0;
    void visit(AST::StringLiteral *) = 0;
    void visit(AST::IdentExpr *) = 0;
    void visit(AST::InfixExpr *) = 0;
    void visit(AST::PrefixExpr *) = 0;
    void visit(AST::PostfixExpr *) = 0;
    void visit(AST::CallExpr *) = 0;
};

#endif
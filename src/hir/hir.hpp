#pragma once

#ifndef HIR_HPP
#define HIR_HPP

#include <map>
#include <vector>
#include <memory>
#include <string>
#include <map>

#include "../ast/ast.hpp"
#include "expressions/expressions.hpp"
#include "statements/statements.hpp"

namespace HIR
{
class IR
{
public:
    std::vector<std::unique_ptr<HStmt>> TypeDefs;
    std::vector<std::unique_ptr<HStmt>> FuncProtos;
    std::vector<std::unique_ptr<HStmt>> FuncDefs;
    std::vector<std::unique_ptr<HStmt>> Globals;

    IR() = default;
    ~IR() = default;

    void print();

};

class Walker : public AST::IVisitor
{
public:
    std::unique_ptr<IR> ir = std::make_unique<IR>();

    Walker() = default;
    ~Walker() = default;

    void visit(AST::VarDecl *);
    void visit(AST::FuncDecl *);
    void visit(AST::BlockStmt *);
    void visit(AST::ExprStmt *);
    void visit(AST::RetStmt *);
    void visit(AST::ExternStmt *);

    void visit(AST::IntLiteral *);
    void visit(AST::FloatLiteral *);
    void visit(AST::RuneLiteral *);
    void visit(AST::StringLiteral *);
    void visit(AST::IdentExpr *);
    void visit(AST::InfixExpr *);
    void visit(AST::PrefixExpr *);
    void visit(AST::PostfixExpr *);
    void visit(AST::CallExpr *);
};

std::unique_ptr<IR> Lower(AST::Program* program);
}


#endif
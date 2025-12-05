#pragma once

#ifndef C_CODEGEN_HPP
#define C_CODEGEN_HPP

#include <fstream>
#include "../hir/hir.hpp"

namespace C_Codegen
{

class Codegen : AST::IVisitor {
private:
    std::ofstream *file;

public:
    Codegen(std::ofstream *f);
    ~Codegen() = default;

    void walk(std::vector<std::unique_ptr<AST::IStmt>> stmt_list);

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

}

#endif
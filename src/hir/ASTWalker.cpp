#include "hir.hpp"

namespace HIR
{
void Walker::visit(AST::VarDecl *ast) 
{
    this->ir->Globals.push_back(std::make_unique<VarDecl>(ast->Ident, std::move(ast->Type), std::move(ast->expr)));
};
void Walker::visit(AST::FuncDecl *ast) {};
void Walker::visit(AST::BlockStmt *ast) {};
void Walker::visit(AST::ExprStmt *ast) {};
void Walker::visit(AST::RetStmt *ast) {};
void Walker::visit(AST::ExternStmt *ast) {};

void Walker::visit(AST::IntLiteral *ast) {};
void Walker::visit(AST::FloatLiteral *ast) {};
void Walker::visit(AST::RuneLiteral *ast) {};
void Walker::visit(AST::StringLiteral *ast) {};
void Walker::visit(AST::IdentExpr *ast) {};
void Walker::visit(AST::InfixExpr *ast) {};
void Walker::visit(AST::PrefixExpr *ast) {};
void Walker::visit(AST::PostfixExpr *ast) {};
void Walker::visit(AST::CallExpr *ast) {};
}
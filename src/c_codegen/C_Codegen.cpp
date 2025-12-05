#include "C_Codegen.hpp"

namespace C_Codegen
{
Codegen::Codegen(std::ofstream *f)
{
    this->file = f;
    
    *this->file << "#include <stdint.h>\n";
}

void Codegen::walk(std::vector<std::unique_ptr<AST::IStmt>> stmt_list)
{
    for(const auto& stmt : stmt_list)
    {
        stmt->accept(this);
    }
}

void Codegen::visit(AST::VarDecl *vd)
{
    *this->file << vd->m_type->codegen() << " ";
    *this->file << vd->m_ident.value << " = " << vd->m_expr->str();
    *this->file << ";\n";
}

void Codegen::visit(AST::FuncDecl *fd) {};
void Codegen::visit(AST::BlockStmt *bs) {};
void Codegen::visit(AST::ExprStmt *es) {};
void Codegen::visit(AST::RetStmt *rs) {};
void Codegen::visit(AST::ExternStmt *es) {};

void Codegen::visit(AST::IntLiteral *il) {};
void Codegen::visit(AST::FloatLiteral *fl) {};
void Codegen::visit(AST::RuneLiteral *rl) {};
void Codegen::visit(AST::StringLiteral *sl) {};
void Codegen::visit(AST::IdentExpr *i) {};
void Codegen::visit(AST::InfixExpr *ie) {};
void Codegen::visit(AST::PrefixExpr *pe) {};
void Codegen::visit(AST::PostfixExpr *pe) {};
void Codegen::visit(AST::CallExpr *ce) {};
}
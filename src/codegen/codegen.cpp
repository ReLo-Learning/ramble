#include "codegen.hpp"

namespace Codegen
{
    std::string Visitor::str() { return this->m_content.str(); }

    void Visitor::visit(AST::ExternStmt *stmt)
    {
        stmt->stmt()->accept(this);
    }

    void Visitor::visit(AST::FuncDecl *func)
    {
        if (func->isProto())
            this->m_content << "declare";
        else
            this->m_content << "define";
        
        this->m_content << " ";

        this->m_content << "i32" << " ";

        this->m_content << "@" << func->ident();

        this->m_content << "(";

        if (func->isProto())
        {
            auto params = func->params();

            std::string separator = "";

            for(auto const &param : params)
            {
                this->m_content << separator << param->type()->codegen();
                separator = ",";
            }
        }

        this->m_content << ")" << " nounwind";

        if (func->isProto())
            this->m_content << "\n";
        else
        {
            this->m_content << " ";
            func->body()->accept(this);
        }

    }

    void Visitor::visit(AST::VarDecl *stmt) {};
    // void Visitor::visit(AST::FuncDecl *stmt) {};
    void Visitor::visit(AST::BlockStmt *stmt) 
    {
        this->m_content << "{\n";

        this->m_content <<"}\n";
    };
    void Visitor::visit(AST::ExprStmt *stmt) {};
    void Visitor::visit(AST::RetStmt *stmt) {};
    // void Visitor::visit(AST::ExternStmt *stmt) {};

    void generate(std::unique_ptr<AST::Program> program)
    {
        Visitor v;

        auto statements = program->statements();

        for (auto const &statement : statements)
        {
            statement->accept(&v);
        }

        std::cout << v.str();
    }
}
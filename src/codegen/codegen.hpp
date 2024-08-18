#pragma once

#ifndef CODEGEN_HPP
#define CODEGEN_HPP

#include "../ast/ast.hpp"
#include <sstream>

namespace Codegen
{
    class Visitor : public AST::IVisitor
    {
        private:
            std::stringstream m_content;
        public:
        Visitor() = default;

        std::string str();

        void visit(AST::VarDecl *);
        void visit(AST::FuncDecl *);
        void visit(AST::BlockStmt *);
        void visit(AST::ExprStmt *);
        void visit(AST::RetStmt *);
        void visit(AST::ExternStmt *);
    };

    void generate(std::unique_ptr<AST::Program> program);
}

#endif
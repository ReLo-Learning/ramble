#include "FuncDecl.hpp"

namespace AST
{
    void FuncDecl::accept(IVisitor *v) { v->visit(this); }

    void FuncDecl::addBody(std::unique_ptr<IStmt> body)
    {
        this->m_body = std::move(body);
    }

    void FuncDecl::addRetType(std::unique_ptr<Type::IType> retType)
    {
        this->m_retType = std::move(retType);
    }

    std::string FuncDecl::str()
    {
        return "{Func: " + m_ident.value + "\n" + this->m_body->str() + " }";
    }
}
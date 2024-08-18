#include "FuncDecl.hpp"

namespace AST
{
    void FuncDecl::accept(IVisitor *v) { v->visit(this); }

    void FuncDecl::addParam(std::unique_ptr<FuncParams> param)
    {
        this->m_params.push_back(std::move(param));
    }

    void FuncDecl::addBody(std::unique_ptr<IStmt> body)
    {
        this->m_body = std::move(body);
    }

    void FuncDecl::addRetType(std::unique_ptr<Type::IType> retType)
    {
        this->m_retType = std::move(retType);
    }

    std::unique_ptr<IStmt> FuncDecl::body()
    {
        return std::move(this->m_body);
    }

    bool FuncDecl::isProto()
    {
        if (this->m_body)
            return false;
        
        return true;
    }

    std::vector<std::unique_ptr<FuncParams>> FuncDecl::params()
    {
        return std::move(this->m_params);
    }

    std::string FuncDecl::ident() { return m_ident.value; }

    std::string FuncDecl::str()
    {
        return "{Func: " + m_ident.value + " }";
    }
}
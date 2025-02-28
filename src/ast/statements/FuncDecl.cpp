#include "FuncDecl.hpp"

namespace AST
{
    std::string FuncParams::str()
    {
        std::stringstream ss;
        ss << "{Parameter:\n";
        ss << std::left << std::setw(10) << "Arg: " << this->m_ident.value << "\n";
        ss << std::left << std::setw(10) << "Type: " << this->m_type->str() << "\n";
        ss << "}\n";

        return ss.str(); 
    }

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
        std::stringstream ss;
        ss << "{\n";
        ss << std::left << std::setw(10) << "Function: " << this->m_ident.value << "\n";

        ss << "Args: [";

        if (this->m_params.size() > 0)
            ss << "\n";

        for (auto& param : m_params)
            ss << param->str();

        ss << "]\n";

        ss << std::left << std::setw(10) << "Return_Type: " << this->m_retType->str() << "\n";
        ss << "Body:\n";
        ss << this->m_body->str() << "\n";
        ss << "}\n";

        return ss.str();
    }
}
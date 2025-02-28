#include "VarDecl.hpp"

namespace AST
{
    void VarDecl::accept(IVisitor *v) { v->visit(this); }

    std::string VarDecl::str() 
    {
        std::stringstream ss;
        ss << "{ Variable Declaration:\n";

        ss << "   " << std::left << std::setw(10) << "Variable: " << this->m_ident.value << "\n";

        ss << "   " << std::left << std::setw(10) << "Type: " << this->m_type->str() << "\n";

        ss << "   " << std::left << std::setw(10) << "Value: " << this->m_expr->str() << "\n";

        ss << "}\n";

        return ss.str(); 
    };

    bool VarDecl::isConstant() { return this->constant; }
    bool VarDecl::isUninitialized() { return this->uninitialized; }
}
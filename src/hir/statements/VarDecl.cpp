#include "VarDecl.hpp"

namespace HIR 
{
    void VarDecl::accept(HVisitor *v) { v->visit(this); }

    std::string VarDecl::str()
    {
        return this->type->str() + " " + this->ident.value + " = " + this->expr->str() + ";\n";
    }
}
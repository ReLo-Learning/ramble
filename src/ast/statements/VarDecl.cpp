#include "VarDecl.hpp"

namespace AST
{
    void VarDecl::accept(IVisitor *v) { v->visit(this); }

    std::string VarDecl::str() 
    { 
        return "{Variable: " + this->Ident.value + " " + this->expr->str() + "}"; 
    };
}
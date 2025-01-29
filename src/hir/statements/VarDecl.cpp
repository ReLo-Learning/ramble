#include "VarDecl.hpp"

namespace HIR 
{
    VarDecl::VarDecl()
    {
        std::cout << "I am creating a variable declaration\n";
    }

    void VarDecl::accept(HVisitor *v) { v->visit(this); }

    std::string VarDecl::str() { return "VarDecl::str() hasnt been created yet"; }
}
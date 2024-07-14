#include "statement.hpp"

namespace AST
{
    void VarDecl::accept(Visitor *v) { v->visit(this); }
    void UninitVarDecl::accept(Visitor *v) { v->visit(this); }
}
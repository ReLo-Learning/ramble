#include "IntLiteral.hpp"

namespace AST
{
    void IntLiteral::accept(IVisitor *v) {v->visit(this);}
}
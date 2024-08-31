#include "PrefixExpr.hpp"

namespace AST
{
    void PrefixExpr::accept(IVisitor *v) {v->visit(this);}
}
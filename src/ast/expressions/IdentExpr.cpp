#include "IdentExpr.hpp"

namespace AST
{
    void IdentExpr::accept(IVisitor *v) { v->visit(this); }
}
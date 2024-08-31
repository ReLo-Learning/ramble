#include "CallExpr.hpp"

namespace AST
{
    void CallExpr::accept(IVisitor *v) { v->visit(this); }
}
#include "PostfixExpr.hpp"

namespace AST
{
    void PostfixExpr::accept(IVisitor *v) { v->visit(this); }
}
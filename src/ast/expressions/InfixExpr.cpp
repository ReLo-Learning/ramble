#include "InfixExpr.hpp"

namespace AST
{
    void InfixExpr::accept(IVisitor *v) {v->visit(this);}
}
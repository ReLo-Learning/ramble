#include "FloatLiteral.hpp"

namespace AST
{
    void FloatLiteral::accept(IVisitor *v) { v->visit(this); }
}
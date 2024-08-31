#include "StringLiteral.hpp"

namespace AST
{
    void StringLiteral::accept(IVisitor *v) { v->visit(this); }
}
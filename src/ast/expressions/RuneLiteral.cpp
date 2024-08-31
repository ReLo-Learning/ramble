#include "RuneLiteral.hpp"

namespace AST
{
    void RuneLiteral::accept(IVisitor *v) {v->visit(this);}
}
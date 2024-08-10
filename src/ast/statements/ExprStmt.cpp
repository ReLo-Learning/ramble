#include "ExprStmt.hpp"

namespace AST
{
    void ExprStmt::accept(IVisitor *v) { v->visit(this); }
    std::string ExprStmt::str() { return this->m_expr->str(); }
}
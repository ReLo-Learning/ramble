#include "RetStmt.hpp"

namespace AST
{
    void RetStmt::accept(IVisitor *v) { v->visit(this); }
    std::string RetStmt::str() { return "Return: " + this->m_ret->str(); }
}
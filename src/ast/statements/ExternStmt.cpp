#include "ExternStmt.hpp"

namespace AST
{
    void ExternStmt::accept(IVisitor *v) { v->visit(this); }
    std::string ExternStmt::str() { return "Extern" + this->m_stmt->str(); }
    std::unique_ptr<IStmt> ExternStmt::stmt() {return std::move(this->m_stmt); };
}
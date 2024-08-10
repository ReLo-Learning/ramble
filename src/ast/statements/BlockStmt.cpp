#include "BlockStmt.hpp"

namespace AST
{
    void BlockStmt::accept(IVisitor *v) { v->visit(this); }

    void BlockStmt::addStmt(std::unique_ptr<IStmt> stmt) { this->m_stmts.push_back(std::move(stmt)); }

    std::string BlockStmt::str()
    {
        std::stringstream ss;
        ss << "{BlockStmt: ";

        for (auto &stmt : this->m_stmts)
        {
            ss << "\n\t" << stmt->str();
        }

        ss << "\n}";

        return ss.str();
    }
}
#include "CallExpr.hpp"

namespace AST
{
    void CallExpr::accept(IVisitor *v) { v->visit(this); }

    std::string CallExpr::str()
    {
        std::stringstream ss;

        ss << this->m_ident.val() << "(";

        for (auto &arg: m_args)
        {
            ss << arg->str() << ",";
        }

        return ss.str();
    }
}
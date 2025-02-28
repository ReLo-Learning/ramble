#include "InfixExpr.hpp"

namespace AST
{
    void InfixExpr::accept(IVisitor *v) {v->visit(this);}

    std::string InfixExpr::str() 
    {
        std::stringstream ss;

        ss << "{ Infix Expression:\n";
        ss << "   " << std::left << std::setw(10) << "LHS: " << LHS->str() << "\n";
        ss << "   " << std::left << std::setw(10) << "Op: " << getType(Op.kind()) << "\n";
        ss << "   " << std::left << std::setw(10) << "RHS: " << RHS->str() << "\n";
        ss << "}\n";

        return ss.str();
    }
}
#include "expression.hpp"

std::string AST::InfixExpr::str()
{
    std::string buff;
    buff.append(LHS->str());
    buff.append(getType(Op.kind()));
    buff.append(RHS->str());
    return buff;
};


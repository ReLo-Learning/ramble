#pragma once

#ifndef HVISITOR_HPP
#define HVISITOR_HPP

#include "statements/statements.hpp"
#include "expressions/expressions.hpp"

namespace HIR
{

class VarDecl;

class HVisitor
{
public:
    ~HVisitor() = default;
    
    virtual void visit(VarDecl *) = 0;
};


}

#endif
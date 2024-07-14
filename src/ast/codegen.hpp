#pragma once

#ifndef CODEGEN_HPP
#define CODEGEN_HPP

#include <memory>
#include <map>
#include <string>

#include "statement.hpp"

namespace AST
{
class Codegen : public Visitor
{
private:

public:
    void visit(VarDecl *stmt);
};
}

#endif
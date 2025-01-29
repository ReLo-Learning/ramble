// Copyright 2025 Logan Reuter. All rights reserved


#pragma once

#ifndef HIR_VAR_DECL
#define HIR_VAR_DECL

#include "../hir.hpp"
#include "../HVisitor.hpp"

namespace HIR
{

class VarDecl : public HStmt
{

public:
VarDecl();
// ~VarDecl();

void accept(HVisitor *v);
std::string str();

};

}

#endif
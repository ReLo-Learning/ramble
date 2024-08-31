#pragma once

#ifndef HIR_FUNC_DEF
#define HIR_FUNC_DEF

#include "HVisitor.hpp"

namespace HIR
{

/*
declare retType ident(types...)
*/

class FuncDef : public HStmt
{
private:

public:
    FuncDef();

};

}

#endif
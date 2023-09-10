#pragma once

#ifndef MIR_HPP
#define MIR_HPP

#include <string>

#include "../codegen/codegen.hpp"

namespace MIR
{

class MIR
{

};

class Expr
{
public:
    virtual ~Expr() = default;

    virtual std::string str() = 0;
    virtual Value *codegen() = 0;
    virtual bool check() = 0;
};

}


#endif
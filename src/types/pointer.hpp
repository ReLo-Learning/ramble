#pragma once

#ifndef POINTER_HPP
#define POINTER_HPP

#include "IType.hpp"

namespace Type
{

class Pointer : public IType
{
private:
    std::unique_ptr<IType> m_underlying;

public:
    Pointer(std::unique_ptr<IType> underlying) : m_underlying(std::move(underlying)) {};
    std::string str();
    std::string codegen();

};

}

#endif
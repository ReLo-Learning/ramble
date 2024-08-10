#pragma once

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "IType.hpp"

namespace Type
{

class Array : public IType
{
private:
    std::unique_ptr<IType> m_underlying;

public:
    Array(std::unique_ptr<IType> underlying) : m_underlying(std::move(underlying)) {}
    std::string str();

};

}

#endif
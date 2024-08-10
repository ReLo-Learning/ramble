#pragma once

#ifndef ITYPE_HPP
#define ITYPE_HPP

#include <string>
#include <memory>

namespace Type
{
    class IType
    {
    public:
        IType() = default;
        virtual ~IType() = default;
        virtual std::string str() = 0;
    };
}

#endif
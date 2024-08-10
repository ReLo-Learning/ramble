#pragma once

#ifndef ISTMT_HPP
#define ISTMT_HPP

#include <memory>
#include <string>
#include <vector>
#include <sstream>

#include "../expression.hpp"

#include "../../types/type.hpp"
#include "../../lexer/token.hpp"

namespace AST
{
    class IVisitor;

    class IStmt
    {
    public:
        IStmt() = default;
        virtual ~IStmt() = default;
        virtual void accept(IVisitor *) = 0;
        virtual std::string str() = 0;
    };
}

#endif
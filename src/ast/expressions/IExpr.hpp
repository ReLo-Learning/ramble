#pragma once

#ifndef IEXPR_HPP
#define IEXPR_HPP

#include <memory>
#include <string>
#include <vector>
#include <sstream>

#include "../expression.hpp"

#include "../../types/type.hpp"
#include "../../lexer/token.hpp"

namespace AST
{
    class ExprVisitor;

    // Base class
    class IExpr
    {
    public:
        virtual ~IExpr() = default;
        virtual void accept(ExprVisitor *v) = 0;
        virtual std::string str() = 0;
    };
}

#endif
#pragma once

#ifndef HEXPER_HPP
#define HEXPER_HPP

#include <string>

namespace HIR
{
    class HVisitor;

    class HExpr
    {
        public:
            ~HExpr() = default;
            virtual void accept(HVisitor *) = 0;
            virtual std::string str() = 0;
    };

}

#endif
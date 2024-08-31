#pragma once

#ifndef HSTMT_HPP
#define HSTMT_HPP

#include <string>

namespace HIR
{
    class HVisitor;

    class HStmt
    {
        public:
            ~HStmt() = default;
            virtual void accept(HVisitor *) = 0;
            virtual std::string str() = 0; 

    };

}

#endif
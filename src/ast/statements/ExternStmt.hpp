#pragma once

#ifndef EXTERNSTMT_HPP
#define EXTERNSTMT_HPP

#include "../IVisitor.hpp"

namespace AST
{
    /*
    extern func ident([args]) -> RetType
    */

    class ExternStmt : public IStmt
    {
    private:
        std::unique_ptr<IStmt> m_stmt;
    
    public:
        ExternStmt(std::unique_ptr<IStmt> stmt) : m_stmt(std::move(stmt)) {};

        void accept(IVisitor *v);

        std::unique_ptr<IStmt> stmt();

        std::string str();
    };
}

#endif
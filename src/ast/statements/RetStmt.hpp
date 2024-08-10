#pragma once

#ifndef RETSTMT_HPP
#define RETSTMT_HPP

#include "IVisitor.hpp"

namespace AST
{
    class RetStmt : public IStmt
    {
        private:
            std::unique_ptr<AST::IExpr> m_ret;
            std::unique_ptr<Type::IType> m_type;
        
        public:
            RetStmt(std::unique_ptr<AST::IExpr> ret) : m_ret(std::move(ret)) {};
            void accept(IVisitor *);
            std::string str();
    };
}

#endif
#pragma once

#ifndef EXPRSTMT_HPP
#define EXPRSTMT_HPP

#include "../IVisitor.hpp"
#include "../expression.hpp"

namespace AST
{
    class ExprStmt : public IStmt
    {
    private:
        std::unique_ptr<IExpr> m_expr;
    
    public:
        ExprStmt(std::unique_ptr<IExpr> expr) : m_expr(std::move(expr)) {};
        void accept(IVisitor *v);
        std::string str();
    };
}

#endif
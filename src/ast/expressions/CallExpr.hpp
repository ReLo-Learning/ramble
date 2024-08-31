#pragma once

#ifndef CALLEXPR_HPP
#define CALLEXPR_HPP

#include "../IVisitor.hpp"

namespace AST
{
    // ident({args})
    class CallExpr : public IExpr
    {
    private:
        std::string m_func;
        std::vector<std::unique_ptr<IExpr>> m_args;

    public:
        CallExpr(std::string func) : m_func(func) {}
        void accept(IVisitor *v);
        void addArg(std::unique_ptr<IExpr> arg) { this->m_args.push_back(std::move(arg)); }
        std::string str() { return this->m_func + "()"; }
    };
}

#endif
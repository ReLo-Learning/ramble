#pragma once

#ifndef HIR_HPP
#define HIR_HPP

#include <map>
#include <vector>
#include <memory>

namespace HIR 
{
    class HIR
    {
        Stmt *program;

    public:
        HIR();        
    };

    class Expr
    {
    public:
        int type;

        virtual ~Expr() = default;

        virtual std::string str() = 0;

        virtual void lower() = 0;

        virtual bool operator==(const Expr& expr) = 0;
    };

    template <typename T>
    class Literal: public Expr
    {
        T value;

    public:
        Literal();
        Literal(int type, T value);

        std::string str() override;

        void lower() override;

        bool operator==(const Expr& expr) override;
    };

    class FuncCall: public Expr
    {
    public:
        FuncCall();
    };

    class Stmt
    {
    public:
        virtual ~Stmt() = default;
    };
}

#endif
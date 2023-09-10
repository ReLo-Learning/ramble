#pragma once

#ifndef HIR_HPP
#define HIR_HPP

#include <map>
#include <vector>
#include <memory>
#include <string>


    class HExpr
    {
    public:
        int type;

        virtual ~HExpr() = default;

        virtual std::string str() = 0;

        virtual void lower() = 0;

        virtual bool operator==(const HExpr& expr) = 0;
    };

    template <typename T>
    class Literal: public HExpr
    {
        T value;

    public:
        Literal();
        Literal(int type, T value);

        std::string str() override;

        void lower() override;

        bool operator==(const HExpr& expr) override;
    };

    class FuncCall: public HExpr
    {
    public:
        FuncCall();
    };

    class HStmt
    {
    public:
        virtual ~HStmt() = default;
    };

    class HIR
    {
        std::unique_ptr<HStmt> program;

    public:
        HIR();
    };


#endif
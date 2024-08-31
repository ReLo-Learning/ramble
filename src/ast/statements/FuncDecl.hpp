#pragma once

#ifndef FUNCDECL_HPP
#define FUNCDECL_HPP

#include "../IVisitor.hpp"
#include "BlockStmt.hpp"

namespace AST
{
    class FuncParams
    {
    private:
        Token m_ident;
        std::unique_ptr<Type::IType> m_type;

    public:
        FuncParams(std::unique_ptr<Type::IType> type) : m_type(std::move(type)) {};
        FuncParams(Token ident, std::unique_ptr<Type::IType> type) : m_ident(ident), m_type(std::move(type)) {};
        std::string str() 
        {
            return "{Param: " + m_type->str() + " }"; 
        };

        std::unique_ptr<Type::IType> type() { return std::move(m_type); }
    };

    class FuncDecl : public IStmt
    {
    private:
        Token m_ident;
        std::unique_ptr<Type::IType> m_retType;
        std::vector<std::unique_ptr<FuncParams>> m_params;
        std::unique_ptr<IStmt> m_body;

    public:
        FuncDecl(Token ident) : m_ident(ident) {};
        FuncDecl(Token ident, std::unique_ptr<Type::IType> retType) : m_ident(ident), m_retType(std::move(retType)) {};
        void accept(IVisitor *v);
        void addParam(std::unique_ptr<FuncParams> param);
        void addBody(std::unique_ptr<IStmt> body);
        void addRetType(std::unique_ptr<Type::IType> retType);
        
        bool isProto();
        std::vector<std::unique_ptr<FuncParams>> params();
        std::string ident();
        std::unique_ptr<IStmt> body();
        std::string str();
    };
}

#endif
#pragma once

#ifndef PARSER_HPP
#define PARSER_HPP

#include <map>
#include <functional>

#include "../lexer/lexer.hpp"
#include "../ast/ast.hpp"
#include "../utils/panic.hpp"
#include "precedence.hpp"

class Parser
{
    private:
        unsigned int m_index;
        const std::vector<Token> m_tokens;

        std::map<Kind, Precedence> precedences;
        std::map<Kind, int> prefixOps;
        std::map<Kind, int> infixOps;
        std::map<Kind, int> postfixOps;

        Token get();
        Token peek();
        Token consume();
        Token next();

        Precedence getPrecedence();
        Precedence peekPrecedence();

        bool expect(Kind kind);
        bool is(Kind kind);
        bool isNot(Kind kind);
        bool peekIsNot(Kind kind);

        std::unique_ptr<AST::IStmt> ParseStatement();
        std::unique_ptr<AST::IExpr> ParseExpression(int precedence = 0);

        std::unique_ptr<AST::IExpr> ParsePrefixExpression();
        std::unique_ptr<AST::IExpr> ParseInfixExpression(std::unique_ptr<AST::IExpr> left);
        std::unique_ptr<AST::IExpr> ParsePostfixExpression(std::unique_ptr<AST::IExpr> left);

        std::unique_ptr<AST::IExpr> ParseIntLiteral();
        std::unique_ptr<AST::IExpr> ParseFloatLiteral();
        // std::unique_ptr<AST::IExpr> ParseRuneLiteral();
        std::unique_ptr<AST::IExpr> ParseStringLiteral();
        std::unique_ptr<AST::IExpr> HandleIdent();

        std::unique_ptr<AST::IStmt> ParseVarDecl();
        std::unique_ptr<AST::IStmt> ParseFuncDecl();
        std::unique_ptr<AST::IStmt> ParseBlockStmt();
        std::unique_ptr<AST::IStmt> ParseExprStmt();
        std::unique_ptr<AST::IStmt> ParseRetStmt();

        public: 
        Parser(std::vector<Token> tokens);

        std::unique_ptr<AST::Program> parse();
};

#endif
#pragma once

#ifndef PARSER_HPP
#define PARSER_HPP

#include "../lexer/lexer.hpp"
#include "../ast/ast.hpp"

class Parser
{
    private:
        unsigned int m_index;
        const std::vector<Token> m_tokens;
        std::unique_ptr<AST::Program> prog;

        Token get();
        Token peek();
        Token consume();

        std::unique_ptr<AST::IExpr> ParseExpression();
        std::unique_ptr<AST::IExpr> ParseIntLiteral();

        std::unique_ptr<AST::IStmt> ParseVarDecl();


    public:
        Parser(std::vector<Token> tokens);

        std::unique_ptr<AST::Program> parse();
};

#endif
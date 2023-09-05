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
        std::unique_ptr<Program> prog;

        Token get();
        Token consume();

        std::unique_ptr<Expr> ParseExpression();
        std::unique_ptr<Expr> ParseIntLiteral();

        std::unique_ptr<Stmt> ParseVarDecl();


    public:
        Parser(std::vector<Token> tokens);

        std::unique_ptr<Program> parse();
};

#endif
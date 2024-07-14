#include "parser.hpp"

#include <string>

std::unique_ptr<AST::IExpr> Parser::ParseExpression()
{
    return ParseIntLiteral();
}

std::unique_ptr<AST::IExpr> Parser::ParseIntLiteral()
{
    Token int_lit = this->consume();
    return std::make_unique<AST::IntLiteral>(std::stoi(int_lit.value));
}
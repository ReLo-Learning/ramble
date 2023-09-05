#include "parser.hpp"

#include <string>

std::unique_ptr<Expr> Parser::ParseExpression()
{
    return ParseIntLiteral();
}

std::unique_ptr<Expr> Parser::ParseIntLiteral()
{
    Token int_lit = this->consume();
    return std::make_unique<IntExpr>(std::stoi(int_lit.value));
}
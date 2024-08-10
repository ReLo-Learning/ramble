#include "../parser.hpp"

std::unique_ptr<AST::IStmt> Parser::ParseExprStmt()
{
    std::unique_ptr<AST::IStmt> stmt = std::make_unique<AST::ExprStmt>(this->ParseExpression());

    if (this->is(SEMI))
        this->next();
    
    return stmt;
}
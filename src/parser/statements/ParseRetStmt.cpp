#include "../parser.hpp"

std::unique_ptr<AST::IStmt> Parser::ParseRetStmt()
{
    // Ignore the RETURN keyword
    this->next();

    std::unique_ptr<AST::IExpr> ret = this->ParseExpression();

    if (this->is(SEMI))
        this->next();
    
    return std::make_unique<AST::RetStmt>(std::move(ret));
}
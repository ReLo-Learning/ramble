#include "../parser.hpp"

std::unique_ptr<AST::IStmt> Parser::ParseExternStmt()
{
    this->next();
    return std::make_unique<AST::ExternStmt>(this->ParseStatement());
}
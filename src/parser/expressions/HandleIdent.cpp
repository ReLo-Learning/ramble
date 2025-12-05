#include "../parser.hpp"

std::unique_ptr<AST::IExpr> Parser::HandleIdent()
{
    return std::make_unique<AST::IdentExpr>(this->consume());
}
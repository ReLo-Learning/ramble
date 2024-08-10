#include "../parser.hpp"

std::unique_ptr<AST::IExpr> Parser::HandleIdent()
{
    Token ident = this->consume();

    if (this->is(LPAREN))
        // Is a function call
        panic("Have not implemented function calls");
    
    return std::make_unique<AST::IdentExpr>(ident.value);
}
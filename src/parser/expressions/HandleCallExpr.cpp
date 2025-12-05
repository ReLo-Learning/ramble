#include "../parser.hpp"

std::unique_ptr<AST::IExpr> Parser::HandleCallExpr()
{
    std::cout << "Call Expr\n"; 
    Token ident = this->consume();
    
    std::unique_ptr<AST::CallExpr> callExpr = std::make_unique<AST::CallExpr>(ident);

    // eat the (
    this->consume();

    while (!this->is(Kind::RPAREN))
    {
        callExpr->addArg(this->ParseExpression(0));

        if (this->expect(Kind::COMMA))
            this->consume();
    }

    if (this->expect(Kind::RPAREN))
        this->consume();

    return std::move(callExpr);
}
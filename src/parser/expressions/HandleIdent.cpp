#include "../parser.hpp"

std::unique_ptr<AST::IExpr> Parser::HandleIdent()
{
    Token ident = this->consume();

    if (this->is(LPAREN))
    {
        this->next();
        // Is a function call
        std::unique_ptr<AST::CallExpr> call = std::make_unique<AST::CallExpr>(ident.value);

        while(this->isNot(RPAREN))
        {
            call->addArg(this->ParseExpression());
        }

        this->next();

        if (this->is(SEMI))
            this->next();

        return call;
    }
    
    return std::make_unique<AST::IdentExpr>(ident.value);
}
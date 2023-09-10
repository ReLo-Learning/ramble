#include "parser.hpp"

// (let | ident) (ident) = (expr) ;
std::unique_ptr<Stmt> Parser::ParseVarDecl()
{
    Token ident = this->consume();
    
    if(ident.kind() != IDENT)
        std::cout << "ERROR" << std::endl;

    if(this->get().kind() != EQ)
        std::cout << "ERROR";
    else
        this->consume();

    std::unique_ptr<Expr> expr = std::move(this->ParseExpression());

    auto s = std::make_unique<VarDecl>(ident, std::move(expr));

    return s;
}
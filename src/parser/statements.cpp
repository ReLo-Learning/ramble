#include "parser.hpp"

// [const | private | unsigned] (let | type) (ident) [= (expr)] ;
std::unique_ptr<AST::IStmt> Parser::ParseVarDecl()
{  
    Token t = this->consume();

    if (!this->expect(IDENT))
        panic("Expected IDENT but did not find it");
    
    Token ident = this->consume();

    if (!this->expect(EQ))
        panic("Expected = but did not find it");
    
    this->next();

    std::unique_ptr<AST::IExpr> expr = this->ParseExpression();

    this->next();

    return std::make_unique<AST::VarDecl>(ident, std::move(expr));
}
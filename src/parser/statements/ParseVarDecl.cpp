#include "../parser.hpp"

// const | let ident [: Type] [= (expr)] ;
std::unique_ptr<AST::IStmt> Parser::ParseVarDecl()
{
    Token start = this->consume();

    bool isConstant = false;
    if (start.is(CONST))
        isConstant = true;

    if (!this->expect(IDENT))
        panic("Expected IDENT but did not find it");

    Token ident = this->consume();

    Token type = Token();

    /*
    TODO:
    Add type class that handles complex types like arrays
    */
    if (this->expect(COLON))
    {
        this->next();
        if (!this->expect(IDENT))
            panic("Type is required following a colon");

        type = this->consume();
    }

    if (!this->expect(EQ))
        panic("Expected = but did not find it");

    this->next();

    std::unique_ptr<AST::IExpr> expr = this->ParseExpression();

    this->next();

    return std::make_unique<AST::VarDecl>(ident, type, std::move(expr));
}
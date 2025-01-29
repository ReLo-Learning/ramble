#include "../parser.hpp"

// const | let ident [: Type] [= (expr)] ;
std::unique_ptr<AST::IStmt> Parser::ParseVarDecl()
{
    // Function called when current token is either let or const
    Token start = this->consume();

    // Check if the variable is constant
    bool isConstant = false;
    if (start.is(CONST))
        isConstant = true;

    // ensure the next token is an ident (this will be variable name)
    if (!this->expect(IDENT))
        panic("Expected IDENT but did not find it");

    // get the variable name
    Token ident = this->consume();

    // throw error if : is not present in variable declaration
    if (!this->expect(COLON))
        this->panic("Missing : in variable declaration");

    // skip the :
    this->next();

    /*
    TODO:
    Add type class that handles complex types like arrays
    */

    // throw error if 
    std::unique_ptr<Type::IType> type = this->ParseType();

    // if (!this->expect(IDENT))
    //     this->panic("Missing type in variable declaration");

    // type = this->consume();

    if (!this->expect(EQ))
        panic("Expected = but did not find it");

    this->next();

    std::unique_ptr<AST::IExpr> expr = this->ParseExpression();

    this->next();

    return std::make_unique<AST::VarDecl>(ident, std::move(type), std::move(expr));
}
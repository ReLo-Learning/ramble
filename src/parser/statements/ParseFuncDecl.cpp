#include "../parser.hpp"

// [private] func ident({Parameters}) [-> ({Types})] BLOCK STATEMENT
std::unique_ptr<AST::IStmt> Parser::ParseFuncDecl()
{
    Token start = this->consume();

    if (!this->expect(IDENT))
        panic("Expected identifier after func");

    Token ident = this->consume();

    std::unique_ptr<AST::FuncDecl> func = std::make_unique<AST::FuncDecl>(ident);

    if (!this->expect(LPAREN))
        panic("Did not find (");
    
    this->next(); // skip the "("
    
    while(!this->expect(RPAREN))
    {
        if (!this->expect(IDENT))
            panic("Expected an identifier");
        
        Token ident = this->consume();

        if (!this->expect(COLON))
            panic("Expected a colon");
        this->next();

        func->addParam( std::make_unique<AST::FuncParams>( ident, this->ParseType() ));

        if (this->expect(COMMA))
            this->next();
    }

    // TODO: Parse parameters here
    // if (this->isNot(RPAREN))
    //     func->addParam( std::make_unique<AST::FuncParams>( this->ParseType() ));

    if (!this->expect(RPAREN))
        panic("Did not find )");
    
    this->next();

    if (this->is(ARWR))
    {
        this->next();

        func->addRetType(this->ParseType());
    }
    else
        func->addRetType(std::make_unique<Type::Void>());

    if (this->is(SEMI))
        this->next();
    
    if (!this->expect(LCURL))
        return func;

    func->addBody(this->ParseBlockStmt());

    if (this->is(SEMI))
        this->next();
    
    return func;
}
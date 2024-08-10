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
    
    this->next();

    // TODO: Parse parameters here

    if (!this->expect(RPAREN))
        panic("Did not find )");
    
    this->next();

    if (this->is(ARWR))
    {
        this->next();

        int retType = Type::isBuiltinType(this->consume());
        if (!retType)
            panic("Have not implemented return type parsing");
        
        func->addRetType(std::make_unique<Type::Builtin>( Type::Basic(retType) ));
    }

    if (this->is(SEMI))
        this->next();
    
    // TODO: Parse Block statement
    if (!this->expect(LCURL))
        panic("Function does not have body");

    func->addBody(this->ParseBlockStmt());

    if (this->is(SEMI))
        this->next();

    return func;
}
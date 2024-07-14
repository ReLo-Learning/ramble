#include "parser.hpp"

// [extern] [const | private | unsigned] (let | ident | type) (ident) [= (expr)] ;
std::unique_ptr<AST::IStmt> Parser::ParseVarDecl()
{  
    Token t = this->get();
    Token varType = Token(ILLEGAL);
    Token ident = Token(ILLEGAL);

    int validArgs = 0;
    bool varAssigned = false;

    const Kind validTypes[] = {LET, IDENT, INT, FLOAT};
    const int lenValidTypes = 4;

    while(t.kind() != SEMI)
    {
        if (t.is(EXTERN))
            validArgs |= 0b10000;
        else if (t.is(CONST))
            validArgs |= 0b01000;
        else if (t.is(PRIVATE))
            validArgs |= 0b00100;
        else if (t.is(UNSIGNED))
            validArgs |= 0b00010;
        else if (t.is(IDENT) && !varType.is(ILLEGAL))
            ident = t;
        else if (t.isAny(lenValidTypes, validTypes))
            varType = t;
        else if (t.is(EQ))
        {
            varAssigned = true;
            std::cout << "=" << std::endl;
        }
    }

    if (!varAssigned)
        validArgs |= 0b00001;

    std::unique_ptr<AST::IExpr> expr = std::move(this->ParseExpression());

    return std::make_unique<AST::VarDecl>(ident, std::move(expr));
}
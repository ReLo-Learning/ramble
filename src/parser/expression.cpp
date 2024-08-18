#include "parser.hpp"

#include <string>

std::unique_ptr<AST::IExpr> Parser::ParseExpression(int precedence)
{
    int primary = this->prefixOps[this->get().kind()];
    if (primary == 0)
        panic("Did not find a prefix operator");

    auto left = this->ParsePrefixExpression();

    while (this->isNot(SEMI) && precedence < this->getPrecedence())
    {
        int infix = this->infixOps[this->get().kind()];
        int postfix = this->postfixOps[this->get().kind()];

        if (infix == 0 && postfix == 0)
            return left;
        
        // this->next();

        if (infix != 0)
            left = this->ParseInfixExpression(std::move(left));
        else if (postfix != 0)
            left = this->ParsePostfixExpression(std::move(left));
    }

    return left;
}

std::unique_ptr<AST::IExpr> Parser::ParsePrefixExpression()
{
    switch (this->get().kind())
    {
    case Kind::INT_LIT:
        return this->ParseIntLiteral();
    case Kind::FLOAT_LIT:
        return this->ParseFloatLiteral();
    case Kind::RUNE_LIT:
        // return this->ParseRuneLiteral();
        break;
    case Kind::STRING_LIT:
        return this->ParseStringLiteral();
    case Kind::IDENT:
        return this->HandleIdent();
        break;
    
    default:
        panic("Unimplemented Primary Expression!");
        break;
    }
}

std::unique_ptr<AST::IExpr> Parser::ParseInfixExpression(std::unique_ptr<AST::IExpr> LHS)
{
    Token op = this->consume();

    int precedence = this->precedences[op.kind()];

    std::unique_ptr<AST::IExpr> RHS = this->ParseExpression(precedence);

    return std::make_unique<AST::InfixExpr>(op, std::move(LHS), std::move(RHS)); 
};
std::unique_ptr<AST::IExpr> Parser::ParsePostfixExpression(std::unique_ptr<AST::IExpr> left) { return left; };

std::unique_ptr<AST::IExpr> Parser::ParseIntLiteral() { return std::make_unique<AST::IntLiteral>(std::stoi(this->consume().value)); }

std::unique_ptr<AST::IExpr> Parser::ParseFloatLiteral() { return std::make_unique<AST::FloatLiteral>(std::stof(this->consume().value)); }

std::unique_ptr<AST::IExpr> Parser::ParseStringLiteral() { return std::make_unique<AST::StringLiteral>(this->consume().value); }
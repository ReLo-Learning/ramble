#include "token.hpp"

Token::Token(Kind kind)
{
    this->type = kind;
}
Token::Token(Kind kind, int line, int column)
{
    this->type = kind;
    this->line = line;
    this->column = column;
}
Token::Token(Kind kind, std::string value, int line, int column)
{
    this->type = kind;
    this->line = line;
    this->column = column;
    this->value = value;
}

Kind Token::kind(){ return this->type; }

std::ostream &operator<<(std::ostream &os, const Token& token)
{
    os << std::left;
    os << std::setw(10) << TokenKind[token.type];
    os << "(" << std::setw(5) << token.line << ":" << std::setw(5) << token.column << ")";

    if (token.value.length() > 0)
        os << "\t" << token.value;
    
    os << std::endl;

    return os;
}
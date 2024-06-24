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
bool Token::is(Kind kind) { return this->kind() == kind; }
bool Token::isAny(int len, const Kind kinds[])
{
    bool ret_val = false;

    for(int i = 0; i < len; i++)
    {
        ret_val = this->is(kinds[i]);
        if (ret_val)
            break;
    }

    return ret_val;
}

std::ostream &operator<<(std::ostream &os, const Token& token)
{
    os << std::left;
    os << std::setw(10) << getType(token.type);
    os << "(" << std::setw(5) << token.line << ":" << std::setw(5) << token.column << ")";

    if (token.value.length() > 0)
        os << "\t" << token.value;
    
    os << std::endl;

    return os;
}
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

std::string Token::kindStr() { return getType(this->type); }
std::string Token::str()
{
    std::stringstream ss;

    ss << std::left;
    ss << std::setw(10) << getType(this->type);
    ss << "(" << std::setw(5) << this->line << ":" << std::setw(5) << this->column << ")";

    if (this->value.length() > 0)
        ss << "\t" << this->value;

    ss << "\n";

    return ss.str();
}
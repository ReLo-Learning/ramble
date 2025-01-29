#include "error.hpp"

std::map<ErrorType, std::string> ErrorTypeString = {
    {LEXER, "LEXER"},
    {PARSER, "PARSER"},
};

std::string Error::str()
{
    std::stringstream ss;

    return ss.str();
}
#pragma once

#ifndef ERROR_HPP
#define ERROR_HPP

#include <sstream>
#include <string>
#include <map>

// enum to specify different types of common errors (Lexer, Parser, Codegen, etc)
enum ErrorType 
{
    LEXER,
    PARSER,

};

class Error
{
public:
    std::string msg;
    std::string filepath;
    unsigned int lineNum;
    unsigned int colNum;

    std::string str();
};

#endif
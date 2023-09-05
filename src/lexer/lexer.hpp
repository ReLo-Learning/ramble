#pragma once

#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "../errors/error.hpp"
#include "token.hpp"

struct Position
{
    int line;
    int column;
};

class Lexer
{
    private:
        std::string file;
        unsigned int line;
        unsigned int col;
        unsigned int index;

        std::vector<Token> tokens;
        std::string src;

        char peek();
        char next();
        char get();
        char consume();

        void word(std::string &buff);

        Token m_tokenize();

    public:
        Lexer(std::string str);
        
        std::vector<Token> tokenize();
};

#endif
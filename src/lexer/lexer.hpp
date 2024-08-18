#pragma once

#ifndef LEXER_HPP
#define LEXER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../errors/error.hpp"
#include "../utils/panic.hpp"
#include "token.hpp"

struct Position
{
    int line;
    int column;
};

class Lexer
{
    private:
        std::string m_file;
        unsigned int line;
        unsigned int col;

        std::vector<Token> tokens;
        std::ifstream src;

        char peek();
        char next();
        char get();
        char consume();

        bool check_and_consume(char c);

        void word(std::string &buff);

        void handleInlineComment();
        void handleMultilineComment();

        Token m_tokenize();

    public:
        Lexer(std::string file);
        
        std::vector<Token> tokenize();

        void print();
};

#endif
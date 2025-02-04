#pragma once

#ifndef LEXER_HPP
#define LEXER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../errors/error.hpp"
#include "../utils/panic.hpp"
#include "../utils/FileSet.hpp"
#include "token.hpp"

struct Position
{
    std::streampos filePos;
    int line;
    int column;
};

class Lexer
{
    private:
        std::string m_file;
        unsigned int line;
        unsigned int col;

        std::shared_ptr<FileSet> file;
        std::vector<Token> tokens;
        std::ifstream src;

        char peek();
        char next();
        char get();
        char consume();
        std::streampos getFilePos();

        bool check_and_consume(char c);

        void word(std::string &buff);

        void handleInlineComment();
        void handleMultilineComment();

        Token m_tokenize();

    public:
        Lexer(std::string file);
        
        std::vector<Token> tokenize();

        std::shared_ptr<FileSet> getFileSet();

        void print();
};

#endif
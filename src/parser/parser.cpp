#include "parser.hpp"

Parser::Parser(std::vector<Token> tokens) : m_tokens(std::move(tokens))
{
    this->m_index = 0;
    std::unique_ptr<Program> prog = std::make_unique<Program>();
}

std::unique_ptr<Program> Parser::parse()
{
    while(true)
    {
        switch(this->consume().kind())
        {
            case eof:
                std::cout << "Parser" << std::endl;
                std::cout << prog;
                return std::move(prog);

            case LET:
                ParseVarDecl();
                break;
            
            default:
                break;
        }
    }

    return std::move(prog);
}

Token Parser::get(){ return this->m_tokens.at(m_index); }
Token Parser::consume(){ return this->m_tokens.at(m_index++); }
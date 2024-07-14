#include "parser.hpp"

Parser::Parser(std::vector<Token> tokens) : m_tokens(std::move(tokens))
{
    this->m_index = 0;
    std::unique_ptr<AST::Program> prog = std::make_unique<AST::Program>();
}

std::unique_ptr<AST::Program> Parser::parse()
{
    Token currTok = this->get();
    while(this->get().kind() != eof)
    {
        switch(currTok.kind())
        {
            case LET:
                ParseVarDecl();
                break;

            case INT:
                ParseVarDecl();
                break;
            
            case FLOAT:
                ParseVarDecl();
                break;
            
            default:
                break;
        }

        currTok = this->consume();
    }

    return std::move(prog);
}

Token Parser::get() { return this->m_tokens.at(m_index); }
Token Parser::consume() { return this->m_tokens.at(++m_index); }
Token Parser::peek() { return this->m_tokens.at(m_index + 1); }
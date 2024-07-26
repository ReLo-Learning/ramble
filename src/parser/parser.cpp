#include "parser.hpp"

Parser::Parser(std::vector<Token> tokens) : m_tokens(std::move(tokens))
{
    this->m_index = 0;
    
    // Populate Precedence
    this->precedences[Kind::IDENT] = Precedence::PRIMARY;
    this->precedences[Kind::INT_LIT] = Precedence::PRIMARY;
    this->precedences[Kind::FLOAT_LIT] = Precedence::PRIMARY;
    this->precedences[Kind::RUNE_LIT] = Precedence::PRIMARY;
    this->precedences[Kind::STRING_LIT] = Precedence::PRIMARY;

    this->precedences[Kind::ADD] = Precedence::ADDITIVE;
    this->precedences[Kind::SUB] = Precedence::ADDITIVE;

    this->precedences[Kind::MUL] = Precedence::MULTIPLICATIVE;
    this->precedences[Kind::DIV] = Precedence::MULTIPLICATIVE;
    this->precedences[Kind::MOD] = Precedence::MULTIPLICATIVE;

    this->precedences[Kind::POW] = Precedence::POWER;

    // Populate Expression Operations
    this->prefixOps[Kind::IDENT] = 1;
    this->prefixOps[Kind::INT_LIT] = 1;
    this->prefixOps[Kind::FLOAT_LIT] = 1;
    this->prefixOps[Kind::RUNE_LIT] = 1;
    this->prefixOps[Kind::STRING_LIT] = 1;
    this->prefixOps[Kind::INCR] = 1;
    this->prefixOps[Kind::DECR] = 1;
    this->prefixOps[Kind::SUB] = 1;

    this->infixOps[Kind::ADD] = 1;
    this->infixOps[Kind::SUB] = 1;
    this->infixOps[Kind::MUL] = 1;
    this->infixOps[Kind::DIV] = 1;
    this->infixOps[Kind::MOD] = 1;
    this->infixOps[Kind::POW] = 1;

    this->postfixOps[Kind::INCR] = 1;
    this->postfixOps[Kind::DECR] = 1;

}

std::unique_ptr<AST::Program> Parser::parse()
{
    std::unique_ptr<AST::Program> program = std::make_unique<AST::Program>();

    while (this->get().kind() != eof)
    {
        program->addStatement(this->ParseStatement());
    }

    return program;
}

std::unique_ptr<AST::IStmt> Parser::ParseStatement()
{
    switch (this->get().kind())
    {
    case LET:
        return this->ParseVarDecl();

    case FUNC:
        return this->ParseFuncDecl();

    default:
        std::cout << getType(this->get().kind()) << this->get().str() << "\n";
        panic("Illegal Token");
        this->next();
        break;
    }
}

Token Parser::get() { return this->m_tokens.at(m_index); }
Token Parser::next() { return this->m_tokens.at(++m_index); }
Token Parser::consume() { return this->m_tokens.at(m_index++); }
Token Parser::peek() { return this->m_tokens.at(m_index + 1); }

Precedence Parser::getPrecedence(){return this->precedences[this->get().kind()]; } 
Precedence Parser::peekPrecedence() { return this->precedences[this->peek().kind()]; }

bool Parser::expect(Kind kind) { return this->get().kind() == kind; }
bool Parser::is(Kind kind) { return this->get().kind() == kind; }
bool Parser::isNot(Kind kind) { return this->get().kind() != kind; }
bool Parser::peekIsNot(Kind kind) { return this->peek().kind() != kind; }
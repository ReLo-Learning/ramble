#include "lexer.hpp"

const std::string KEYWORDS[] = {
    "let",
    "int",
    "float",
    "char",
    "bool",
    "const",
    "unsigned",
    "extern",
    "private",

    "end"
};

Lexer::Lexer(std::string str)
{
    this->line = 0;
    this->col = 0;
    this->index = 0;
    this->src = str; 
}

//See the next character
char Lexer::peek(){ return this->src[this->index + 1]; }

//Get the next character
char Lexer::next(){ this->col++; return this->src[++this->index]; }

char Lexer::get() { return this->src[this->index]; }

char Lexer::consume() { this->col++; return this->src[this->index++]; }

//Read until invalid character is found and break off
//returns the found word
void Lexer::word(std::string &buff)
{
    while (isalnum(this->get()) || this->get() == '_')
    {
        buff.push_back(this->consume());
    }
}

int isKeyword(std::string const &w)
{
    int i = 0;
    
    while(KEYWORDS[i].compare("end") != 0)
    {
        if (KEYWORDS[i++].compare(w) == 0) { return i; }
    }

    return -1;
}

int isIdent(std::string const &w) { return (isalpha(w[0]) || w[0] == '_'); }

Token Lexer::m_tokenize()
{
    for(;;)
    {
        if (this->index >= this->src.length())
        {
            if(this->tokens.back().kind() != SEMI)
                this->tokens.push_back(Token(SEMI, this->line, this->col));
            return Token(eof, this->line, this->col);
        }
        
        int line = this->line;
        int col = this->col;
        
        char c = this->consume();

        std::string buff;
        buff.push_back(c);
        
        switch (c)
        {
        case '\n':
            this->line++;
            this->col = 0;

            if (this->tokens.back().kind() != SEMI)
                return Token(SEMI, line, col);
                
            break;

        case '+':
            if (this->get() == '+')
            {
                this->consume();
                return Token(INCR, this->line, this->col);
            }
            else
                return Token(ADD, this->line, this->col);
            break;

        case '=':
            if (this->get() == '=')
                return Token(EEQ, this->line, this->col);
            else
                return Token(EQ, this->line, this->col);
            break;

        case ';':
            return Token(SEMI, this->line, this->col);
            break;

        default:
            if (isalpha(c) || c == '_')
            {
                this->word(buff);

                int offset = isKeyword(buff);

                if (offset != -1)
                {
                    return Token(Kind(keyword_begin + offset), line, col);
                }
                else if (isIdent(buff))
                {
                    return Token(IDENT, buff, line, col);
                }
            }
            else if (isdigit(c))
            {
                Kind type = INT_LIT;

                while (isdigit(this->get()) || this->get() == '.')
                {
                    if (this->get() == '.')
                    {
                        if (type == FLOAT_LIT)
                            std::cout << "Unimplemented ERROR" << std::endl;

                        type = FLOAT_LIT;
                    }

                    buff.push_back(this->consume());
                }

                return Token(type, buff, line, col);
            }
            else
            {
            }
            break;
        }
    }
}

std::vector<Token> Lexer::tokenize()
{
    //Loop over every character in line
    while(true)
    {
        Token t = this->m_tokenize();
        std::cout << t;
        this->tokens.push_back(t);

        if (t.kind() == eof)
            break;
        
    }

    std::cout << "Created tokens" << std::endl;

    // For debugging purposes
    for (auto token : this->tokens)
    {
        std::cout << token;
    }

    return this->tokens;
}
#include "lexer.hpp"

const std::string KEYWORDS[] = {
    "let",
    "const",
    "unsigned",
    "extern",
    "private",

    "switch",
    "case",
    "default",
    "for",
    "while",
    "continue",
    "break",
    "if",
    "elif",
    "else",

    "struct",
    "typedef",
    "union",
    "enum",
    "interface",

    "func",
    "return",

    "import",

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

bool Lexer::check_and_consume(char c)
{
    bool isNext = this->get() == c;
    if (isNext)
        this->next();

    return isNext;
}

//Read until invalid character is found and break off
//returns the found word
void Lexer::word(std::string &buff)
{
    while (isalnum(this->get()) || this->get() == '_')
    {
        buff.push_back(this->consume());
    }
}

void Lexer::handleInlineComment()
{
    while (this->get() != '\n' || this->index >= this->src.length())
        this->next();
}

void Lexer::handleMultilineComment()
{
    while (this->get() != '*' && this->peek() != '/')
    {
        if (this->index >= this->src.length())
            panic("Multiline comment is not closed");
        
        this->next();
    }
    this->next();
    this->next();
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
            if(this->tokens.size() > 0 && this->tokens.back().kind() != SEMI)
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

            if (this->tokens.size() > 0 && this->tokens.back().kind() != SEMI)
                return Token(SEMI, line, col);
                
            break;

        case '+':
            if (this->check_and_consume('+'))
                return Token(INCR, this->line, this->col);
            
            if (this->check_and_consume('='))
                return Token(PEQ, this->line, this->col);

            return Token(ADD, this->line, this->col);
        
        case '-':
            if (this->check_and_consume('-'))
                return Token(DECR, this->line, this->col);
            
            if (this->check_and_consume('='))
                return Token(SEQ, this->line, this->col);
            
            if (this->check_and_consume('>'))
                return Token(ARWR, this->line, this->col);
            
            return Token(SUB, this->line, this->col);
        
        case '*':
            if (this->check_and_consume('*'))
                return Token(POW, this->line, this->col);
            
            if (this->check_and_consume('='))
                return Token(MEQ, this->line, this->col);

            return Token(MUL, this->line, this->col);
        
        case '/':
            if (this->check_and_consume('/'))
            {
                this->handleInlineComment();
                continue;
            }
            
            if (this->check_and_consume('*'))
            {
                this->handleMultilineComment();
                continue;
            }

            if (this->check_and_consume('='))
                return Token(DEQ, this->line, this->col);

            return Token(DIV, this->line, this->col);
        
        case '%':
            if (this->check_and_consume('='))
                return Token(REQ, this->line, this->col);

            return Token(MOD, this->line, this->col);

        case '=':
            if (this->check_and_consume('='))
                return Token(EEQ, this->line, this->col);
            
            return Token(EQ, this->line, this->col);
        
        case '|':
            if (this->check_and_consume('|'))
                return Token(OR, this->line, this->col);
            
            if (this->check_and_consume('='))
                return Token(OEQ, this->line, this->col);

            return Token(bOR, this->line, this->col);
        
        case '&':
            if (this->check_and_consume('&'))
                return Token(AND, this->line, this->col);

            if (this->check_and_consume('='))
                return Token(AEQ, this->line, this->col);

            return Token(bAND, this->line, this->col);
        
        case '<':
            if (this->check_and_consume('<'))
                return Token(SHL, this->line, this->col);
            
            if (this->check_and_consume('='))
                return Token(LEQ, this->line, this->col);

            // Can lead to ambiguous code like 5<-1
            if (this->check_and_consume('-'))
                return Token(ARWL, this->line, this->col);

            return Token(LSS, this->line, this->col);
        
        case '>':
            if (this->check_and_consume('>'))
                return Token(SHR, this->line, this->col);
            
            if (this->check_and_consume('='))
                return Token(GEQ, this->line, this->col);

            return Token(GRT, this->line, this->col);
        
        case '!':
            if (this->check_and_consume('='))
                return Token(NEQ, this->line, this->col);

            return Token(NOT, this->line, this->col);
        
        case '^':
            if (this->check_and_consume('='))
                return Token(XEQ, this->line, this->col);

            return Token(XOR, this->line, this->col);
        
        case '~':
            return Token(bNOT, this->line, this->col);

        case ':':
            return Token(COLON, this->line, this->col);
        
        case ',':
            return Token(COMMA, this->line, this->col);

        case ';':
            return Token(SEMI, this->line, this->col);

        case '(':
            return Token(LPAREN, this->line, this->col);
        
        case ')':
            return Token(RPAREN, this->line, this->col);
        
        case '{':
            return Token(LCURL, this->line, this->col);
        
        case '}':
            return Token(RCURL, this->line, this->col);

        case '[':
            return Token(LBRACK, this->line, this->col);

        case ']':
            return Token(RBRACK, this->line, this->col);
        
        case '.':
            return Token(PERIOD, this->line, this->col);
        
        case '\'':
            while (this->get() != '\'')
            {
                buff.push_back(this->consume());
            }
            buff.push_back(this->consume());

            return Token(RUNE_LIT, buff, this->line, this->col);
        
        case '"':
            while (this->get() != '"')
            {
                buff.push_back(this->consume());
            }
            buff.push_back(this->consume());

            return Token(STRING_LIT, buff, this->line, this->col);

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
        this->tokens.push_back(t);

        if (t.kind() == eof)
            break;
        
    }

    return this->tokens;
}

void Lexer::print()
{
    std::cout << "Tokens:" << "\n";

    for(auto token : this->tokens)
    {
        std::cout << token.str();
    }

    std::cout << std::endl;
}
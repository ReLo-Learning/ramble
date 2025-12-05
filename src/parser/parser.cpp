#include "parser.hpp"

void Parser::panic(std::string msg) 
{
    Token currToken = this->get();

    // find the position corresponding to the beginning of the line
    std::streampos beginOfLine = currToken.getFilePos();

    int col = currToken.getColumn();
    int line = currToken.getLine();

    // get the line which caused the error
    std::string str;
    this->file->src.clear();
    this->file->src.seekg(beginOfLine, std::ios::beg);
    std::getline(this->file->src, str);

    // Change terminal text color to red
    std::cout << "\033[31m";

    std::cout << "PARSER ERROR (" << this->file->filepath << " [ln " << line + 1 << ", col " << col + 1 << "])\n";

    // Print the actual error message
    std::cout << "   " << msg << "\n";

    // Print debug information
    std::cout << str << "\n";
    std::cout << std::string(col - 1, ' ') << std::string(currToken.val().length(), '^') << "\n";

    // Change terminal text color back to default
    std::cout << "\033[0m";
    exit(1);
}

Parser::Parser(std::vector<Token> tokens, std::shared_ptr<FileSet> fs) : m_tokens(std::move(tokens)), file(fs)
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

    this->precedences[Kind::EQ] = Precedence::ASSIGNMENT;
    this->precedences[Kind::PEQ] = Precedence::ASSIGNMENT;
    this->precedences[Kind::SEQ] = Precedence::ASSIGNMENT;
    this->precedences[Kind::MEQ] = Precedence::ASSIGNMENT;
    this->precedences[Kind::DEQ] = Precedence::ASSIGNMENT;
    this->precedences[Kind::REQ] = Precedence::ASSIGNMENT;
    this->precedences[Kind::SHLEQ] = Precedence::ASSIGNMENT;
    this->precedences[Kind::SHREQ] = Precedence::ASSIGNMENT;
    this->precedences[Kind::AEQ] = Precedence::ASSIGNMENT;
    this->precedences[Kind::XEQ] = Precedence::ASSIGNMENT;
    this->precedences[Kind::OEQ] = Precedence::ASSIGNMENT;

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
    this->infixOps[Kind::EQ] = 1;
    this->infixOps[Kind::PEQ] = 1;
    this->infixOps[Kind::SEQ] = 1;
    this->infixOps[Kind::MEQ] = 1;
    this->infixOps[Kind::DEQ] = 1;
    this->infixOps[Kind::REQ] = 1;
    this->infixOps[Kind::SHLEQ] = 1;
    this->infixOps[Kind::SHREQ] = 1;
    this->infixOps[Kind::AEQ] = 1;
    this->infixOps[Kind::XEQ] = 1;
    this->infixOps[Kind::OEQ] = 1;

    this->postfixOps[Kind::INCR] = 1;
    this->postfixOps[Kind::DECR] = 1;

}

std::unique_ptr<AST::Program> Parser::parse()
{
    std::unique_ptr<AST::Program> program = std::make_unique<AST::Program>(this->file);

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
    
    case IDENT:
        return this->ParseExprStmt();
    
    case RETURN:
        return this->ParseRetStmt();

    case EXTERN:
        return this->ParseExternStmt();

    default:
        this->panic("Illegal Token");
        break;
    }
}

std::unique_ptr<Type::IType> Parser::ParseType()
{
    switch (this->get().kind())
    {
        case MUL: {
            this->next();
            return std::make_unique<Type::Pointer>(this->ParseType());
        }
        
        case IDENT: {
            int builtin = Type::isBuiltinType(this->get());
            if (!builtin)
                panic("Unhandled Type");
            
            this->next();

            return std::make_unique<Type::Builtin>( Type::Basic(builtin) );
        }
        
        default:
            std::cout << this->get().str();
            panic("Unhandled Type");
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
bool Parser::peekIs(Kind kind) { return this->peek().kind() == kind; }
bool Parser::peekIsNot(Kind kind) { return this->peek().kind() != kind; }
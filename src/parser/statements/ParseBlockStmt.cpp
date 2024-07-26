#include "../parser.hpp"

std::unique_ptr<AST::IStmt> Parser::ParseBlockStmt()
{
    std::unique_ptr<AST::BlockStmt> block = std::make_unique<AST::BlockStmt>();
    
    this->next();
    if (this->is(SEMI))
        this->next();

    while (this->isNot(RCURL))
    {
        if (this->is(eof))
            panic("Block statement is not closed");
        
        block->addStmt(this->ParseStatement());
    }

    this->next();

    return block;
}
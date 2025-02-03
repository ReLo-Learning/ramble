#include "module.hpp"

namespace module
{

std::unique_ptr<HIR::Walker> process(std::string file)
{
    Lexer lexer(file);
    std::vector<Token> tokens = lexer.tokenize();
    lexer.print();

    Parser parser(tokens, lexer.getFileSet());
    std::unique_ptr<AST::Program> program = parser.parse();
    program->print();

    return HIR::Lower(&*program);
}

Module::Module(std::string input)
{
    std::unique_ptr<HIR::Walker> ir = process(input);
    ir->print();
}

}
#include "module.hpp"

namespace module
{

std::unique_ptr<HIR::IR> process(std::string file)
{
    Lexer lexer(file);
    std::vector<Token> tokens = lexer.tokenize();
    lexer.print();

    Parser parser(tokens, lexer.getFileSet());
    std::unique_ptr<AST::Program> program = parser.parse();
    program->print();

    std::unique_ptr<HIR::IR> ir = std::move(HIR::Lower(&*program));

    return ir;
}

Module::Module(std::string input)
{
    std::unique_ptr<HIR::IR> ir = process(input);
    ir->print();

    // this->Globals = ir->Globals;

    std::filesystem::path p = std::filesystem::current_path() / std::filesystem::path(this->mod_name + ".c");

    this->m_file = std::ofstream(p);
    if(!this->m_file.is_open())
    {
        std::cerr << "Error opening file\n";
    }

    C_Codegen::Codegen generator(&this->m_file);
    generator.walk(std::move(ir->Globals));

    this->m_file.close();
}

}
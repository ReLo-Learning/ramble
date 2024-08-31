#include <iostream>
#include <sstream>
#include <fstream>

#include "../src/lexer/lexer.hpp"
#include "../src/errors/error.hpp"
#include "../src/parser/parser.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Insufficient arguments passed" << std::endl;
        return EXIT_FAILURE;
    }

    // std::string contents;
    // {
    //     std::stringstream contents_stream;
    //     std::fstream input(argv[1], std::ios::in);
    //     contents_stream << input.rdbuf();
    //     contents = contents_stream.str();
    // }

    Lexer lexer(argv[1]);
    std::vector<Token> tokens = lexer.tokenize();
    lexer.print();

    Parser parser(tokens);
    std::unique_ptr<AST::Program> program = parser.parse();
    program->print();

    // Codegen::generate(std::move(program));

    return 0;
}
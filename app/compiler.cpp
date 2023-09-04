#include <iostream>

#include "../src/lexer/lexer.hpp"
#include "../src/errors/error.hpp"

int main(int argc, char **argv)
{
    // if (argc < 2)
    // {
    //     std::cout << "Insufficient arguments passed" << std::endl;
    //     return EXIT_FAILURE;
    // }

    std::cout << "Tokens (string)" << std::endl;
    Lexer lexer = Lexer("let x = 5");
    
    return 0;
}
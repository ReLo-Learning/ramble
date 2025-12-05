#pragma once

#ifndef MODULE_HPP
#define MODULE_HPP

#include <string>
#include <fstream>
#include <filesystem>

#include "../lexer/lexer.hpp"
#include "../parser/parser.hpp"
#include "../hir/hir.hpp"
#include "../c_codegen/C_Codegen.hpp"

namespace module
{

class Module
{
private:
    std::ofstream m_file;
    std::string mod_name = "main";

public:
    Module(std::string input);
    ~Module() = default;
};

}

#endif
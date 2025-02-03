#pragma once

#ifndef MODULE_HPP
#define MODULE_HPP

#include <map>
#include <string>

#include "../lexer/lexer.hpp"
#include "../parser/parser.hpp"
#include "../hir/hir.hpp"

namespace module
{

class Module
{
private:
    std::map<std::string, HIR::VarDecl> Globals;

public:
    Module(std::string input);
    ~Module() = default;
};

}

#endif
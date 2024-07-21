#pragma once

#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "expression.hpp"
#include "statement.hpp"

namespace AST
{
class Program
{
    std::string file;
    std::string path;
    
    std::vector<std::unique_ptr<IStmt>> stmts;

public:
    Program();
    ~Program() = default;

    void addStatement(std::unique_ptr<IStmt>);

    void print();
};

}

#endif
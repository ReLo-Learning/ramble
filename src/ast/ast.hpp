#pragma once

#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "IVisitor.hpp"
#include "expression.hpp"
#include "statement.hpp"
#include "../utils/FileSet.hpp"

namespace AST
{
class Program
{
    std::shared_ptr<FileSet> file;
    
    std::vector<std::unique_ptr<IStmt>> stmts;
public:
    Program(std::shared_ptr<FileSet> file) : file(file) {};
    ~Program() = default;

    void addStatement(std::unique_ptr<IStmt>);

    void walk(IVisitor *);

    void print();
};

}

#endif
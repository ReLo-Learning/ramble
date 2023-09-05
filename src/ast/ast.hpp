#pragma once

#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "expression.hpp"
#include "statement.hpp"

class Program
{
    std::string file;
    std::string path;
    
    std::vector<std::unique_ptr<Stmt>> stmts;

public:
    Program() {}

    friend std::ostream& operator<<(std::ostream& os, const Program& program)
    {
        for( auto& stmt : program.stmts )
        {
            stmt->print();
        }
        
        return os;
    }
};

#endif
#pragma once

#ifndef AST_HPP
#define AST_HPP

#include <vector>
#include <memory>

#include "expression.hpp"
#include "statement.hpp"

struct Program
{
    std::vector<std::unique_ptr<Stmt>> prog;
};

#endif
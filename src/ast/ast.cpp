#include "ast.hpp"

namespace AST
{
Program::Program() {}

void Program::addStatement(std::unique_ptr<IStmt> statement)
{
    this->stmts.push_back(std::move(statement));
}

std::vector<std::unique_ptr<IStmt>> Program::statements()
{
    return std::move(this->stmts);
}

void Program::print()
{
    for (auto const& statement : this->stmts)
    {
        std::cout << statement->str() << "\n";
    }
}

}
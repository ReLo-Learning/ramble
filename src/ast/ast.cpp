#include "ast.hpp"

namespace AST
{
void Program::addStatement(std::unique_ptr<IStmt> statement)
{
    this->stmts.push_back(std::move(statement));
}

void Program::walk(IVisitor *v)
{
    for (auto const& statement : this->stmts)
    {
        statement->accept(v);
    }
}

void Program::print()
{
    std::cout << "{\n";
    std::cout << std::left << std::setw(10) << "Program: " << this->file->filename << "\n";
    std::cout << std::left << std::setw(10) << "File: " << this->file->filepath << "\n";

    std::cout << "Content:\n" << "[\n";
    for (auto const& statement : this->stmts)
    {
        std::cout << statement->str() << "\n";
    }
    std::cout << "]\n";

    std::cout << "}\n";
}

}
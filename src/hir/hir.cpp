#include "hir.hpp"

namespace HIR
{

std::unique_ptr<IR> Lower(AST::Program* program)
{
    // Create AST Walker
    Walker walker;

    // Walk AST
    program->walk(&walker);

    return std::move(walker.ir);
}

void IR::print()
{
    for(const auto& var : this->Globals)
    {
        std::cout << var->str();
    }
}
}
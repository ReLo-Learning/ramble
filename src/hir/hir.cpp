#include "hir.hpp"

namespace HIR
{

std::unique_ptr<IR> Lower(std::unique_ptr<AST::Program>& program)
{
    // Create AST Walker
    Walker walker;

    // Walk AST
    program->walk(&walker);

    // Convert AST to IR

    return std::make_unique<IR>();
}

}
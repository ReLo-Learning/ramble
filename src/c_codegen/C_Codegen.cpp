#include "C_Codegen.hpp"

namespace C_Codegen
{
Codegen::Codegen(std::ofstream *f)
{
    this->file = f;
    
    *this->file << "#include <stdint.h>\n";
}

void Codegen::walk(std::vector<std::unique_ptr<HIR::HStmt>> stmt_list)
{
    for(const auto& stmt : stmt_list)
    {
        stmt->accept(this);
    }
}

void Codegen::visit(HIR::VarDecl *vd)
{
    *this->file << vd->type->codegen() << " ";
    *this->file << vd->ident.value << " = " << vd->expr->str();
    *this->file << ";\n";
}
}
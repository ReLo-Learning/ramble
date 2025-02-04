#pragma once

#ifndef C_CODEGEN_HPP
#define C_CODEGEN_HPP

#include <fstream>
#include "../hir/hir.hpp"

namespace C_Codegen
{

class Codegen : HIR::HVisitor {
private:
    std::ofstream *file;

public:
    Codegen(std::ofstream *f);
    ~Codegen() = default;

    void walk(std::vector<std::unique_ptr<HIR::HStmt>> stmt_list);

    void visit(HIR::VarDecl *);
};

}

#endif
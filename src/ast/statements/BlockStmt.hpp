#pragma once

#ifndef BLOCKSTMT_HPP
#define BLOCKSTMT_HPP

#include "../IVisitor.hpp"

namespace AST
{
/*
{ statements... }
*/
class BlockStmt : public IStmt
{
private:
    std::vector<std::unique_ptr<IStmt>> m_stmts;

public:
    BlockStmt() = default;

    void accept(IVisitor *v);

    void addStmt(std::unique_ptr<IStmt> stmt);

    std::string str();
};

}

#endif
// #pragma once

// #ifndef BLOCKSTMT_HPP
// #define BLOCKSTMT_HPP

// #include "../statement.hpp"

// namespace AST
// {

// /*
// Block Statement:

// {
// STATEMENTS
// }

// */

// class BlockStmt : public IStmt
// {
// private:
//     std::vector<std::unique_ptr<IStmt>> m_stmts;

// public:
//     BlockStmt() {};

//     void accept(Visitor *v) { v->visit(this); }

//     void addStmt(std::unique_ptr<IStmt> stmt) { this->m_stmts.push_back(std::move(stmt)); }

//     std::string str()
//     {
//         std::stringstream ss;
//         ss << "{BlockStmt: ";

//         for (auto &stmt : this->m_stmts)
//         {
//             ss << "\n\t" << stmt->str();
//         }

//         ss << "\n}";

//         return ss.str();
//     }
// };
// };

// #endif
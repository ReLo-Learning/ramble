#pragma once

#ifndef PACKAGE_HPP
#define PACKAGE_HPP

#include <vector>
#include <string>

#include "../lexer/lexer.hpp"
#include "../parser/parser.hpp"
#include "../ast/ast.hpp"

namespace Package
{

    class Package
    {
        private:
            std::vector<std::string> m_files;

        public:
            Package() = default;
            ~Package() = default;

            void addFile(std::string file);

            void compile();

    };
}

#endif
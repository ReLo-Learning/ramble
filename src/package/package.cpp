#include "package.hpp"

namespace Package
{
    AST::Program DivideAndConquer();

    void Package::addFile(std::string file) { this->m_files.push_back(file); }

    void Package::compile()
    {
        return;
    }
}
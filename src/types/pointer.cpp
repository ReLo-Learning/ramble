#include "pointer.hpp"

namespace Type
{
    std::string Pointer::str() { return this->m_underlying->str() + "*"; }
    std::string Pointer::codegen() { return this->m_underlying->codegen() + "*"; }
}
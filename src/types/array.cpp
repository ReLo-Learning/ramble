#include "array.hpp"

namespace Type
{
    std::string Array::str() { return this->m_underlying->str() + "[]"; };
}
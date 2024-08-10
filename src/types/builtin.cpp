#include "builtin.hpp"

namespace Type
{
    const std::string builtin[] = {
        "bool",

        "int",
        "int8",
        "int16",
        "int32",
        "int64",
        
        "uint",
        "uint8",
        "uint16",
        "uint32",
        "uint64",

        "float32",
        "float64",

        "complex64",
        "complex128",

        "string",

        "byte",
        "char",
        "rune"
    };

    enum Basic {
        INVALID,

        Bool,

        Int,
        Int8,
        Int16,
        Int32,
        Int64,

        Uint,
        Uint8,
        Uint16,
        Uint32,
        Uint64,

        Float32,
        Float64,

        Complex64,
        Complex128,

        String,

        Byte = Uint8,
        Char = Byte,
        Rune = Uint32
    };

    int isBuiltinType(Token t)
    {   
        int idx = 1;   
        for (auto type : builtin)
        {
            if (t.value == type)
                return Basic(idx);
            
            idx += 1;
        }

        return INVALID;
    }

    Builtin::Builtin(Basic type)
    {
        this->m_type = type;
        this->m_value = builtin[type];
    }

    std::string Builtin::str() { return this->m_value; }
}
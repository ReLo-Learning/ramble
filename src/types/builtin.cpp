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

    const std::string builtin_codegen[] = {
        "INVALID",
        "u8",

        "i32",
        "i8",
        "i16",
        "i32",
        "i64",

        "i32",
        "i8",
        "i16",
        "i32",
        "i64",

        "f32",
        "f64",

        "c64",
        "c128",

        "i8*",
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
        int ret_val = INVALID;

        int idx = 1;   
        for (auto type : builtin)
        {
            
            if (!t.value.compare(type))
            {
                ret_val = Basic(idx);
                break;
            }
            
            idx += 1;
        }

        return ret_val;
    }

    std::string Void::str() { return "void"; }

    Builtin::Builtin(Basic type)
    {
        this->m_type = type;
        this->m_value = builtin[type-1];
    }

    std::string Builtin::str() { return this->m_value; }
    std::string Builtin::codegen() { return builtin_codegen[this->m_type]; }
}
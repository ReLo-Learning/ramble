#include "TypeCheck.hpp"

int SymbolTable::insert(std::string name, Symbol sym)
{
    int ret_val = -1;
    if (!this->lookup(name))
    {
        this->table.insert({name, sym});
        ret_val = 0;
    }
    
    return ret_val;
}

bool SymbolTable::lookup(std::string name)
{
    return this->table.contains(name);
}

Symbol SymbolTable::get(std::string name)
{
    return this->table[name];
}
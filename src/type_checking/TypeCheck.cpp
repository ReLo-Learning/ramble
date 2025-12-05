#include "TypeCheck.hpp"

TypeChecker::TypeChecker(AST::Program& prog)
{
    this->depth = 0;
    this->scope.emplace_back(SymbolTable("global"));

    prog.walk(this);
}
int TypeChecker::insert(std::string name, Symbol sym)
{
    this->scope[this->depth].insert(name, sym);
}

int TypeChecker::lookup(std::string name)
{
    int i = this->depth;

    while (i <= 0)
    {
        bool currScope = this->scope[i].lookup(name);
        if (currScope)
            break;

        i--;
    }

    return i;
}

Symbol TypeChecker::get(std::string name)
{
    /*
        This function will locate the symbol in any valid scope
        if the symbol cannot be found a symbol with type EMPTY will be returned
    */

    // retrieve the depth index of given symbol
    int idx = this->lookup(name);

    // create a temporary entry value
    std::unique_ptr<AST::IStmt> tmp = std::make_unique<AST::BlockStmt>();
    if (idx == -1)
        return {
            .type = EMPTY,
            .entry = tmp,
            .ident = ""
        };

    return this->scope[idx].get(name);
}

void TypeChecker::remove()
{
    this->scope.pop_back();
}

void TypeChecker::visit(AST::FuncDecl *fd)
{
    std::cout << "Function: " << fd->str() << "\n";
}
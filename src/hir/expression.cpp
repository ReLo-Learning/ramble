#include "hir.hpp"

template <typename T>
HIR::Literal<T>::Literal(){}

template <typename T>
HIR::Literal<T>::Literal(int type, T value){}

template <typename T>
bool HIR::Literal<T>::operator==(const Expr& expr) { return expr->type == this->type; }
#include "./../headers/Categoria.h"

Categoria::Categoria() {}

Categoria::Categoria(int _variable)
{
    this->variable = _variable;
}

int Categoria::getVariable()
{
    return this->variable;
}

Categoria::~Categoria() {}

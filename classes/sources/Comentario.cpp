#include "./../headers/Comentario.h"

Comentario::Comentario() {}

Comentario::Comentario(int _variable)
{
    this->variable = _variable;
}

int Comentario::getVariable()
{
    return this->variable;
}

Comentario::~Comentario() {}

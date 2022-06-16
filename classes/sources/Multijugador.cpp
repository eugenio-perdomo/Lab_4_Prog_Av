#include "./../headers/Multijugador.h"

Multijugador::Multijugador() {}

Multijugador::Multijugador(int _variable)
{
    this->variable = _variable;
}

int Multijugador::getVariable()
{
    return this->variable;
}

Multijugador::~Multijugador() {}

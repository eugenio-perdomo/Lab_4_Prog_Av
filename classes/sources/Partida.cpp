#include "./../headers/Partida.h"

Partida::Partida() {}

Partida::Partida(int _variable)
{
    this->variable = _variable;
}

int Partida::getVariable()
{
    return this->variable;
}

Partida::~Partida() {}

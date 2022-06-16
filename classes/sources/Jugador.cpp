#include "./../headers/Jugador.h"

Jugador::Jugador() {}

Jugador::Jugador(int _variable)
{
    this->variable = _variable;
}

int Jugador::getVariable()
{
    return this->variable;
}

Jugador::~Jugador() {}

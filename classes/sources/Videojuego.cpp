#include "./../headers/Videojuego.h"

Videojuego::Videojuego() {}

Videojuego::Videojuego(int _variable)
{
    this->variable = _variable;
}

int Videojuego::getVariable()
{
    return this->variable;
}

Videojuego::~Videojuego() {}

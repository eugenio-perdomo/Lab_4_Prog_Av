#include "./../headers/Suscripcion.h"

Suscripcion::Suscripcion() {}

Suscripcion::Suscripcion(int _variable)
{
    this->variable = _variable;
}

int Suscripcion::getVariable()
{
    return this->variable;
}

Suscripcion::~Suscripcion() {}

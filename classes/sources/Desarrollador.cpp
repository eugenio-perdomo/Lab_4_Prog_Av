#include "./../headers/Desarrollador.h"

Desarrollador::Desarrollador() {}

Desarrollador::Desarrollador(int _variable)
{
    this->variable = _variable;
}

int Desarrollador::getVariable()
{
    return this->variable;
}

Desarrollador::~Desarrollador() {}

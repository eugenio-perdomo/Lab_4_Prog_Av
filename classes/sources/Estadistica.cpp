#include "./../headers/Estadistica.h"

Estadistica::Estadistica() {}

Estadistica::Estadistica(int _variable)
{
    this->variable = _variable;
}

int Estadistica::getVariable()
{
    return this->variable;
}

Estadistica::~Estadistica() {}

#include "./../headers/Transmision.h"

Transmision::Transmision() {}

Transmision::Transmision(int _variable)
{
    this->variable = _variable;
}

int Transmision::getVariable()
{
    return this->variable;
}

Transmision::~Transmision() {}

#include "./../headers/Usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(int _variable)
{
    this->variable = _variable;
}

int Usuario::getVariable()
{
    return this->variable;
}

Usuario::~Usuario() {}

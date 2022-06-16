#include "./../headers/Individual.h"

Individual::Individual() {}

Individual::Individual(int _variable)
{
    this->variable = _variable;
}

int Individual::getVariable()
{
    return this->variable;
}

Individual::~Individual() {}

#include "./../headers/Transmision.h"

Transmision::Transmision() {}

Transmision::Transmision(DtFecha fechaInicio)
{
    this->fechaInicio = fechaInicio;
}

DtFecha Transmision::getFechaInicio()
{
    return this->fechaInicio;
}

void Transmision::setFechaInicio(DtFecha fechaInicio)
{
    this->fechaInicio = fechaInicio;
}

Transmision::~Transmision() {}

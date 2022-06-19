#include "./../headers/Transmision.h"

Transmision::Transmision() {}

Transmision::Transmision(DtFecha fechaInicio)
{
    this->fechaInicio = fechaInicio;
}

Transmision::DtFecha getFechaInicio()
{
    return this->fechaInicio;
}

Transmision::void setFechaInicio(DtFecha fechaInicio)
{
    this->fechaInicio = fechaInicio;
}

Transmision::~Transmision() {}

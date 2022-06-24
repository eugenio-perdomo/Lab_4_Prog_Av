#include "../headers/Transmision.h"

Transmision::Transmision()
{
    this->comentarios = new List();
}

Transmision::Transmision(DtFecha *fechaInicio)
{
    this->fechaInicio = fechaInicio;
    this->comentarios = new List();
}

DtFecha Transmision::getFechaInicio()
{
    return *fechaInicio;
}

void Transmision::setFechaInicio(DtFecha *fechaInicio)
{
    this->fechaInicio = fechaInicio;
}

/*void Transmision::setComentario(Comentario *c)
{
    comentarios->add(c);
}*/

Transmision::~Transmision() {}

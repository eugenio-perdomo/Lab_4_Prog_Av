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

void Transmision::eliminacionDeComentarios()
{
    IIterator *it = this->comentarios->getIterator();
    while (it->hasCurrent())
    {
        Comentario *com = dynamic_cast<Comentario *>(it->getCurrent());
        comentarios->remove(com);
        com->Eliminarme();
        delete (com);
        it->next();
    }
    delete it;
}

Transmision::~Transmision() {}

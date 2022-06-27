#include "../headers/Partida.h"

Partida::Partida() {}

Partida::Partida(std::string id,
                 std::string nombreVideojuego,
                 bool finalizado,
                 float duracionPartida,
                 DtFecha fechaInicio,
                 DtFecha fechaFin,
                 Videojuego *juego)
{
    this->id = id;
    this->nombreVideojuego = nombreVideojuego;
    this->finalizado = finalizado;
    this->duracionPartida = duracionPartida;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
    this->juego = juego;
    this->comentarios = new List();
}

std::string Partida::getId()
{
    return this->id;
}
std::string Partida::getNombreVideojuego()
{
    return this->nombreVideojuego;
}
bool Partida::getFinalizado()
{
    return this->finalizado;
}
float Partida::getDuracionPartida()
{
    return this->duracionPartida;
}
DtFecha Partida::getFechaInicio()
{
    return this->fechaInicio;
}
DtFecha Partida::getFechaFin()
{
    return this->fechaFin;
}

void Partida::setId(std::string id)
{
    this->id = id;
}

void Partida::setNombreVideojuego(std::string nombreVideojuego)
{
    this->nombreVideojuego = nombreVideojuego;
}
void Partida::setFinalizado(bool finalizado)
{
    this->finalizado = finalizado;
}
void Partida::setDuracionPartida(float duracionPartida)
{
    this->duracionPartida = duracionPartida;
}
void Partida::setFechaInicio(DtFecha fechaInicio)
{
    this->fechaInicio = fechaInicio;
}
void Partida::setFechaFin(DtFecha fechaFin)
{
    this->fechaFin = fechaFin;
}

void Partida::eliminarme()
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

Partida::~Partida() {}

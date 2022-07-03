#include "../headers/Partida.h"

Partida::Partida() {}

Partida::Partida(std::string id,
                 std::string nombreVideojuego,
                 bool finalizado,
                 float duracionPartida,
                 DtFecha *fechaInicio,
                 DtFecha *fechaFin)
{
    this->id = id;
    this->nombreVideojuego = nombreVideojuego;
    this->finalizado = finalizado;
    this->duracionPartida = duracionPartida;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
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
DtFecha *Partida::getFechaInicio()
{
    return fechaInicio;
}
DtFecha *Partida::getFechaFin()
{
    return fechaFin;
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
void Partida::setFechaInicio(DtFecha *fechaInicio)
{
    this->fechaInicio = fechaInicio;
}
void Partida::setFechaFin(DtFecha *fechaFin)
{
    this->fechaFin = fechaFin;
}

Partida::~Partida() {}

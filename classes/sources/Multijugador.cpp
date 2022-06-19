#include "./../headers/Multijugador.h"

Multijugador::Multijugador() {}

Multijugador::Multijugador(bool transmitidaEnVivo, DtFecha ultimaConexion, int cantJugadores)
{
    this->transmitidaEnVivo = transmitidaEnVivo;
    this->ultimaConexion = ultimaConexion;
    this->cantJugadores = cantJugadores;
}

bool Multijugador::getTransmitidaEnVivo()
{
    return this->transmitidaEnVivo;
}

DtFecha Multijugador::getUltimaConexion()
{
    return this->ultimaConexion;
}

int Multijugador::getCantJugadores()
{
    return this->cantJugadores;
}

void Multijugador::setTransmitidaEnVivo(bool transmitidaEnVivo)
{
    this->transmitidaEnVivo = transmitidaEnVivo;
}

void Multijugador::setUltimaConexion(DtFecha ultimaConexion)
{
    this->ultimaConexion = ultimaConexion;
}

void Multijugador::setCantJugadores(int cantJugadores)
{
    this->cantJugadores = cantJugadores;
}

Multijugador::~Multijugador() {}

#include "./../headers/Multijugador.h"

Multijugador::Multijugador() {}

Multijugador::Multijugador(bool transmitidaEnVivo, std::string nickJugadores, DtFecha ultimaConexion, int cantJugadores)
{
    this->transmitidaEnVivo = transmitidaEnVivo;
    this->nickJugadores = nickJugadores;
    this->ultimaConexion = ultimaConexion;
    this->cantJugadores = cantJugadores;
}

Multijugador::bool getTransmitidaEnVivo()
{
    return this->transmitidaEnVivo;
}

Multijugador::std::string getNickJugadores()
{
    return this->nickJugadores;
}

Multijugador::DtFecha getUltimaConexion()
{
    return this->ultimaConexion;
}

Multijugador::int getCantJugadores()
{
    return this->cantJugadores;
}

Multijugador::void setTransmitidaEnVivo(bool transmitidaEnVivo)
{
    this->transmitidaEnVivo = transmitidaEnVivo;
}

Multijugador::void setNickJugadores(std::string nickJugadores[10])
{
    this->nickJugadores = nickJugadores;
}

Multijugador::void setUltimaConexion(DtFecha ultimaConexion)
{
    this->ultimaConexion = ultimaConexion;
}

Multijugador::void setCantJugadores(int cantJugadores)
{
    this->cantJugadores = cantJugadores;
}

Multijugador::~Multijugador() {}

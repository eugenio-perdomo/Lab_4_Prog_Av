#include "../headers/Multijugador.h"

Multijugador::Multijugador() {}

Multijugador::Multijugador(bool transmitidaEnVivo,
                           // DtFecha ultimaConexion,
                           int cantJugadores,
                           std::string _id,
                           std::string _nombreVideojuego,
                           bool _finalizado,
                           float _duracionPartida,
                           DtFecha *_fechaInicio,
                           DtFecha *_fechaFin) : Partida(_id, _nombreVideojuego, _finalizado, _duracionPartida, _fechaInicio, _fechaFin)
{
    this->transmitidaEnVivo = transmitidaEnVivo;
    // this->ultimaConexion = ultimaConexion;
    this->cantJugadores = cantJugadores;
}

bool Multijugador::getTransmitidaEnVivo()
{
    return this->transmitidaEnVivo;
}

/*DtFecha Multijugador::getUltimaConexion()
{
    return *this->ultimaConexion;
}*/

int Multijugador::getCantJugadores()
{
    return this->cantJugadores;
}

void Multijugador::setTransmitidaEnVivo(bool transmitidaEnVivo)
{
    this->transmitidaEnVivo = transmitidaEnVivo;
}

/*void Multijugador::setUltimaConexion(DtFecha *ultimaConexion)
{
    this->ultimaConexion = ultimaConexion;
}*/

void Multijugador::setCantJugadores(int cantJugadores)
{
    this->cantJugadores = cantJugadores;
}

void Multijugador::eliminarMisComentarios()
{
    this->transmision->eliminacionDeComentarios();
}

Multijugador::~Multijugador() {}

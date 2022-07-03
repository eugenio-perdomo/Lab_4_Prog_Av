#include "../headers/Multijugador.h"

Multijugador::Multijugador() {}

Multijugador::Multijugador(bool transmitidaEnVivo,
                           int cantJugadores,
                           std::string _id,
                           std::string _nombreVideojuego,
                           bool _finalizado,
                           float _duracionPartida,
                           DtFecha *_fechaInicio,
                           DtFecha *_fechaFin/*,
                           ICollection *_listaJugadores*/) : Partida(_id, _nombreVideojuego, _finalizado, _duracionPartida, _fechaInicio, _fechaFin)
{
    this->transmitidaEnVivo = transmitidaEnVivo;
    this->cantJugadores = cantJugadores;
    /*List *jugadores = new List(); 
    this->jugadores = _listaJugadores;*/
}

Multijugador::Multijugador(bool transmitidaEnVivo, int cantJugadores, std::string _id, std::string _nombreVideojuego, bool _finalizado, float _duracionPartida, DtFecha *_fechaInicio)
{
    this->transmitidaEnVivo = transmitidaEnVivo;
    this->cantJugadores = cantJugadores;
    this->id = id;
    this->nombreVideojuego = nombreVideojuego;
    this->finalizado = finalizado;
    this->duracionPartida = duracionPartida;
    this->fechaInicio = fechaInicio;
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

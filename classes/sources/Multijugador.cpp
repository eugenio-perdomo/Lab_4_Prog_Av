#include "../headers/Multijugador.h"

Multijugador::Multijugador() {}

Multijugador::Multijugador(bool _transmitidaEnVivo,
                           int _cantJugadores,
                           std::string _id,
                           std::string _nombreVideojuego,
                           bool _finalizado,
                           float _duracionPartida,
                           DtFecha *_fechaInicio,
                           DtFecha *_fechaFin/*,
                           ICollection *_listaJugadores*/) : Partida(_id, _nombreVideojuego, _finalizado, _duracionPartida, _fechaInicio, _fechaFin)
{
    this->transmitidaEnVivo = _transmitidaEnVivo;
    this->cantJugadores = _cantJugadores;
    this->jugadores = new List();
    /*List *jugadores = new List(); 
    this->jugadores = _listaJugadores;*/
}

Multijugador::Multijugador(bool _transmitidaEnVivo, int _cantJugadores, std::string _id, std::string _nombreVideojuego, bool _finalizado, float _duracionPartida, DtFecha *_fechaInicio, DtFecha *_fechaFin, List *_participantes)
{
    this->transmitidaEnVivo = _transmitidaEnVivo;
    this->cantJugadores = _cantJugadores;
    this->id = _id;
    this->nombreVideojuego = _nombreVideojuego;
    this->finalizado = _finalizado;
    this->duracionPartida = _duracionPartida;
    this->fechaInicio = _fechaInicio;
    this->fechaFin = _fechaFin;
    this->jugadores = _participantes;
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

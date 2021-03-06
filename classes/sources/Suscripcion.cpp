#include "../headers/Suscripcion.h"

Suscripcion::Suscripcion() {}

Suscripcion::Suscripcion(/*float _costo, */ DtFecha *_fechaInicio, MetodoPago _metodo, Valor _tipo, bool _cancelada, Videojuego *_juego, Jugador *_jugador)
{
    // this->costo = _costo;
    this->fechaInicio = _fechaInicio;
    this->metodo = _metodo;
    this->tipo = _tipo;
    this->cancelada = _cancelada;
    this->juego = _juego;
    this->jugador = _jugador;
}
void Suscripcion::eliminarme()
{
    this->jugador->EliminarMiSuscripcion(this);
    delete (this);
}
Suscripcion::~Suscripcion() {}

std::string Suscripcion::GetNombreVideojuego()
{
    return juego->GetNombreVidJ();
}

std::string Suscripcion::GetNombreJugador()
{
    return jugador->Getnick();
}
#include "./../headers/Suscripcion.h"

Suscripcion::Suscripcion(float _costo,
	DtFecha _fechaInicio,
	enum MetodoPago _metodo,
	enum Valor _tipo,
	bool _cancelada,
	Videojuego *_juego) {
        this->costo = _costo;
        this->fechaInicio = _fechaInicio;
        this->metodo = _metodo;
        this->tipo = _tipo;
        this->cancelada = _cancelada;
        this->juego = _juego; 

    }
Suscripcion::~Suscripcion() {}

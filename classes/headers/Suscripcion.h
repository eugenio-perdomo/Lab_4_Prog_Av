#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H

#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../datatypes/headers/DtFecha.h"
#include "MetodoPago.h"
#include "Valor.h"
#include "Videojuego.h"

class Suscripcion : public ICollection
{
private:
	float costo;
	DtFecha fechaInicio;
	enum MetodoPago metodo;
	enum Valor tipo;
	bool cancelada;
	Videojuego *juego;

public:
	Suscripcion();

	float Getcosto() { return costo; }
	void Setcosto(float val) { costo = val; }
	DtFecha GetfechaInicio() { return fechaInicio; }
	void SetfechaInicio(DtFecha val) { fechaInicio = val; }

	MetodoPago Getmetodo() { return metodo; }
	void Setmetodo(MetodoPago val) { metodo = val; }

	Valor Gettipo() { return tipo; }
	void Settipo(Valor val) { tipo = val; }

	bool Getcancelada() { return cancelada; }
	void Setcancelada(bool val) { cancelada = val; }

	Videojuego *Getjuego() { return juego; }
	void Setjuego(Videojuego *val) { juego = val; }

	virtual ~Suscripcion();
};

#endif /* Suscripcion_H */

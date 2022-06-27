#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H

class Jugador;
class Videojuego;

#include "string.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../datatypes/headers/DtFecha.h"
#include "Jugador.h"
#include "Videojuego.h"
#include "MetodoPago.h"
#include "Valor.h"

class Suscripcion : public ICollectible
{
private:
	// float costo;
	DtFecha *fechaInicio;
	MetodoPago metodo;
	Valor tipo;
	bool cancelada;
	Videojuego *juego;
	Jugador *jugador;

public:
	Suscripcion();
	Suscripcion(/*float costo,*/ DtFecha *fechaInicio, MetodoPago metodo, Valor tipo, bool cancelada, Videojuego *juego, Jugador *jugador);

	/*float Getcosto() { return costo; }
	void Setcosto(float val) { costo = val; }*/
	DtFecha GetfechaInicio() { return *fechaInicio; }
	void SetfechaInicio(DtFecha *val) { fechaInicio = val; }

	MetodoPago Getmetodo() { return metodo; }
	void Setmetodo(MetodoPago val) { metodo = val; }

	Valor Gettipo() { return tipo; }
	void Settipo(Valor val) { tipo = val; }

	bool Getcancelada() { return cancelada; }
	void Setcancelada(bool val) { cancelada = val; }

	/*Videojuego Getjuego() { return *juego; }
	void Setjuego(Videojuego *val) { juego = val; }*/

	std::string GetNombreVideojuego();
	std::string GetNombreJugador();

	void eliminarme();
	virtual ~Suscripcion();
};

#endif /* Suscripcion_H */

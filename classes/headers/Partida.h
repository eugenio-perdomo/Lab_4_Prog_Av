#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../datatypes/headers/DtFecha.h"
#include "Videojuego.h"

class Partida : public ICollectible
{
protected:
	std::string id;
	std::string nombreVideojuego;
	bool finalizado;
	float duracionPartida; // En Minutos, el set va a ser un date.fin - date.inicio
	DtFecha fechaInicio;
	DtFecha fechaFin;
	Videojuego *juego;

public:
	Partida();
	Partida(std::string id,
			std::string nombreVideojuego,
			bool finalizado,
			float duracionPartida,
			DtFecha fechaInicio,
			DtFecha fechaFin,
			Videojuego *juego);

	std::string getId();
	std::string getNombreVideojuego();
	bool getFinalizado();
	float getDuracionPartida();
	DtFecha getFechaInicio();
	DtFecha getFechaFin();

	void setId(std::string id);
	void setNombreVideojuego(std::string nombreVideojuego);
	void setFinalizado(bool finalizado);
	void setDuracionPartida(float duracionPartida);
	void setFechaInicio(DtFecha fechaInicio);
	void setFechaFin(DtFecha fechaFin);

	void TerminarPartida(std::string id);

	virtual ~Partida();
};

#endif /* Partida_H */

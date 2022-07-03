#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H

#include "Partida.h"
#include "Transmision.h"

class Multijugador : public Partida
{
private:
	bool transmitidaEnVivo;
	// DtFecha *ultimaConexion;
	int cantJugadores;
	Transmision *transmision;
	// ICollection *jugadores;

public:
	Multijugador();
	Multijugador(bool transmitidaEnVivo, int cantJugadores, std::string _id, std::string _nombreVideojuego, bool _finalizado, float _duracionPartida, DtFecha *_fechaInicio, DtFecha *_fechaFin/*, ICollection *_listaJugadores*/);
	Multijugador(bool transmitidaEnVivo, int cantJugadores, std::string _id, std::string _nombreVideojuego, bool _finalizado, float _duracionPartida, DtFecha *_fechaInicio);

	bool getTransmitidaEnVivo();
	// DtFecha getUltimaConexion();
	int getCantJugadores();

	void setTransmitidaEnVivo(bool transmitidaEnVivo);
	// void setUltimaConexion(DtFecha *ultimaConexion);
	void setCantJugadores(int cantJugadores);

	Transmision *Gettransmision() { return transmision; }
	void Settransmision(Transmision *val) { transmision = val; }
	void eliminarMisComentarios();
	virtual ~Multijugador();
};

#endif /* Multijugador_H */

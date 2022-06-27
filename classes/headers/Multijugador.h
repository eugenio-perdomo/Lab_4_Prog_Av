#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H

#include "Partida.h"
#include "Transmision.h"
class Multijugador : public Partida
{
private:
	bool transmitidaEnVivo;
	DtFecha ultimaConexion;
	int cantJugadores;
	Transmision *transmision;

public:
	Multijugador();
	Multijugador(bool transmitidaEnVivo, DtFecha ultimaConexion, int cantJugadores);

	bool getTransmitidaEnVivo();
	DtFecha getUltimaConexion();
	int getCantJugadores();

	void setTransmitidaEnVivo(bool transmitidaEnVivo);
	void setUltimaConexion(DtFecha ultimaConexion);
	void setCantJugadores(int cantJugadores);

	Transmision *Gettransmision() { return transmision; }
	void Settransmision(Transmision *val) { transmision = val; }

	virtual ~Multijugador();
};

#endif /* Multijugador_H */

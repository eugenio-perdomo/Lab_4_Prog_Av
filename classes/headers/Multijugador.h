#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "./Partida.h"
// TODO: los nickjugadores pueden ser simplemente un string
// o tambien podemos utilizar la coleccion de partidas que tiene Jugador
// en el DCD está como DtJugador
// es un arreglo sin definir su maximo
// el set y get talvez vayan a ser diferentes

class Multijugador : public Partida
{
private:
	bool transmitidaEnVivo;
	std::string nickJugadores[10];
	DtFecha ultimaConexion;
	int cantJugadores;

public:
	Multijugador();
	Multijugador(bool transmitidaEnVivo,
				 std::string nickJugadores,
				 DtFecha ultimaConexion,
				 int cantJugadores);

	bool getTransmitidaEnVivo();
	std::string getNickJugadores();
	DtFecha getUltimaConexion();
	int getCantJugadores();

	void setTransmitidaEnVivo();
	void setNickJugadores();
	void setUltimaConexion();
	void setCantJugadores();

	virtual ~Multijugador();
};

#endif /* Multijugador_H */

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "./Partida.h"

class Individual : public Partida
{
private:
	bool esContinuacion;
	std::string nickJugador;

public:
	Individual();
	Individual(bool esContinuacion,
			   std::string nickJugador);

	bool getEsContinuacion();
	std::string getNickJugador();
	
	void setEsContinuacion(bool esContinuacion);
	void setNickJugador(std::string nickJugador);

	virtual ~Individual();
};

#endif /* Individual_H */

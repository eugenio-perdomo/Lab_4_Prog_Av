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
	
	void setEsContinuacion();
	void setNickJugador();

	virtual ~Individual();
};

#endif /* Individual_H */

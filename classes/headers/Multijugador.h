#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "./Partida.h"

class Multijugador : public Partida
{
private:

public:
	Multijugador();
	Multijugador();


	int get();
	void set();
	virtual ~Multijugador();
};

#endif /* Multijugador_H */

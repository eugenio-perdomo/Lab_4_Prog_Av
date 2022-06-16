#ifndef JUGADOR_H
#define JUGADOR_H
#include "./Usuario.h"

class Jugador : public Usuario
{
private:

public:
	Jugador();
	Jugador();


	int get();
	void set();
	virtual ~Jugador();
};

#endif /* Jugador_H */

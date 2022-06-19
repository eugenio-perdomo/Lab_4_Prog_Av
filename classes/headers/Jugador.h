#ifndef JUGADOR_H
#define JUGADOR_H
#include "./Usuario.h"

class Jugador : public Usuario
{
private:
	std::string nick;
	std::string descripcion;
	ICollection *suscripcion;

public:
	Jugador();

	std::string Getnick() { return nick; }
	void Setnick(std::string val) { nick = val; }
	std::string Getdescripcion() { return descripcion; }
	void Setdescripcion(std::string val) { descripcion = val; }

	virtual ~Jugador();
};

#endif /* Jugador_H */

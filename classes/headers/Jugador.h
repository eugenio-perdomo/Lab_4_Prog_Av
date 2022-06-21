#ifndef JUGADOR_H
#define JUGADOR_H
#include "./Usuario.h"
#include "./../../ICollection/collections/List.h"

class Jugador : public Usuario
{
private:
	std::string nick;
	std::string descripcion;
	IDictionary *suscripcion;
	ICollection *partidas;

public:
	Jugador();
	Jugador(std::string email, std::string contrasenia, std::string nick, std::string desc);

	std::string Getnick() { return nick; }
	void Setnick(std::string val) { nick = val; }
	std::string Getdescripcion() { return descripcion; }
	void Setdescripcion(std::string val) { descripcion = val; }

	std::string getContrasenia() { return contrasenia; }

	virtual ~Jugador();
};

#endif /* Jugador_H */

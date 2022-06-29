#ifndef JUGADOR_H
#define JUGADOR_H

class Partida;
class Suscripcion;

#include "Usuario.h"
#include "Suscripcion.h"
#include "Partida.h"
#include "../../ICollection/collections/List.h"

class Jugador : public Usuario
{
private:
	std::string nick;
	std::string descripcion;
	ICollection *suscripcion; // Luego definir si esto es una colleccion o es un IDictionary
							  // Va a cambiar el set, utilizando IKey
	IDictionary *partidas;

public:
	Jugador();
	Jugador(std::string email, std::string contrasenia, std::string nick, std::string desc);

	std::string Getnick() { return nick; }
	void Setnick(std::string val) { nick = val; }
	std::string Getdescripcion() { return descripcion; }
	void Setdescripcion(std::string val) { descripcion = val; }
    void setPartidas(Partida *p, IKey *k);
    IDictionary *getPartidas();

	std::string getContrasenia();

	void setSuscripcion(Suscripcion *_suscripcion);
	void setPartida(Partida *_partida);
	void EliminarMiSuscripcion(Suscripcion *s);

	bool verificarSuscripcion(std::string nombreJuego);
	bool verificarEsVitalicia(std::string nombreJuego);
	void cancelarSuscripcion(Videojuego *vj);



	void listarVideojuegosDeJugador();

	void listarPartidas();


	virtual ~Jugador();
};

#endif /* Jugador_H */

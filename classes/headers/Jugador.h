#ifndef JUGADOR_H
#define JUGADOR_H

class Partida;
class Suscripcion;
class Videojuego;
class Individual;
class Multijugador;

#include "Partida.h"
#include "Individual.h"
#include "Multijugador.h"
#include "Usuario.h"
#include "Suscripcion.h"
#include "../../datatypes/headers/DtFecha.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/Integer.h"

class Jugador : public Usuario
{
private:
	std::string nick;
	std::string descripcion;
	ICollection *suscripcion; // Luego definir si esto es una colleccion o es un IDictionary
							  // Va a cambiar el set, utilizando IKey
	IDictionary *partidas;
	IDictionary *partidasIndividuales;
	IDictionary *partidasMultijugador;

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
	void mostrarPartidasNoFinalizadas();

	void listarPartidasIndividualesFinalizadas(std::string nombreVideojuego);
	bool comprobarContinuacion(int id, std::string nombreVideojuego);

	void agregarIndividual(Individual* aux);
	void agregarMultijugador(Multijugador* aux);


	virtual ~Jugador();
};

#endif /* Jugador_H */

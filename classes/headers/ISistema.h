#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <string.h>
#include "../../ICollection/collections/List.h"
#include "../../ICollection/collections/ListIterator.h"
#include "../../ICollection/collections/ListNode.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/collections/OrderedDictionaryEntry.h"

#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/interfaces/IIterator.h"
#include "../../ICollection/interfaces/OrderedKey.h"
#include "../../ICollection/interfaces/IKey.h"

#include "../../ICollection/Integer.h"
#include "../../ICollection/String.h"
#include "../../ICollection/StringKey.h"

#include "../../datatypes/headers/DtFecha.h"
#include "Usuario.h"
#include "Desarrollador.h"
#include "Jugador.h"

#include "Partida.h"
#include "Multijugador.h"
#include "Individual.h"
#include "Transmision.h"
#include "Comentario.h"

#include "Videojuego.h"
#include "Estadistica.h"
#include "Categoria.h"
#include "Suscripcion.h"
class Sistema;

class ISistema
{
private:
public:
	virtual void menuCaso1(/*Sistema* s*/) = 0;
	virtual void menuCaso2(/*Sistema* s*/) = 0;
	virtual void menuCaso3(int i /*, Sistema* s*/) = 0;

	virtual void imprimirTextoPrincipal() = 0;
	virtual void imprimirTextoDelDesarrollador() = 0;
	virtual void imprimirTextoDelJugador() = 0;
	virtual void imprimirMenuDesarrollador() = 0;
	virtual void imprimirMenuJugador(Jugador *jugadorActual) = 0;
	virtual void clearDeDatosDeEntrada() = 0;

	// CASO DE USO 1: ALTA USUARIO
	virtual void agregarJugador(std::string email, std::string contrasenia, std::string nick, std::string desc) = 0;
	virtual void agregarDesarrollador(std::string email, std::string contrasenia, std::string empresa) = 0;

	// CASO DE USO 2: INICIAR SESION
	virtual int iniciarSesion(std::string email, std::string contrasenia) = 0;
	virtual Jugador *obtenerJugadorActual(std::string email) = 0;
	virtual Desarrollador *obtenerDesarrolladorActual(std::string email) = 0;

	// CASO DE USO 3: PUBLICAR VIDEOJUEGO
	virtual void mostrarCategorias() = 0;
	virtual Categoria *obtenerCategoria(std::string categoria) = 0;
	virtual void publicarVideojuego(/*Sistema* s*/) = 0;
	virtual void mostrarListaCategorias(List *lista) = 0;

	// CASO DE USO 4: SUSCRIBIRSE A VIDEOJUEGO
	virtual void suscribirseVideojuego() = 0;
	virtual void mostrarVideojuegos() = 0;

	// CASO DE USO : ELIMINAR VIDEOJUEGO
	virtual Videojuego *obtenerVideojuegodesarrollador(std::string videojuego) = 0;
	virtual void EliminarVideojuego(Desarrollador *d /*, Sistema* s*/) = 0;
	virtual void mostrarListaVideojuegos(List *lista) = 0;

	// CASO DE USO : FINALIZAR PARTIDA
	virtual void finalizarPartida(Jugador *jugadorActual) = 0;

	virtual ~ISistema();
};

#endif /* ISISTEMA_H */

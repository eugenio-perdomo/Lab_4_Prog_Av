#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <string.h>
#include "./../../ICollection/collections/List.h"
#include "./../../ICollection/collections/ListIterator.h"
#include "./../../ICollection/collections/ListNode.h"
#include "./../../ICollection/collections/OrderedDictionary.h"
#include "./../../ICollection/collections/OrderedDictionaryEntry.h"

#include "./../../ICollection/interfaces/ICollectible.h"
#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../ICollection/interfaces/IDictionary.h"
#include "./../../ICollection/interfaces/IIterator.h"
#include "./../../ICollection/interfaces/OrderedKey.h"
#include "./../../ICollection/interfaces/IKey.h"

#include "./../../ICollection/Integer.h"
#include "./../../ICollection/String.h"

#include "./../../datatypes/headers/DtFecha.h"
#include "./Usuario.h"
#include "./Desarrollador.h"
#include "./Jugador.h"

#include "./Partida.h"
#include "./Multijugador.h"
#include "./Individual.h"
#include "./Transmision.h"
#include "./Comentario.h"

#include "./Videojuego.h"
#include "./Estadistica.h"
#include "./Categoria.h"
#include "./Suscripcion.h"

class ISistema
{
private:

public:

    virtual void menuCaso1() = 0;
	virtual void menuCaso2() = 0;
	virtual void menuCaso3() = 0;
	virtual void imprimirTextoPrincipal() = 0;
	virtual void imprimirTextoDelDesarrollador() = 0;
	virtual void imprimirTextoDelJugador() = 0;
	virtual void imprimirMenuDesarrollador() = 0;
	virtual void imprimirMenuJugador() = 0;
	virtual void InicioSesion(std::string email, std::string contrasenia, int i) = 0;

    //CASO DE USO 1: ALTA USUARIO
	void agregarJugador(string email, string contrasenia, string nick, string desc)=0;
    void agregarDesarrollador(string email, string contrasenia, string empresa)=0;

    //CASO DE USO 2: INICIAR SESION
    int iniciarSesion(string email, string contrasenia)=0;
    jugador* obtenerJugadorActual(string email)=0;
    desarrollador* obtenerDesarrolladorActual(string email)=0;



	virtual ~ISistema();
};

#endif /* ISISTEMA_H */

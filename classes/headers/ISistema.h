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

class ISistema
{
private:

public:

    virtual void menuCaso1() = 0;
	virtual void menuCaso2() = 0;
	virtual void menuCaso3() = 0;
	virtual void imprimirTextoPrincipal() = 0;
	virtual void imprimirMenuDesarrollador() = 0;
	virtual void imprimirMenuJugador() = 0;
	virtual void InicioSesion(std::string email, std::string contrasenia, int i) = 0;

	virtual ~ISistema();
};

#endif /* ISISTEMA_H */

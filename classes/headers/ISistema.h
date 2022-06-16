#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>

#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../ICollection/interfaces/IDictionary.h"
#include "./../../datatypes/headers/DtFecha.h"
#include "./Usuario.h"

class ISistema
{
private:

public:

    virtual void menuCaso1() = 0;
	virtual void menuCaso2() = 0;
	virtual void menuCaso3() = 0;
	virtual void menuCaso4() = 0;
	virtual void imprimirTextoPrincipal() = 0;
	virtual void imprimirMenuAdministrador() = 0;
	virtual void imprimirMenuDocente() = 0;
	virtual void imprimirMenuEstudiante() = 0;
	virtual void InicioSesion(std::string email, std::string contrasenia, int i) = 0;

	virtual ~ISistema();
};

#endif /* ISISTEMA_H */

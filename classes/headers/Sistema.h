#ifndef SISTEMA_H
#define SISTEMA_H
#include "./ISistema.h"

//class ISistema;

class Sistema : public ISistema
{
private:
	IDictionary *usuarios;
	IDictionary *asignaturas;
	DtFecha *fecha;
	Usuario *actual;

public:
	Sistema();
	void menuCaso1();
	void menuCaso2();
	void menuCaso3();
	void imprimirTextoPrincipal();
	void imprimirMenuDesarrollador();
	void imprimirMenuJugador();
	void InicioSesion(std::string email, std::string contrasenia, int i);
	virtual ~Sistema();
};

#endif /* SISTEMA_H */

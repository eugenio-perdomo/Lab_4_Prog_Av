#ifndef SISTEMA_H
#define SISTEMA_H
#include "./ISistema.h"

class ISistema;

class Sistema : public ISistema
{
private:
	IDictionary * usuarios;
	IDictionary * asignaturas;
	DtFecha *fecha;
	Usuario *actual;
public:
	Sistema();
	void menuCaso1();
	void menuCaso2();
	void menuCaso3();
	void menuCaso4();
	void imprimirTextoPrincipal();
	void imprimirMenuAdministrador();
	void imprimirMenuDocente();
	void imprimirMenuEstudiante();
	void InicioSesion(std::string email, std::string contrasenia, int i);
	virtual ~Sistema();
};

#endif /* SISTEMA_H */

#ifndef SISTEMA_H
#define SISTEMA_H
#include "./ISistema.h"

//class ISistema;

class Sistema : public ISistema
{
private:
	IDictionary *videojuegos;
	IDictionary *categorias;
	IDictionary *jugadores;
	IDictionary *desarrolladores;
	DtFecha *fechaDelSistema;
	Usuario *usuarioActual;

public:
	Sistema();
	void menuCaso1(); // Alta de usuario
	void menuCaso2(); // Iniciar sesión
	void menuCaso3(); // Cargar datos de prueba
	void imprimirTextoPrincipal();
	void imprimirTextoDelDesarrollador();
	void imprimirTextoDelJugador();
	void imprimirMenuDesarrollador();
	void imprimirMenuJugador();
	void InicioSesion(std::string email, std::string contrasenia, int i);
	virtual ~Sistema();
};

#endif /* SISTEMA_H */

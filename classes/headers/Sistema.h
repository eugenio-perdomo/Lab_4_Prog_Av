#ifndef SISTEMA_H
#define SISTEMA_H
#include "./ISistema.h"

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

	// CASO DE USO 1: ALTA USUARIO
	void agregarJugador(std::string email, std::string contrasenia, std::string nick, std::string desc);
	void agregarDesarrollador(std::string email, std::string contrasenia, std::string empresa);

	// CASO DE USO 2: INICIAR SESION
	int iniciarSesion(std::string email, std::string contrasenia);
	Jugador *obtenerJugadorActual(std::string email);
	Desarrollador *obtenerDesarrolladorActual(std::string email);

	virtual ~Sistema();
};

#endif /* SISTEMA_H */
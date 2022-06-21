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

    //CASO DE USO 1: ALTA USUARIO
	void agregarJugador(string email, string contrasenia, string nick, string desc);
    void agregarDesarrollador(string email, string contrasenia, string empresa);

    //CASO DE USO 2: INICIAR SESION
    int iniciarSesion(string email, string contrasenia);
    jugador* obtenerJugadorActual(string email);
    desarrollador* obtenerDesarrolladorActual(string email);

	virtual ~Sistema();
};

#endif /* SISTEMA_H */
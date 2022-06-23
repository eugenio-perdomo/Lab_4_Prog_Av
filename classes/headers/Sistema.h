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
	void menuCaso1(Sistema* s); // Alta de usuario
	void menuCaso2(Sistema* s); // Iniciar sesión
	void menuCaso3(int i, Sistema* s); // Cargar datos de prueba
	
	void imprimirTextoPrincipal();
	void imprimirTextoDelDesarrollador();
	void imprimirTextoDelJugador();
	void imprimirMenuDesarrollador();
	void imprimirMenuJugador();

	// CASO DE USO 1: ALTA USUARIO
	void agregarJugador(std::string email, std::string contrasenia, std::string nick, std::string desc);
	void agregarDesarrollador(std::string email, std::string contrasenia, std::string empresa);

	// CASO DE USO 2: INICIAR SESION
	int iniciarSesion(std::string email, std::string contrasenia);
	Jugador *obtenerJugadorActual(std::string email);
	Desarrollador *obtenerDesarrolladorActual(std::string email);

	// CASO DE USO 3: PUBLICAR VIDEOJUEGO
	void mostrarCategorias();
	Categoria* obtenerCategoria(std::string categoria);
	void publicarVideojuego(Sistema *s);

	void mostrarListaCategorias(List* lista);

	virtual ~Sistema();
};

#endif /* SISTEMA_H */
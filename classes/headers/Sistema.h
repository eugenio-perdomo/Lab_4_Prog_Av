#ifndef SISTEMA_H
#define SISTEMA_H
#include "ISistema.h"

class Sistema : public ISistema
{
private:
	IDictionary *videojuegos;
	IDictionary *categorias;
	IDictionary *jugadores;
	IDictionary *desarrolladores;
	DtFecha *fechaDelSistema;
	Usuario *usuarioActual;
	Desarrollador *desarrolladorActual;
	Jugador *jugadorActual;
	//ICollection *listaJugadores;
	int ultimaPartida = 6;

public:
	Sistema();
	void menuCaso1();			// Alta de usuario
	void menuCaso2();			// Iniciar sesión
	void menuCaso3(int i); // Cargar datos de prueba

	void imprimirTextoPrincipal();
	void imprimirTextoDelDesarrollador();
	void imprimirTextoDelJugador();
	void imprimirMenuDesarrollador();
	void imprimirMenuJugador(Jugador *jugadorActual);
	void clearDeDatosDeEntrada();

	DtFecha *obtenerFecha();
	int calcularDiferenciaFecha(DtFecha *hora1);

	// CASO DE USO 1: ALTA USUARIO
	void agregarJugador(std::string email, std::string contrasenia, std::string nick, std::string desc);
	void agregarDesarrollador(std::string email, std::string contrasenia, std::string empresa);

	// CASO DE USO 2: INICIAR SESION
	int iniciarSesion(std::string email, std::string contrasenia);
	Jugador *obtenerJugadorActual(std::string email);
	Desarrollador *obtenerDesarrolladorActual(std::string email);

	// CASO DE USO 3: PUBLICAR VIDEOJUEGO
	void mostrarCategorias();
	Categoria *obtenerCategoria(std::string categoria);
	void publicarVideojuego(Desarrollador *d);
	void mostrarListaCategorias(List *lista);

	// CASO DE USO 4: SUSCRIBIRSE A VIDEOJUEGO
	void suscribirseVideojuego();
	void mostrarVideojuegos();
	Videojuego *GetUnVideojuego(StringKey *nombreVideojuego);

	// CASO DE USO : ELIMINAR VIDEOJUEGO
	void EliminarVideojuego();
	void mostrarListaVideojuegos(List *lista);

	// CASO DE USO : INICIAR PARTIDA
	void iniciarPartida();
	void listarJugadoresPorSuscripcion(std::string videojuego, std::string host);
	bool confirmarJugadoresPorSuscripcion(std::string jugador, std::string videojuego);
	std::string generarIdPartida();

	// CASO DE USO : FINALIZAR PARTIDA
	void finalizarPartida();

	// CASO DE USO : VER INFO VIDEOJUEGO
	virtual void VerInfoVideoJuego();

	virtual ~Sistema();
};

#endif /* SISTEMA_H */

#ifndef DESARROLLADOR_H_INCLUDED
#define DESARROLLADOR_H_INCLUDED

#include "Usuario.h"
#include "Videojuego.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"

class Desarrollador : public Usuario
{
private:
	std::string empresa;
public:
	IDictionary *videojuegosdesarrollador;
	Desarrollador();
	Desarrollador(std::string email, std::string contrasenia, std::string empresa);

	std::string Getempresa() { return empresa; }
	void Setempresa(std::string val) { empresa = val; }
	void setVideoJuego(Videojuego *vj, IKey *id);
	std::string getContrasenia() { return contrasenia; }
	void mostrarVideojuegosDesarrollador(IDictionary *listaVid);
	void EliminarEsteJuego(Videojuego *v);
	Videojuego *obtenerVideojuegodesarrollador(std::string _videojuego);
	bool existeEsteVideojuego(StringKey* nombre);


	virtual ~Desarrollador();
};

#endif /* ESTUDIANTE_H */

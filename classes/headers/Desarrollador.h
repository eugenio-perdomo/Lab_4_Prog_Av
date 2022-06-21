#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "./Usuario.h"

class Desarrollador : public Usuario
{
private:
	std::string empresa;
	// TODO El order Dictionary para Videojuegos

public:
	Desarrollador();
	Desarrollador(std::string email, std::string contrasenia, std::string empresa);

	std::string Getempresa() { return empresa; }
	void Setempresa(std::string val) { empresa = val; }

	std::string getContrasenia() { return contrasenia; }

	virtual ~Desarrollador();
};

#endif /* ESTUDIANTE_H */

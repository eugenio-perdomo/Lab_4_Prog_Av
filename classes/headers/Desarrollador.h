#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "./Usuario.h"

class Desarrollador : public Usuario
{
private:
	std::string empresa;

public:
	Desarrollador();
	Desarrollador(std::string empresa);
	Desarrollador(std::string empresa, std::string _email, std::string _contrasenia);

	std::string getCi();
	void setCi(std::string empresa);
	virtual ~Desarrollador();
};

#endif /* ESTUDIANTE_H */

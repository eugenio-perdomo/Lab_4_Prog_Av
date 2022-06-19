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

	std::string Getempresa() { return empresa; }
	void Setempresa(std::string val) { empresa = val; }

	virtual ~Desarrollador();
};

#endif /* ESTUDIANTE_H */

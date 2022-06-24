#ifndef CATEGORIA_H
#define CATEGORIA_H

#include "../../ICollection/interfaces/ICollection.h"
#include "string"

class Categoria : public ICollectible
{
private:
	std::string nombre;
	std::string descripcion;
	std::string tipo;

public:
	Categoria();
	Categoria(std::string nombre,std::string descripcion, std::string tipo);
	std::string Getnombre() { return nombre; }
	void Setnombre(std::string val) { nombre = val; }
	std::string Getdescripcion() { return descripcion; }
	void Setdescripcion(std::string val) { descripcion = val; }
	std::string Getplataforma() { return tipo; }
	void Setplataforma(std::string val) { tipo = val; }

	virtual ~Categoria();
};

#endif /* Categoria_H */

#ifndef CATEGORIA_H
#define CATEGORIA_H

#include "./../../ICollection/interfaces/ICollection.h"
#include "string"

class Categoria : public ICollection
{
private:
	std::string nombre;
	std::string descripcion;
	bool plataforma;

public:
	Categoria();
	//Categoria::Categoria(std::string nombre,std::string descripcion,bool plataforma);
	std::string Getnombre() { return nombre; }
	void Setnombre(std::string val) { nombre = val; }
	std::string Getdescripcion() { return descripcion; }
	void Setdescripcion(std::string val) { descripcion = val; }
	bool Getplataforma() { return plataforma; }
	void Setplataforma(bool val) { plataforma = val; }

	virtual ~Categoria();
};

#endif /* Categoria_H */

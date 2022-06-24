#ifndef VIJEOJUEGO_H
#define VIJEOJUEGO_H

#include "string"
#include "./Estadistica.h"
#include "./Categoria.h"
#include "./Suscripcion.h"
#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../ICollection/collections/List.h"
#include "./../../ICollection/collections/OrderedDictionary.h"

class Suscripcion;

class Videojuego: public ICollectible
{
private:
	std::string nombre;
	std::string descripcion;
	float costoVitalicia;
	float costoMensual;
	float costoTrimestral;
	float costoAnual;
	Estadistica *est;
	ICollection *categoria;
	ICollection *suscripcion;
	IDictionary *partidas;

public:
	Videojuego();

	Videojuego(std::string nom, std::string desc, float costoM, float costoT, float costoA, float costoV, List* cat);

	Videojuego(std::string nombre, std::string descripcion, float costoVitalicia, float costoMensual, float costoTrimestral,
			   float costoAnual, Estadistica *est);
	std::string Getnombre() { return nombre; }
	void Setnombre(std::string val) { nombre = val; }
	std::string Getdescripcion() { return descripcion; }
	void Setdescripcion(std::string val) { descripcion = val; }
	float GetcostoVitalicia() { return costoVitalicia; }
	void SetcostoVitalicia(float val) { costoVitalicia = val; }
	float GetcostoMensual() { return costoMensual; }
	void SetcostoMensual(float val) { costoMensual = val; }
	float GetcostoTrimestral() { return costoTrimestral; }
	void SetcostoTrimestral(float val) { costoTrimestral = val; }
	float GetcostoAnual() { return costoAnual; }
	void SetcostoAnual(float val) { costoAnual = val; }
	Estadistica *Getestadistica() { return est; }
	void Setestadistica(Estadistica *val) { est = val; }
	void eliminarme();
	void setCategoria(Categoria *c);
	void setSuscripcion(Suscripcion *s);
	void Borrame();

	virtual ~Videojuego();
};

#endif /* Videojuego_H */

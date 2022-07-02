#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

class Suscripcion;
class Desarrollador;

#include "string"
#include "Estadistica.h"
#include "Categoria.h"
#include "Partida.h"
#include "Suscripcion.h"
#include "Desarrollador.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/StringKey.h"

class Videojuego : public ICollectible
{
private:
	std::string nombre;
	std::string descripcion;
	float costoVitalicia;
	float costoMensual;
	float costoTrimestral;
	float costoAnual;
	Estadistica *est;
	Desarrollador *desarrollador;
	ICollection *categoria;
	ICollection *suscripcion;
	IDictionary *partidas;
	
public:
	Videojuego();

	Videojuego(std::string nom, std::string desc, float costoM, float costoT, float costoA, float costoV, List *cat);
	void setPartidaParaVideojuego(Partida *part, IKey *_id);


	Videojuego(std::string nombre, std::string descripcion, float costoVitalicia, float costoMensual, float costoTrimestral, float costoAnual, Estadistica *est, Desarrollador * des);

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
	void setDesarrollador(Desarrollador *d);
	Estadistica *Getestadistica() { return est; }
	Desarrollador *GetDesarrollador();
	void Setestadistica(Estadistica *val) { est = val; }
	void eliminarme();
	void setCategoria(Categoria *c);
	void setSuscripcion(Suscripcion *s);
	void Borrame();
	void getCategorias();
	bool tienepartidas();

	void cancelarSuscripcion(std::string nick);

	virtual ~Videojuego();
};

#endif /* Videojuego_H */

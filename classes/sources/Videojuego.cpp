#include "./../headers/Videojuego.h"

Videojuego::Videojuego(std::string _nombre, std::string _descripcion, float _costoVitalicia, float _costoMensual, float _costoTrimestral,
                       float _costoAnual, Estadistica *_est)
{
    this->nombre = _nombre;
    this->descripcion = _descripcion;
    this->costoVitalicia = _costoVitalicia;
    this->costoMensual = _costoMensual;
    this->costoTrimestral = _costoTrimestral;
    this->costoAnual = _costoAnual;
    this->est = _est;
    this->categoria = new List();
    this->suscripcion = new List();
    this->partidas = new OrderedDictionary;
}

Videojuego::Videojuego(std::string nom, std::string desc, float costoM, float costoT, float costoA, float costoV, List* cat){
    this->nombre=nom;
    this->descripcion=desc;
    this->costoMensual=costoM;
    this->costoTrimestral=costoT;
    this->costoAnual=costoA;
    this->costoVitalicia=costoV;
    this->suscripcion= new List();
    this->categoria=new List();
    this->categoria=cat;

}


Videojuego::Videojuego()
{
    this->categoria = new List();
    this->suscripcion = new List();
}

void Videojuego::setCategoria(Categoria *c)
{
    this->categoria->add(c);
}

void Videojuego::setSuscripcion(Suscripcion *s)
{
    this->suscripcion->add(s);
}

Videojuego::~Videojuego() {}

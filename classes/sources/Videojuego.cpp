#include "./../headers/Videojuego.h"

Videojuego::Videojuego(std::string _nombre,std::string _descripcion,float _costoVitalicia,float _costoMensual,float _costoTrimestral,
float _costoAnual,Estadistica *_est
)
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
}
Videojuego::Videojuego() {
    this->categoria = new List();
    this->suscripcion = new List();}

Videojuego::~Videojuego() {}

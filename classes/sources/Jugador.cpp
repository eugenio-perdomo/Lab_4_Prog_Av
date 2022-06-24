#include "../headers/Jugador.h"

Jugador::Jugador()
{
    // Seria new OrderedDictionary() en caso de ser parte de IDictionary
    this->suscripcion = new List();
    this->partidas = new List();
}

Jugador::Jugador(std::string _email, std::string _contrasenia, std::string _nick, std::string _desc) : Usuario(_email, _contrasenia)
{
    this->nick = _nick;
    this->descripcion = _desc;
    this->suscripcion = new List();
    this->partidas = new List();
}

std::string Jugador::getContrasenia()
{
    return this->contrasenia;
}
void Jugador::setSuscripcion(Suscripcion *_suscripcion)
{
    /*
        IKey *k = new String(jug->getEmail());
        this->suscripcion->add(k, jug);
    */
    this->suscripcion->add(_suscripcion);
}
void Jugador::setPartida(Partida *_partida)
{
    this->partidas->add(_partida);
}

void Jugador::EliminarMiSuscripcion(Suscripcion *s){
    this->suscripcion->remove(s);
}
Jugador::~Jugador() {}

bool Jugador::verificarSuscripcion(std::string nombreJuego){

    bool resultado = false;

    IIterator* it = suscripcion->getIterator();

    while (it->hasCurrent()){
        Suscripcion* aux=dynamic_cast<Suscripcion*>(it->getCurrent());

        if (aux->GetNombreVideojuego()==nombreJuego){
            resultado = true;
        }
        it->next();
    }  
    return resultado;
}

bool Jugador::verificarEsVitalicia(std::string nombreJuego){

    bool resultado = false;
    IIterator* it = suscripcion->getIterator();

    while(it->hasCurrent()){
        Suscripcion* aux=dynamic_cast<Suscripcion*>(it->getCurrent());
        
        if (aux->GetNombreVideojuego()==nombreJuego){
            if (aux->Gettipo()==Vitalicia){
                resultado = true;
            }
        }
        it->next();
    }  
    return resultado;
}

void Jugador::cancelarSuscripcion(Videojuego* vj){
    suscripcion->remove(vj);
}
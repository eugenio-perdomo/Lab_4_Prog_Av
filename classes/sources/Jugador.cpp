#include "../headers/Jugador.h"

Jugador::Jugador()
{
    // Seria new OrderedDictionary() en caso de ser parte de IDictionary
    this->suscripcion = new List();
    this->partidas = new OrderedDictionary;
    this->partidasIndividuales = new OrderedDictionary();
    this->partidasMultijugador = new OrderedDictionary();
}

Jugador::Jugador(std::string _email, std::string _contrasenia, std::string _nick, std::string _desc) : Usuario(_email, _contrasenia)
{
    this->nick = _nick;
    this->descripcion = _desc;
    this->suscripcion = new List();
    this->partidas = new OrderedDictionary;
    this->partidasIndividuales = new OrderedDictionary();
    this->partidasMultijugador = new OrderedDictionary();
}

std::string Jugador::getContrasenia()
{
    return this->contrasenia;
}
void Jugador::setSuscripcion(Suscripcion *_suscripcion)
{
    this->suscripcion->add(_suscripcion);
}

void Jugador::setPartidas(Partida *p, IKey *id)
{
    this->partidas->add(id, p);
}

IDictionary *Jugador::getPartidas()
{
    return this->partidas;
}

void Jugador::EliminarMiSuscripcion(Suscripcion *s)
{
    this->suscripcion->remove(s);
}
Jugador::~Jugador() {}

bool Jugador::verificarSuscripcion(std::string nombreJuego)
{

    bool resultado = false;

    IIterator *it = suscripcion->getIterator();

    while (it->hasCurrent())
    {
        Suscripcion *aux = dynamic_cast<Suscripcion *>(it->getCurrent());

        if (aux->GetNombreVideojuego() == nombreJuego)
        {

            if (aux->Getcancelada() == false)
            {
                resultado = true;
            }
        }
        it->next();
    }
    return resultado;
}

bool Jugador::verificarEsVitalicia(std::string nombreJuego)
{

    bool resultado = false;
    IIterator *it = suscripcion->getIterator();

    while (it->hasCurrent())
    {
        Suscripcion *aux = dynamic_cast<Suscripcion *>(it->getCurrent());

        if (aux->GetNombreVideojuego() == nombreJuego)
        {
            if (aux->Getcancelada() == false)
            {
                if (aux->Gettipo() == Vitalicia)
                {
                    resultado = true;
                }
            }
        }
        it->next();
    }
    return resultado;
}

void Jugador::cancelarSuscripcion(Videojuego *vj)
{

    IIterator *it = suscripcion->getIterator();

    while (it->hasCurrent())
    {
        Suscripcion *aux = dynamic_cast<Suscripcion *>(it->getCurrent());

        if (aux->GetNombreVideojuego() == vj->Getnombre())
        {
            aux->Setcancelada(true);
        }
        it->next();
    }

    // suscripcion->remove(vj);
}


void Jugador::listarVideojuegosDeJugador(){

    IIterator *it = suscripcion->getIterator();

    while (it->hasCurrent()){
        Suscripcion *aux = dynamic_cast<Suscripcion*>(it->getCurrent());

        if (aux->Getcancelada()==false){
            std::cout << aux->GetNombreVideojuego();
        }

        it->next();
    }
}

void Jugador::listarPartidasIndividualesFinalizadas(std::string nombreVideojuego){
    IIterator *it = partidasIndividuales->getIterator();

    while (it->hasCurrent()){
        Individual *aux = dynamic_cast<Individual*>(it->getCurrent());

        if (aux->getFinalizado()==true && aux->getNombreVideojuego()==nombreVideojuego){
            std::cout << "\nID: " << aux->getId();
            std::cout << "\nDuracion: " << aux->getDuracionPartida();
            std::cout << "\nInicio: " << aux->getFechaInicio()->getDia() << "/" << aux->getFechaInicio()->getMes() << "/" << aux->getFechaInicio()->getAnio() << " " << aux->getFechaInicio()->getHora() << ":" << aux->getFechaInicio()->getMinuto();
            std::cout << "\nInicio: " << aux->getFechaFin()->getDia() << "/" << aux->getFechaFin()->getMes() << "/" << aux->getFechaFin()->getAnio() << " " << aux->getFechaFin()->getHora() << ":" << aux->getFechaFin()->getMinuto();
        }

        it->next();
    }
}

bool Jugador::comprobarContinuacion(int id, std::string nombreVideojuego){

    Integer* key = new Integer(id);
    bool resultado=false;
    
    if (partidasIndividuales->member(key)){
        Individual *aux = dynamic_cast<Individual*>(partidasIndividuales->find(key));

        if (aux->getFinalizado()==true && aux->getNombreVideojuego()==nombreVideojuego){
            resultado=true;
        }
    }

    return resultado;
}

void Jugador::agregarIndividual(Individual* aux){
    StringKey* key = new StringKey(aux->getId());

    partidasIndividuales->add(key,aux); 
    partidas->add(key,aux);
}

void Jugador::agregarMultijugador(Multijugador* aux){
    StringKey* key = new StringKey(aux->getId());

    partidasMultijugador->add(key,aux); 
    partidas->add(key,aux);
}
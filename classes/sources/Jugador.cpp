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

        if (aux->GetNombreVideojuego() == vj->GetNombreVidJ())
        {
            aux->Setcancelada(true);
        }
        it->next();
    }

    // suscripcion->remove(vj);
}

void Jugador::mostrarPartidasNoFinalizadas()
{
    IIterator *itM = this->partidasMultijugador->getIterator();
    std::cout << "\e[0;35mPartidas Multijugador: \n\e[0m";
    while (itM->hasCurrent())
    {
        Partida *aux1 = dynamic_cast<Partida *>(itM->getCurrent());
        bool finalizada = aux1->getFinalizado();

        if (finalizada == false)
        {
            std::cout << "\e[0;35mId: " << aux1->getId() << "\n\e[0m";
            std::cout << "\e[0;35mNombre: " << aux1->getNombreVideojuego() << "\n\e[0m" << std::endl;
        }
        itM->next();
    }
    delete itM;

    IIterator *it = this->partidasIndividuales->getIterator();
    std::cout << "\e[0;35mPartidas Individuales: \n\e[0m";
    while (it->hasCurrent())
    {
        Partida *aux = dynamic_cast<Partida *>(it->getCurrent());
        bool finalizada = aux->getFinalizado();

        if (finalizada == false)
        {
            std::cout << "\e[0;35mId: " << aux->getId() << "\n\e[0m";
            std::cout << "\e[0;35mNombre: " << aux->getNombreVideojuego() << "\n\e[0m" << std::endl;
        }
        it->next();
    }
    delete it;
}

void Jugador::listarVideojuegosDeJugador()
{
    IIterator *it = suscripcion->getIterator();
    std::cout << "\e[1;35mVideojuegos: ";
    while (it->hasCurrent())
    {
        Suscripcion *aux = dynamic_cast<Suscripcion *>(it->getCurrent());

        if (aux->Getcancelada() == false)
        {
            std::cout << std::endl
                      << aux->GetNombreVideojuego() << std::endl;
        }
        it->next();
    }
}

void Jugador::listarPartidasIndividualesFinalizadas(std::string nombreVideojuego)
{
    IIterator *it = partidasIndividuales->getIterator();
    std::cout << "\e[1;36mPartidas: ";

    while (it->hasCurrent())
    {
        Individual *aux = dynamic_cast<Individual *>(it->getCurrent());

        if (aux->getFinalizado() == true && aux->getNombreVideojuego() == nombreVideojuego)
        {
            std::cout << "\n\nID: " << aux->getId();
            std::cout << "\nDuracion: " << aux->getDuracionPartida();
            std::cout << "\nInicio: " << aux->getFechaInicio()->getDia() << "/" << aux->getFechaInicio()->getMes() << "/" << aux->getFechaInicio()->getAnio() << " " << aux->getFechaInicio()->getHora() << ":" << aux->getFechaInicio()->getMinuto();
            std::cout << "\nInicio: " << aux->getFechaFin()->getDia() << "/" << aux->getFechaFin()->getMes() << "/" << aux->getFechaFin()->getAnio() << " " << aux->getFechaFin()->getHora() << ":" << aux->getFechaFin()->getMinuto();
        }

        it->next();
    }
}

bool Jugador::comprobarContinuacion(int id, std::string nombreVideojuego)
{

    Integer *key = new Integer(id);
    bool resultado = false;

    if (partidasIndividuales->member(key))
    {
        Individual *aux = dynamic_cast<Individual *>(partidasIndividuales->find(key));

        if (aux->getFinalizado() == true && aux->getNombreVideojuego() == nombreVideojuego)
        {
            resultado = true;
        }
    }

    return resultado;
}

void Jugador::agregarIndividual(Individual *aux)
{
    StringKey *key = new StringKey(aux->getId());
    partidasIndividuales->add(key, aux);
    partidas->add(key, aux);
}

void Jugador::agregarMultijugador(Multijugador *aux)
{
    StringKey *key = new StringKey(aux->getId());
    partidasMultijugador->add(key, aux);
    partidas->add(key, aux);
}

bool Jugador::esMultiJugador(StringKey *key)
{
    bool resultado = partidasMultijugador->member(key);
    return resultado;
}

bool Jugador::esIndividual(StringKey *key)
{
    bool resultado = partidasIndividuales->member(key);
    return resultado;
}

Individual *Jugador::getIndividual(StringKey *key)
{
    Individual *aux = dynamic_cast<Individual *>(partidasIndividuales->find(key));
    return aux;
}

Multijugador *Jugador::getMultijugador(StringKey *key)
{
    Multijugador *aux = dynamic_cast<Multijugador *>(partidasMultijugador->find(key));
    return aux;
}

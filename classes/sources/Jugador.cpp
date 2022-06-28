#include "../headers/Jugador.h"

Jugador::Jugador()
{
    // Seria new OrderedDictionary() en caso de ser parte de IDictionary
    this->suscripcion = new List();
    this->partidas = new OrderedDictionary;
}

Jugador::Jugador(std::string _email, std::string _contrasenia, std::string _nick, std::string _desc) : Usuario(_email, _contrasenia)
{
    this->nick = _nick;
    this->descripcion = _desc;
    this->suscripcion = new List();
    this->partidas = new OrderedDictionary;
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
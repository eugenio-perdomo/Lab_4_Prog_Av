#include "../headers/Videojuego.h"

Videojuego::Videojuego(std::string _nombre, std::string _descripcion, float _costoVitalicia, float _costoMensual, float _costoTrimestral,
                       float _costoAnual, Estadistica *_est, Desarrollador *_des)
{
    this->nombre = _nombre;
    this->descripcion = _descripcion;
    this->costoVitalicia = _costoVitalicia;
    this->costoMensual = _costoMensual;
    this->costoTrimestral = _costoTrimestral;
    this->costoAnual = _costoAnual;
    this->est = _est;
    this->desarrollador = _des;
    this->categoria = new List();
    this->suscripcion = new List();
    this->partidas = new OrderedDictionary;
}

Videojuego::Videojuego(std::string nom, std::string desc, float costoM, float costoT, float costoA, float costoV, List *cat)
{
    this->nombre = nom;
    this->descripcion = desc;
    this->costoMensual = costoM;
    this->costoTrimestral = costoT;
    this->costoAnual = costoA;
    this->costoVitalicia = costoV;
    this->suscripcion = new List();
    this->categoria = new List();
    this->categoria = cat;
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

void Videojuego::eliminarme()
{
    delete (this->est);
    IIterator *it = this->suscripcion->getIterator();
    while (it->hasCurrent())
    {
        Suscripcion *sus = dynamic_cast<Suscripcion *>(it->getCurrent());
        suscripcion->remove(sus);
        sus->eliminarme();
        delete (sus);
        it->next();
    }

    IIterator *itP = this->partidas->getIterator();
    while (it->hasCurrent())
    {
        Partida *part = dynamic_cast<Partida *>(it->getCurrent());
        StringKey *key = new StringKey(part->getId());
        partidas->remove(key);
        part->eliminarme();
        delete (part);
        it->next();
    }
    delete it;
    delete itP;
}
void Videojuego::Borrame()
{
    delete (this);
}

void Videojuego::getCategorias(){
    IIterator *it = this->categoria->getIterator();
    while (it->hasCurrent())
    {
        Categoria *cat = dynamic_cast<Categoria *>(it->getCurrent());
        std::cout << cat->Getnombre();
        it->next();
    }
    delete it;
}

Videojuego::~Videojuego() {}

void Videojuego::cancelarSuscripcion(std::string nick)
{
    IIterator *it = suscripcion->getIterator();

    while (it->hasCurrent())
    {
        Suscripcion *aux = dynamic_cast<Suscripcion *>(it->getCurrent());

        if (aux->GetNombreJugador() == nick)
        {
            if (aux->Getcancelada() == false)
            {
                aux->Setcancelada(true);
            }
        }
    }
}

#include "../headers/Videojuego.h"
Videojuego::Videojuego() {}

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
    this->partidas = new OrderedDictionary();
    this->partidasIndividuales = new OrderedDictionary();
    this->partidasMultijugador = new OrderedDictionary();
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
    this->partidas = new OrderedDictionary();
    this->partidasIndividuales = new OrderedDictionary();
    this->partidasMultijugador = new OrderedDictionary();

    IIterator *i = cat->getIterator();
    Categoria *eachCat;

    while (i->hasCurrent())
    {
        eachCat = (Categoria *)i->getCurrent();
        setCategoria(eachCat);
        i->next();
    }
    delete i;
}

void Videojuego::setCategoria(Categoria *c)
{
    this->categoria->add(c);
}

void Videojuego::setSuscripcion(Suscripcion *s)
{
    this->suscripcion->add(s);
}

void Videojuego::setPartidaParaVideojuego(Partida *part, IKey *_id)
{
    this->partidas->add(_id, part);
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
        // part->eliminarme(); TODO Este no va mas a partidas, va a multijugador
        // dentro de 'partidas' hay que ver si existen multis
        // Así como está va a remover las individuales y las multis, sin pasar por Transmision ni Comentarios.
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

std::string Videojuego::GetNombreVidJ()
{
    return this->nombre;
}

void Videojuego::getCategorias()
{
    IIterator *it = this->categoria->getIterator();
    std::cout << "\e[0;36mCategorias: \n";
    while (it->hasCurrent())
    {
        Categoria *cat = dynamic_cast<Categoria *>(it->getCurrent());
        std::cout << cat->Getnombre() << std::endl;
        it->next();
    }
    std::cout << "\e[0m\n";
    delete it;
}

bool Videojuego::tienepartidas()
{
    bool finalizada = false;
    IIterator *it = this->partidas->getIterator();

    while (it->hasCurrent())
    {
        Partida *par = dynamic_cast<Partida *>(it->getCurrent());

        if (par != 0)
        {
            finalizada = par->getFinalizado();
            if (finalizada == false)
            {
                return true;
            }
        }
        it->next();
    }

    delete it;
    return false;
}

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
        it->next();
    }
}

void Videojuego::agregarIndividual(Individual *aux)
{
    StringKey *key = new StringKey(aux->getId());

    partidasIndividuales->add(key, aux);
    partidas->add(key, aux);
}

void Videojuego::agregarMultijugador(Multijugador *aux)
{
    StringKey *key = new StringKey(aux->getId());

    partidasMultijugador->add(key, aux);
    partidas->add(key, aux);
}

void Videojuego::setDesarrollador(Desarrollador *d)
{
    this->desarrollador = d;
}

Desarrollador *Videojuego::GetDesarrollador()
{
    return this->desarrollador;
}

Videojuego::~Videojuego() {}

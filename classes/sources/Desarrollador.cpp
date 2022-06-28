#include "../headers/Desarrollador.h"

Desarrollador::Desarrollador() {}

Desarrollador::Desarrollador(std::string _email, std::string _contrasenia, std::string _empresa) : Usuario(_email, _contrasenia)
{
    this->empresa = _empresa;
    this->videojuegosdesarrollador = new OrderedDictionary;
}
void Desarrollador::mostrarVideojuegosDesarrollador()
{
    IIterator *it = this->videojuegosdesarrollador->getIterator();
    while (it->hasCurrent())
    {
        Videojuego *aux = dynamic_cast<Videojuego *>(it->getCurrent());
        bool tiene = aux->tienepartidas();
        if(tiene == false) std::cout << "\e[0;35m" << aux->Getnombre() << "\n\e[0m";

        it->next();
    }
}

void Desarrollador::setVideoJuego(Videojuego *vj, IKey *id)
{
    this->videojuegosdesarrollador->add(id, vj);
}


void Desarrollador::EliminarEsteJuego(Videojuego *v)
{
    v->eliminarme();
    StringKey *key = new StringKey(v->Getnombre());
    videojuegosdesarrollador->remove(key);
    v->Borrame();
}

Desarrollador::~Desarrollador() {}

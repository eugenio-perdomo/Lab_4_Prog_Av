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
    std::cout << "\e[0;35mVideojuego con partidas finalizadas: \n\e[0m";
    while (it->hasCurrent())
    {
        Videojuego *aux = dynamic_cast<Videojuego *>(it->getCurrent());
        bool tiene = aux->tienepartidas();
        
        if (tiene == false)
            std::cout << "\e[0;35m" << aux->GetNombreVidJ() << "\n\e[0m";

        it->next();
    }
    delete it;
}

Videojuego *Desarrollador::obtenerVideojuegodesarrollador(std::string _videojuego)
{
    IKey *key = new StringKey(_videojuego);
    Videojuego *aux = dynamic_cast<Videojuego *>(videojuegosdesarrollador->find(key));
    return aux;
}

void Desarrollador::setVideoJuego(Videojuego *vj, IKey *id)
{
    this->videojuegosdesarrollador->add(id, vj);
}

void Desarrollador::EliminarEsteJuego(Videojuego *v)
{
    v->eliminarme();
    StringKey *keyVidj = new StringKey(v->GetNombreVidJ());
    videojuegosdesarrollador->remove(keyVidj);
    v->Borrame();
}

Desarrollador::~Desarrollador() {}

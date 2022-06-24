#include "../headers/Desarrollador.h"

Desarrollador::Desarrollador() {}

Desarrollador::Desarrollador(std::string _email, std::string _contrasenia, std::string _empresa) : Usuario (_email, _contrasenia)
{
    this->empresa = _empresa;
    this->videojuegosdesarrollador = new OrderedDictionary;

}
void Desarrollador::mostrarVideojuegosDesarrollador(){
    IIterator* it= this->videojuegosdesarrollador->getIterator();
    while(it->hasCurrent()){
        Videojuego* aux= dynamic_cast<Videojuego*>(it->getCurrent());
        std::cout << aux->Getnombre();
        it->next();
    }
}
void Desarrollador::EliminarEsteJuego(Videojuego *v){
   v->eliminarme();
   StringKey *key = new StringKey(v->Getnombre());
   videojuegosdesarrollador->remove(key);
    v->Borrame();

}

Desarrollador::~Desarrollador() {}

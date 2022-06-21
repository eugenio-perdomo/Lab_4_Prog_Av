#include "./../headers/Jugador.h"

Jugador::Jugador()
{
    this->suscripcion = new OrderedDictionary();
    this->partidas = new List();
}

Jugador::Jugador(std::string _email, std::string _contrasenia, std::string _nick, std::string _desc) : Usuario (_email, _contrasenia)
{
    this->nick = _nick;
    this->descripcion = _desc;
    this->suscripcion = new OrderedDictionary();
    this->partidas = new List();
}


Jugador::~Jugador() {}

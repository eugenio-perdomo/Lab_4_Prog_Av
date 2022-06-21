#include "./../headers/Desarrollador.h"

Desarrollador::Desarrollador() {}

Desarrollador::Desarrollador(std::string _email, std::string _contrasenia, std::string _empresa) : Usuario (_email, _contrasenia)
{
    this->empresa = _empresa;
    // TODO El order Dictionary para Videojuegos
}

Desarrollador::~Desarrollador() {}

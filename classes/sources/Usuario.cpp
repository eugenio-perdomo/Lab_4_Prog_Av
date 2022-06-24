#include "../headers/Usuario.h"

Usuario::Usuario() {}
Usuario::Usuario(std::string _email, std::string _contrasenia)
{
	this->email = _email;
	this->contrasenia = _contrasenia;
}
Usuario::~Usuario() {}

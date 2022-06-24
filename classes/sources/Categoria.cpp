#include "../headers/Categoria.h"

Categoria::Categoria() {}

Categoria::Categoria(std::string _nombre, std::string _descripcion, std::string _tipo)
{
    this->nombre = _nombre;
    this->descripcion = _descripcion;
    this->tipo = _tipo;
}

Categoria::~Categoria() {}
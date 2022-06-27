#include "../headers/Comentario.h"

Comentario::Comentario() {}

Comentario::Comentario(std::string id, std::string texto, std::string nickUsuarioComentario, DtFecha *fechaEnvio)
{
    this->id = id;
    this->texto = texto;
    this->nickUsuarioComentario = nickUsuarioComentario;
    this->fechaEnvio = fechaEnvio;
}

std::string Comentario::getId()
{
    return this->id;
}
std::string Comentario::getTexto()
{
    return this->texto;
}
std::string Comentario::getNickUsuarioComentario()
{
    return this->nickUsuarioComentario;
}
DtFecha Comentario::getFechaEnvio()
{
    return *fechaEnvio;
}

void Comentario::setId(std::string id)
{
    this->id = id;
}
void Comentario::setTexto(std::string texto)
{
    this->texto = texto;
}
void Comentario::setNickUsuarioComentario(std::string nickUsuarioComentario)
{
    this->nickUsuarioComentario = nickUsuarioComentario;
}
void Comentario::setFechaEnvio(DtFecha *fechaEnvio)
{
    this->fechaEnvio = fechaEnvio;
}
void Comentario::Eliminarme()
{
    delete (this);
}
Comentario::~Comentario() {}

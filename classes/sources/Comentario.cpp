#include "./../headers/Comentario.h"

Comentario::Comentario() {}

Comentario::Comentario(std::string id,
                       std::string texto,
                       std::string nickUsuarioComentario,
                       DtFecha fechaEnvio)
{
    this->id = id;
    this->texto = texto;
    this->nickUsuarioComentario = nickUsuarioComentario;
    this->fechaEnvio = fechaEnvio;
}

Comentario::std::string getId()
{
    return this->id;
}
Comentario::std::string getTexto()
{
    return this->texto;
}
Comentario::std::string getNickUsuarioComentario()
{
    return this->nickUsuarioComentario;
}
Comentario::DtFecha getFechaEnvio()
{
    return this->fechaEnvio;
}

Comentario::void setId(std::string id)
{
    this->id = id;
}
Comentario::void setTexto(std::string texto)
{
    this->texto = texto;
}
Comentario::void setNickUsuarioComentario(std::string nickUsuarioComentario)
{
    this->nickUsuarioComentario = nickUsuarioComentario;
}
Comentario::void setFechaEnvio(DtFecha fechaEnvio)
{
    this->fechaEnvio = fechaEnvio;
}

Comentario::~Comentario() {}

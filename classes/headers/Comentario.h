#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include "DtFecha.h"

class Comentario
{
private:
	std::string id;
	std::string texto;
	std::string nickUsuarioComentario;
	DtFecha fechaEnvio;

public:
	Comentario();
	Comentario(std::string id,
			   std::string texto,
			   std::string nickUsuarioComentario,
			   DtFecha fechaEnvio);

	std::string getId();
	std::string getTexto();
	std::string getNickUsuarioComentario();
	DtFecha getFechaEnvio();

	void setId(std::string id);
	void setTexto(std::string texto);
	void setNickUsuarioComentario(std::string nickUsuarioComentario);
	void setFechaEnvio(DtFecha fechaEnvio);

	virtual ~Comentario();
};

#endif /* Comentario_H */

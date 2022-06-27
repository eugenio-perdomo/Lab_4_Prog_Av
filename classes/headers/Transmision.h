#ifndef TRANSMISION_H
#define TRANSMISION_H

#include "Comentario.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../datatypes/headers/DtFecha.h"

class Transmision
{
private:
	DtFecha *fechaInicio;
	ICollection *comentarios;

public:
	Transmision();
	Transmision(DtFecha *fechaInicio);

	DtFecha getFechaInicio();
	void setFechaInicio(DtFecha *fechaInicio);
	// void setComentario(Comentario *c);

	virtual ~Transmision();
};

#endif /* Transmision_H */

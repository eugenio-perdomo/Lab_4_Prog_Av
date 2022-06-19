#ifndef TRANSMISION_H
#define TRANSMISION_H

#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../datatypes/headers/DtFecha.h"

class Transmision
{
private:
	DtFecha fechaInicio;
	ICollection *comentario;

public:
	Transmision();
	Transmision(DtFecha fechaInicio);

	DtFecha getFechaInicio();
	void setFechaInicio(DtFecha fechaInicio);

	virtual ~Transmision();
};

#endif /* Transmision_H */

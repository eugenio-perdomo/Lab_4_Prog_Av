#ifndef TRANSMISION_H
#define TRANSMISION_H

#include "DtFecha.h"

class Transmision
{
private:
	DtFecha fechaInicio;

public:
	Transmision();
	Transmision(DtFecha fechaInicio);


	DtFecha getFechaInicio();
	void setFechaInicio(DtFecha fechaInicio);

	virtual ~Transmision();
};

#endif /* Transmision_H */

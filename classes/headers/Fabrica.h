#ifndef FABRICA_H
#define FABRICA_H
#include "./ISistema.h"
#include "./Sistema.h"
// class ISistema;

class Fabrica
{
private:
public:
	ISistema *getSistema()
	{
		return new Sistema();
	}
};

#endif /* FABRICA_H */

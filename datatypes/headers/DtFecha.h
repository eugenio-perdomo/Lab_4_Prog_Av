#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>
#include "./../../ICollection/interfaces/ICollectible.h"

class DtFecha : public ICollectible
{
private:
    int segundo;
    int minuto;
    int hora;
    int dia;
    int mes;
    int anio;
    bool isValid();

public:
    DtFecha();
    DtFecha(int dia, int mes, int anio,int segundo,int minuto,int hora);
    int getSegundo();
    int getMinuto();
    int getHora();
    int getDia();
    int getMes();
    int getAnio();
    bool operator==(const DtFecha &df) const;
    bool operator<(const DtFecha &df) const;
    virtual ~DtFecha();
};

#endif

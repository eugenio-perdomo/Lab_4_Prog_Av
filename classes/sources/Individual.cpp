#include "./../headers/Individual.h"

Individual::Individual() {}

Individual::Individual(bool esContinuacion,
                       std::string nickJugador)
{
    this->esContinuacion = esContinuacion;
    this->nickJugador = nickJugador;
}

Individual::bool getEsContinuacion()
{
    return this->esContinuacion;
}
Individual::std::string getNickJugador()
{
    return this->nickJugador;
}

Individual::void setEsContinuacion()
{
    this->esContinuacion = esContinuacion;
}
Individual::void setNickJugador()
{
    this->nickJugador = nickJugador;
}

Individual::~Individual() {}

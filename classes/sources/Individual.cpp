#include "./../headers/Individual.h"

Individual::Individual() {}

Individual::Individual(bool esContinuacion, std::string nickJugador)
{
    this->esContinuacion = esContinuacion;
    this->nickJugador = nickJugador;
}

bool Individual::getEsContinuacion()
{
    return this->esContinuacion;
}
std::string Individual::getNickJugador()
{
    return this->nickJugador;
}

void Individual::setEsContinuacion(bool esContinuacion)
{
    this->esContinuacion = esContinuacion;
}
void Individual::setNickJugador(std::string nickJugador)
{
    this->nickJugador = nickJugador;
}

Individual::~Individual() {}

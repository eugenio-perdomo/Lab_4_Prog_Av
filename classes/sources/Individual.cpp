#include "../headers/Individual.h"

Individual::Individual() {}

Individual::Individual(bool esContinuacion,std::string nickJugador,std::string _id,std::string _nombreVideojuego,bool _finalizado,float _duracionPartida,DtFecha *_fechaInicio,DtFecha *_fechaFin)
{
    this->esContinuacion=esContinuacion;
    this->nickJugador=nickJugador;
    this->id=_id;
    this->nombreVideojuego=_nombreVideojuego;
    this->finalizado=_finalizado;
    this->duracionPartida=_duracionPartida;
    this->fechaFin=_fechaFin;
    this->fechaInicio=_fechaInicio;
    this->esContinuacion = esContinuacion;
    this->nickJugador = nickJugador;
}

Individual::Individual(bool esContinuacion,std::string nickJugador,std::string _id,std::string _nombreVideojuego,bool _finalizado,float _duracionPartida,DtFecha *_fechaInicio)
{
    this->esContinuacion=esContinuacion;
    this->nickJugador=nickJugador;
    this->id=_id;
    this->nombreVideojuego=_nombreVideojuego;
    this->finalizado=_finalizado;
    this->duracionPartida=_duracionPartida;
    this->fechaInicio=_fechaInicio;
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

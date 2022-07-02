#include "../headers/DtFecha.h"
DtFecha::DtFecha() {}

DtFecha::DtFecha(int dia, int mes, int anio,int segundo,int minuto,int hora)
{
	this->segundo = segundo;
	this->minuto = minuto;
	this->hora = hora;
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

// ------- Getters ------ //
int DtFecha::getSegundo()
{
	return this->segundo;
}
int DtFecha::getMinuto()
{
	return this->minuto;
}
int DtFecha::getHora()
{
	return this->hora;
}

int DtFecha::getDia()
{
	return this->dia;
}

int DtFecha::getMes()
{
	return this->mes;
}

int DtFecha::getAnio()
{
	return this->anio;
}


void DtFecha::setSegundo(int v){
	this->segundo=v;
}

void DtFecha::setMinuto(int v){
	this->minuto=v;
}

void DtFecha::setHora(int v){
	this->hora=v;
}

void DtFecha::setDia(int v){
	this->dia=v;
}

void DtFecha::setMes(int v){
	this->mes=v;
}

void DtFecha::setAnio(int v){
	this->anio=v;
}












bool DtFecha::operator==(const DtFecha &dtfecha) const
{
	int suma_fecha1 = this->anio + this->mes * 100 + this->dia;
	int suma_fecha2 = dtfecha.anio + dtfecha.mes * 100 + dtfecha.dia;
	return (suma_fecha1 == suma_fecha2);
}

bool DtFecha::operator<(const DtFecha &dtfecha) const
{
	int suma_fecha1 = this->anio + this->mes * 100 + this->dia;
	int suma_fecha2 = dtfecha.anio + dtfecha.mes * 100 + dtfecha.dia;
	return (suma_fecha1 < suma_fecha2);
}

DtFecha::~DtFecha()
{
}

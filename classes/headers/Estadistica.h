#ifndef ESTADISTICA_H
#define ESTADISTICA_H

class Estadistica
{
private:
	int puntaje;
	float duracionTotalPorJugador;

public:
	Estadistica();

	int Getpuntaje() { return puntaje; }
	void Setpuntaje(int val) { puntaje = val; }
	float GetduracionTotalPorJugador() { return duracionTotalPorJugador; }
	void SetduracionTotalPorJugador(float val) { duracionTotalPorJugador = val; }

	virtual ~Estadistica();
};

#endif /* Estadistica_H */

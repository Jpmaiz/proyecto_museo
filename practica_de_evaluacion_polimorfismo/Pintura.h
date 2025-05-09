#pragma once
#include "ObraDeArte.h"

class Pintura : public ObraDeArte
{
private:
	string tecnica;
	double alto;
	double ancho;

public:
	Pintura(int id, const string& titulo, const string& artista, int anio,
		const string& tecnica, double alto, double ancho);

	double calcularValorEstimado() const override;
	string toJson() const override;


};


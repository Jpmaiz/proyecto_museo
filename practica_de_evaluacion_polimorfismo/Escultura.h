#pragma once
#include "ObraDeArte.h"

class Escultura : public ObraDeArte
{
private:
	string material;
	double peso;

public:
    Escultura(int id, const string& titulo, const string& artista, int anio,
        const string& material, double peso);

    double calcularValorEstimado() const override;
    string toJson() const override;
};


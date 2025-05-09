#pragma once
#include "ObraDeArte.h"

class Fotografia : public ObraDeArte {
private:
    bool esColor;
    string resolucion;

public:
    Fotografia(int id, const string& titulo, const string& artista, int anio,
        bool esColor, const string& resolucion);

    double calcularValorEstimado() const override;
    string toJson() const override;
};

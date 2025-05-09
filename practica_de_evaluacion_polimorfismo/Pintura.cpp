#include "Pintura.h"

Pintura::Pintura(int id, const string& titulo, const string& artista, int anio,
    const string& tecnica, double alto, double ancho)
    : ObraDeArte(id, titulo, artista, anio), tecnica(tecnica), alto(alto), ancho(ancho) {
}

double Pintura::calcularValorEstimado() const {
    double valorBase = 1000.0;
    double area = alto * ancho;
    double factor = 1.0;

    if (tecnica == "oleo") factor = 1.5;
    else if (tecnica == "acrilico") factor = 1.2;
    else if (tecnica == "acuarela") factor = 1.1;

    return valorBase + (area * (valorBase * (factor - 1)));
}

string Pintura::toJson() const
{
	stringstream ss;
    ss << "{"
        << "\"tipo\":\"Pintura\","
        << "\"id\":" << idObra << ","
        << "\"titulo\":\"" << titulo << "\","
        << "\"artista\":\"" << artista << "\","
        << "\"anio\":" << anioCreacion << ","
        << "\"tecnica\":\"" << tecnica << "\","
        << "\"alto\":" << alto << ","
        << "\"ancho\":" << ancho
        << "}";
    return ss.str();
}

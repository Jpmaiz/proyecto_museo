#include "Escultura.h"

Escultura::Escultura(int id, const string& titulo, const string& artista, int anio,
    const string& material, double peso)
    : ObraDeArte(id, titulo, artista, anio), material(material), peso(peso) {
}

double Escultura::calcularValorEstimado() const {
    double valorBase = 2000.0;
    double factor = 1.0;

    if (material == "marmol") factor = 2.0;
    else if (material == "bronce") factor = 1.5;
    else if (material == "madera") factor = 1.2;

    return valorBase + (peso * (valorBase * (factor - 1)));
}

string Escultura::toJson() const {
    stringstream ss;
    ss << "{"
        << "\"tipo\":\"Escultura\","
        << "\"id\":" << idObra << ","
        << "\"titulo\":\"" << titulo << "\","
        << "\"artista\":\"" << artista << "\","
        << "\"anio\":" << anioCreacion << ","
        << "\"material\":\"" << material << "\","
		<< "\"peso\":" << peso << ","
        << fixed << setprecision(2)
		<< "\"valorEstimado\":" << calcularValorEstimado()
        << "}";
    return ss.str();
}
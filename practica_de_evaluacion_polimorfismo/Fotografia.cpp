#include "Fotografia.h"
#include <sstream>

Fotografia::Fotografia(int id, const string& titulo, const string& artista, int anio,
    bool esColor, const string& resolucion)
    : ObraDeArte(id, titulo, artista, anio), esColor(esColor), resolucion(resolucion) {
}

double Fotografia::calcularValorEstimado() const {
    double valorBase = 500.0;
    return esColor ? valorBase * 1.3 : valorBase;
}

string Fotografia::toJson() const {
    stringstream ss;
    ss << "{"
        << "\"tipo\":\"Fotografia\","
        << "\"id\":" << idObra << ","
        << "\"titulo\":\"" << titulo << "\","
        << "\"artista\":\"" << artista << "\","
        << "\"anio\":" << anioCreacion << ","
        << "\"esColor\":" << (esColor ? "true" : "false") << ","
        << "\"resolucion\":\"" << resolucion << "\""
        << "}";
    return ss.str();
}

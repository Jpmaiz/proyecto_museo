#include "ObraDeArte.h"

ObraDeArte::ObraDeArte(int idObra, const string& titulo, const string& artista, int anioCreacion)
    : idObra(idObra), titulo(titulo), artista(artista), anioCreacion(anioCreacion) {
}

int ObraDeArte::getIdObra() const {
    return idObra;
}

string ObraDeArte::getTitulo() const {
    return titulo;
}

string ObraDeArte::getArtista() const {
    return artista;
}

int ObraDeArte::getAnioCreacion() const {
    return anioCreacion;
}

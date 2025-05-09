#pragma once
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class ObraDeArte {
protected:
    int idObra;
    string titulo;
    string artista;
    int anioCreacion;

public:
    ObraDeArte(int idObra, const string& titulo, const string& artista, int anioCreacion);


    int getIdObra() const;
    string getTitulo() const;
    string getArtista() const;
    int getAnioCreacion() const;


    virtual double calcularValorEstimado() const = 0;
    virtual string toJson() const = 0;


    virtual ~ObraDeArte() {}
};
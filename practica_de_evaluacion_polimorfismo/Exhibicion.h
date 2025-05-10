#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "ObraDeArte.h"
#include "Guia.h"

class Guia;

class Exhibicion
{
private:
	string nombre;
	ObraDeArte** obras;
	int tamMax;
	int ind;
	Guia* guia;

public:
	Exhibicion(const string& nombre);
	~Exhibicion();

	void agregarObra(ObraDeArte* obra);
	void asignarGuia(Guia* guia);

	double calcularValorTotal() const;

	Guia* getGuia() const;
	ObraDeArte** getObras() const;
	string getNombre() const;

	string toJson() const;
};


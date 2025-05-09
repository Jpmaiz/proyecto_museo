#pragma once
#include "ModuloObraDeArte.h"
class Museo
{
private:
	string nombre;
	ModuloObraDeArte moduloObras;

public:
	Museo(const string& nombre);

	void agregarObra(ObraDeArte* obra);


};


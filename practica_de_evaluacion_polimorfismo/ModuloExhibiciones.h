#pragma once
#include "Exhibicion.h"

class ModuloExhibiciones
{
private:
	Exhibicion** exhibiciones;
	int tamMax;
	int ind;

public:
	ModuloExhibiciones(int tamMax);
	~ModuloExhibiciones();

	void agregarExhibicion(Exhibicion* exhibicion);
	Exhibicion* buscarPorNombre(const string& nombre) const;

	string toJson() const;
};


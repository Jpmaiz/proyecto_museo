#pragma once
#include "Guia.h"

class ModuloGuia
{
private:
	Guia** guias;
	int tamMax;
	int ind;

public:
	ModuloGuia(int tamMax);
	~ModuloGuia();

	void agregarGuia(Guia* guia);
	Guia* buscarGuia(const string& nombre) const;
	Guia* buscarPorId(int id) const;


	string toJson() const;
};


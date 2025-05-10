#include "ModuloGuia.h"

ModuloGuia::ModuloGuia(int tamMax)
{
	this->tamMax = tamMax;
	this->ind = 0;
	guias = new Guia * [tamMax];
}

ModuloGuia::~ModuloGuia()
{
}

void ModuloGuia::agregarGuia(Guia* guia)
{
	if (ind < tamMax)
	{
		guias[ind] = guia;
		ind++;
	}
	else
	{
		cout << "No se puede agregar mas guias" << endl;
	}
}

Guia* ModuloGuia::buscarGuia(const string& nombre) const
{
	for (int i = 0; i < ind; i++)
	{
		if (guias[i]->getNombre() == nombre)
		{
			return guias[i];
		}
	}
	cout << "No se encontro la guia" << endl;
	return nullptr;
}

Guia* ModuloGuia::buscarPorId(int id) const
{
	for (int i = 0; i < ind; i++)
	{
		if (guias[i]->getId() == id)
		{
			return guias[i];
		}
	}
	cout << "No se encontro la guia" << endl;
	return nullptr;
}

string ModuloGuia::toJson() const
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++) {
		ss << guias[i]->toJson();
		if (i < ind - 1) {
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

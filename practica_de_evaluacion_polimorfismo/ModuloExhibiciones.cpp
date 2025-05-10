#include "ModuloExhibiciones.h"

ModuloExhibiciones::ModuloExhibiciones(int tamMax)
{
	this->tamMax = tamMax;
	ind = 0;
	exhibiciones = new Exhibicion * [tamMax];

}

ModuloExhibiciones::~ModuloExhibiciones()
{
	for (int i = 0; i < ind; i++) {
		delete exhibiciones[i];
	}
	delete[] exhibiciones;
	exhibiciones = nullptr;
	tamMax = 0;
	ind = 0;
}

void ModuloExhibiciones::agregarExhibicion(Exhibicion* exhibicion)
{
	if (ind < tamMax)
	{
		exhibiciones[ind] = exhibicion;
		ind++;
	}
	else
	{
		cout << "No se puede agregar mas exhibiciones" << endl;
	}
}


Exhibicion* ModuloExhibiciones::buscarPorNombre(const string& nombre) const
{
	for (int i = 0; i < ind; i++)
	{
		if (exhibiciones[i]->getNombre() == nombre)
		{
			return exhibiciones[i];
		}
	}
	cout << "No se encontro la exhibicion" << endl;
	return nullptr;

	
}

string ModuloExhibiciones::toJson() const
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++) {
		ss << exhibiciones[i]->toJson();
		if (i < ind - 1) {
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

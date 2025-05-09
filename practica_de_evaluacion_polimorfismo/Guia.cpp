#include "Guia.h"

Guia::Guia(const string& nombre, int id)
{
	this->nombre = nombre;
	this->id = id;
	this->tamMax = 100;
	this->ind = 0;
	exhibiciones = new Exhibicion * [tamMax];
}

Guia::~Guia()
{
}

void Guia::asignarAExhibicion(Exhibicion* exhibicion)
{
	if (ind < tamMax) {
		exhibiciones[ind] = exhibicion;
		ind++;
	}
	else {
		cout << "No se puede agregar más exhibiciones. Capacidad máxima alcanzada." << endl;
	}
}

int Guia::getId() const
{
	return id;
}

string Guia::getNombre() const
{
	return nombre;
}

string Guia::toJson() const
{
	stringstream ss;
	ss << "{";
	ss << "\"id\":" << id << ",";
	ss << "\"nombre\":\"" << nombre << "\",";
	ss << "\"exhibiciones\":[";

	for (int i = 0; i < ind; i++) {
		ss << "\"" << exhibiciones[i]->getNombre() << "\"";
		if (i < ind - 1) ss << ",";
	}

	ss << "]";
	ss << "}";

	return ss.str();
}

#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "Exhibicion.h"

using namespace std;


class Exhibicion; 

class Guia
{
private:
	string nombre;
	int id;
	Exhibicion** exhibiciones;
	int tamMax;
	int ind;

public:
	Guia(const string& nombre, int id);
	~Guia();


	void asignarAExhibicion(Exhibicion* exhibicion);

	int getId() const;
	string getNombre() const;

	string toJson() const;
};


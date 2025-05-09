#pragma once
#include "ObraDeArte.h"

using namespace std;

class ModuloObraDeArte
{
private: 
	ObraDeArte** obras;
	int tamMax;
	int ind;

public:
	ModuloObraDeArte(int tamMax);
	~ModuloObraDeArte();

	void agregarObra(ObraDeArte* obra);
	void mostrarObrasDeArtista(const string& artista) const;

	
	ObraDeArte* buscarPorId(int id) const;

	string toJson() const;

};
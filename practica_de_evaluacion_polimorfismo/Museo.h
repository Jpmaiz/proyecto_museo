#pragma once
#include "ModuloObraDeArte.h"
#include "ModuloGuia.h"
#include "ModuloExhibiciones.h"


class Museo
{
private:
	string nombre;
	ModuloObraDeArte moduloObras;
	ModuloGuia moduloGuias;
	ModuloExhibiciones moduloExhibiciones;

public:
	Museo(const string& nombre);

	ModuloObraDeArte& getObrasDeArte();
	ModuloGuia& getGuias();
	ModuloExhibiciones& getExhibiciones();

	void agregarObra(ObraDeArte* obra);
	void agregarGuia(Guia* guia);
	void agregarExhibicion(Exhibicion* exhibicion);

	ObraDeArte* buscarObraPorId(int id) const;
	Guia* buscarGuiaPorId(int id) const;
	Exhibicion* buscarExhibicionPorNombre(const string& nombre) const;


	string obrasToJson() const;
	string guiasToJson() const;
	string exhibicionesToJson() const;
	
	string toJson() const;

};


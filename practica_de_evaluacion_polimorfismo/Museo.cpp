#include "Museo.h"

Museo::Museo(const string& nombre) : moduloObras(100), moduloGuias(20), moduloExhibiciones(50)
{
	this->nombre = nombre;
}

ModuloObraDeArte& Museo::getObrasDeArte()
{
	return moduloObras;
}

ModuloGuia& Museo::getGuias()
{
	return moduloGuias;
}

ModuloExhibiciones& Museo::getExhibiciones()
{
	return moduloExhibiciones;
}


void Museo::agregarObra(ObraDeArte* obra)
{
	moduloObras.agregarObra(obra);
}

void Museo::agregarGuia(Guia* guia)
{
	moduloGuias.agregarGuia(guia);
}

void Museo::agregarExhibicion(Exhibicion* exhibicion)
{
	moduloExhibiciones.agregarExhibicion(exhibicion);
}

ObraDeArte* Museo::buscarObraPorId(int id) const
{
	return moduloObras.buscarPorId(id);
}

Guia* Museo::buscarGuiaPorId(int id) const
{
	return moduloGuias.buscarPorId(id);
}

Exhibicion* Museo::buscarExhibicionPorNombre(const string& nombre) const
{
	return moduloExhibiciones.buscarPorNombre(nombre);
}

string Museo::obrasToJson() const
{
	return moduloObras.toJson();
}

string Museo::guiasToJson() const
{
	return moduloGuias.toJson();	
}

string Museo::exhibicionesToJson() const
{
	return moduloExhibiciones.toJson();
}

string Museo::toJson() const
{
	stringstream ss;
	ss << "{";
	ss << "\"nombre\":\"" << nombre << "\",";
	ss << "\"obras\":" << moduloObras.toJson() << ",";
	ss << "\"guias\":" << moduloGuias.toJson() << ",";
	ss << "\"exhibiciones\":" << moduloExhibiciones.toJson();
	ss << "}";
	return ss.str();
}

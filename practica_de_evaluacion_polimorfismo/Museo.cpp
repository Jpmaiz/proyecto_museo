#include "Museo.h"

Museo::Museo(const string& nombre) : moduloObras(100)
{
	this->nombre = nombre;
}

void Museo::agregarObra(ObraDeArte* obra)
{
	moduloObras.agregarObra(obra);
}

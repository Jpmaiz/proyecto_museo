#include "Exhibicion.h"

Exhibicion::Exhibicion(const string& nombre)
{
	this->nombre = nombre;
	this->tamMax = 100; 
	this->ind = 0; 
	this->guia = nullptr; 
	obras = new ObraDeArte * [tamMax]; 
}

Exhibicion::~Exhibicion()
{
}

void Exhibicion::agregarObra(ObraDeArte* obra)
{
	if (ind < tamMax) {
		obras[ind] = obra;
		ind++;
	}
	else {
		cout << "No se puede agregar más obras. Capacidad máxima alcanzada." << endl;
	}
}

void Exhibicion::asignarGuia(Guia* guia)
{
	this->guia = guia;
	guia->asignarAExhibicion(this);
}

Guia* Exhibicion::getGuia() const
{
    return guia;
}

ObraDeArte** Exhibicion::getObras() const
{
    return obras;
}

string Exhibicion::getNombre() const
{
    return nombre;
}

string Exhibicion::toJson() const
{
    stringstream ss;
    ss << "{";
    ss << "\"nombre\":\"" << nombre << "\",";

    if (guia != nullptr) {
        ss << "\"guia\":" << guia->toJson() << ",";
    }
    else {
        ss << "\"guia\":null,";
    }

    
    ss << "\"obras\":[";
    for (int i = 0; i < ind; i++) {
        ss << obras[i]->toJson();
        if (i < ind - 1) ss << ",";
    }
    ss << "]";
    ss << "}";

    return ss.str();
}

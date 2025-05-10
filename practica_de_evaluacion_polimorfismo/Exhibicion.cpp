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

double Exhibicion::calcularValorTotal() const
{
    double total = 0.0;
    for (int i = 0; i < ind; i++) {
        total += obras[i]->calcularValorEstimado();
    }
    return total;
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

    // Obras
    ss << "\"obras\":[";
    double total = 0.0;
    for (int i = 0; i < ind; i++) {
        ss << obras[i]->toJson();
        if (i < ind - 1) ss << ",";
        total += obras[i]->calcularValorEstimado(); // acumulando valor
    }
    ss << "],";

    // Valor total
    ss << fixed << setprecision(2); // evita notación científica
    ss << "\"valor_total\":" << total;

    ss << "}";

    return ss.str();
}

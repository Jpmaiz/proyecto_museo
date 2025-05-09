#include "ModuloObraDeArte.h"

ModuloObraDeArte::ModuloObraDeArte(int tamMax)
{
    this->tamMax = tamMax;
    ind = 0;
    obras = new ObraDeArte * [tamMax];
}

ModuloObraDeArte::~ModuloObraDeArte()
{
    for (int i = 0; i < ind; i++) {
        delete obras[i];  
    }
    delete[] obras;
}

void ModuloObraDeArte::agregarObra(ObraDeArte* obra)
{
	if (ind < tamMax) {
		obras[ind] = obra;
		ind++;
	}
	else {
		cout << "No se puede agregar m�s obras. Capacidad m�xima alcanzada." << endl;
	}
}

void ModuloObraDeArte::mostrarObrasDeArtista(const string& artista) const
{
    bool encontrado = false;
    for (int i = 0; i < ind; i++) {
        if (obras[i]->getArtista() == artista) {
            cout << obras[i]->toJson() << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron obras del artista \"" << artista << "\"." << endl;
    }

}





ObraDeArte* ModuloObraDeArte::buscarPorId(int id) const {
    for (int i = 0; i < ind; i++) {
        if (obras[i]->getIdObra() == id) {
            return obras[i];
        }
    }
    return nullptr; 
}

string ModuloObraDeArte::toJson() const
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++) {
		ss << obras[i]->toJson();
		if (i < ind - 1) {
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

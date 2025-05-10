#include <iostream>
#include "Museo.h"
#include "Pintura.h"
#include "Escultura.h"
#include "Fotografia.h"
#include "Guia.h"
#include "Exhibicion.h"

using namespace std;

int main()
{
 
    Museo museo("Museo Nacional de Arte");

    
    museo.agregarObra(new Pintura(1, "La noche estrellada", "Van Gogh", 1889, "oleo", 73, 92));
    museo.agregarObra(new Pintura(2, "Mujer con sombrero", "Henri Matisse", 1905, "acrilico", 81, 60));
    museo.agregarObra(new Escultura(3, "David", "Miguel Angel", 1504, "marmol", 6000));
    museo.agregarObra(new Escultura(4, "El pensador", "Rodin", 1902, "bronce", 635));
    museo.agregarObra(new Fotografia(5, "Moonrise", "Ansel Adams", 1941, false, "2048x1536"));

    Guia* guia1 = new Guia("Maria Lopez", 101);
    Guia* guia2 = new Guia("Juan Perez", 102);
    museo.agregarGuia(guia1);
    museo.agregarGuia(guia2);

    Exhibicion* expo1 = new Exhibicion("Obras clasicas");
    Exhibicion* expo2 = new Exhibicion("Expresionismo y fotografia");

    expo1->asignarGuia(guia1);
    expo2->asignarGuia(guia2);

    expo1->agregarObra(museo.buscarObraPorId(1)); 
    expo1->agregarObra(museo.buscarObraPorId(3)); 

    expo2->agregarObra(museo.buscarObraPorId(2)); 
    expo2->agregarObra(museo.buscarObraPorId(4)); 
    expo2->agregarObra(museo.buscarObraPorId(5)); 

    museo.agregarExhibicion(expo1);
    museo.agregarExhibicion(expo2);

    cout << museo.toJson() << endl;

    return 0;

}
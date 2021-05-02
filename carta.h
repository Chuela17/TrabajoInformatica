#ifndef CARTA_H
#define CARTA_H
#include <string>

using namespace std;

class Carta {
private:
    int numcarta;
    string palocarta;
    string direccioncarta;

public:
    Carta(int, string, string); // Constructor
    ~Carta(); // Destructor
    int GetNumcarta(); // Obtener el número de la carta
    string GetPalocarta(); // Obtener el palo de la carta
    string GetDireccioncarta(); // Obtener el path de la imagen de la carta
};

#endif // CARTA_H

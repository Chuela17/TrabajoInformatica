#ifndef INFORMACION_H
#define INFORMACION_H
#include "jugador.h"

class Informacion {
private:
    int numerojugador;
public:
    Informacion(int); // Constructor
    ~Informacion(); // Destructor
    string ObtenerInformacion1(Jugador *); // Obtener la información del jugador 1
    string ObtenerInformacion2(Jugador *); // Obtener la información del jugador 2
};

#endif // INFORMACION_H

#ifndef JUGADOR_H
#define JUGADOR_H
#include "montoncentro.h"
#include <string>

using namespace std;

class Jugador {
private:
    Monton monton_novisible;
    Monton monton_visible;
    string nombre;
public:
    Jugador(); // Constructor vacío
    Jugador(Monton, Monton, string); // Constructor
    ~Jugador(); // Destructor
    Carta CogerCarta(); // Llamar a coger carta en los montones
    bool ComprobarDejarCarta(Carta); // Comprobación de si se puede dejar una carta en un montón
    void DejarCarta(Carta, Monton *); // Llamar a dejar carta en los montones
    void DejarCarta(Carta, MontonCentro *); // Llamar a dejar carta en los montones de tipo MontonCentro
    Monton *GetMontonNoVisible(); // Obtener el montón no visible del jugador
    Monton *GetMontonVisible(); // Obtener el montón visible del jugador
    bool SinCartas(); //Comprobar si los dos mazos del jugador están vacíos
};

#endif // JUGADOR_H

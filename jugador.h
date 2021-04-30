#ifndef JUGADOR_H
#define JUGADOR_H
#include "monton.h"
#include <string>

using namespace std;

class Jugador {
private:
    Monton *monton_novisible;
    Monton *monton_visible;
    string nombre;
public:
    Jugador(Monton *, Monton *, string);
    Carta CogerCarta(); //llamar a coger carta en los montones
    void DejarCarta(Carta, Monton *); //llamar a dejar carta en los montones. Llamar con el getter
    Monton *GetMontonNoVisible();
    Monton *GetMontonVisible();
    bool SinCartas(); //Comprobar si los dos mazos del jugador están vacíos
};

#endif // JUGADOR_H

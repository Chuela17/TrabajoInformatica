#ifndef MONTON_H
#define MONTON_H
#include <stack>
#include "carta.h"

using namespace std;

class Monton {
private:
    stack<Carta> cartas;

public:
    Monton(stack<Carta>); //Constructor
    bool EstaVacio(); //Comprobar si hay cartas en el montón
    Carta CogerCarta(); //Coger una nueva carta de los mazos de los jugadores
    Carta ConsultarCarta(); //Miramos la carta del montón, sin sacarla
    void DejarCarta(Carta);//Deja carta (Polimorfismo, se va a usar con un stack en la siguiente)
    void DejarCarta(Monton); //Rellenar mazo
};

#endif // MONTON_H

#ifndef MONTON_H
#define MONTON_H
#include <stack>
#include "carta.h"

using namespace std;

class Monton {
private:
    stack<Carta> cartas;
    bool visible = true;

public:
    Monton();
    Monton(stack<Carta>); //Constructor
    bool EstaVacio(); //Comprobar si hay cartas en el montón
    bool GetVisible();
    void SetVisible(bool); // Cuando defina un monton no visible hay que usar el setter
    Carta CogerCarta(); //Coger una nueva carta de los mazos de los jugadores
    Carta ConsultarCarta(); //Miramos la carta del montón, sin sacarla
    void DejarCarta(Carta);//Deja carta (Polimorfismo, se va a usar con un stack en la siguiente)
    void DejarCarta(Monton); //Rellenar mazo
    void SetMonton(stack<Carta> cartas); //Inicializar el stack de cartas
};

#endif // MONTON_H

#ifndef MONTON_H
#define MONTON_H
#include <stack>
#include "carta.h"

using namespace std;

class Monton {
private:
    stack<Carta> cartas;
    bool visible = true;
    int identificador;

public:
    Monton(); // Constructor vacío
    Monton(stack<Carta>, int); // Constructor
    ~Monton(); // Destructor
    bool EstaVacio(); // Comprobar si hay cartas en el montón
    bool GetVisible(); // Obtener si el montón es de tipo visible o no
    void SetVisible(bool); // Definir el valor del atributo visible del motón
    Carta CogerCarta(); // Coger una nueva carta del montón
    Carta ConsultarCarta(); // Obtener la información de la carta que se encuentra en la parte superior
                            // de la pila del montón
    void DejarCarta(Carta); // Dejar una única carta en un montón
    void DejarCarta(Monton *); // Dejar un montón sobre otro, para pasar las cartas visibles a no visibles
                               //cuando sea necesario
    void SetMonton(stack<Carta>); // Inicializar el stack de cartas
    int GetIdentificador(); // Obtener el identificador del montón
    stack<Carta> GetStackCartas(); // Obtener la pila de cartas del montón
};

#endif // MONTON_H

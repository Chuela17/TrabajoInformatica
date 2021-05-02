#ifndef MONTONCENTRO_H
#define MONTONCENTRO_H
#include "montoncrece.h"

class MontonCentro: public MontonCrece {
private:
    string palo;
    bool ComprobarDejarCartaVacio(Carta);
    bool ComprobarDejarCartaSuperior(Carta);
public:
    MontonCentro(); // Constructor vacío
    MontonCentro(stack<Carta>, int, string); // Constructor
    ~MontonCentro(); // Destructor
    bool ComprobarDejarCarta(Carta); // Determinar si se puede colocar la carta sobre el montón o no
    void DejarCarta(Carta); // Dejar la carta sobre el montón
};

#endif // MONTONCENTRO_H

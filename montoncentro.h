#ifndef MONTONCENTRO_H
#define MONTONCENTRO_H
#include "montoncrece.h"

class MontonCentro: public MontonCrece {
private:
    string palo;
public:
    MontonCentro();
    MontonCentro(stack<Carta>, string);
    void DejarCarta(Carta);
};

#endif // MONTONCENTRO_H

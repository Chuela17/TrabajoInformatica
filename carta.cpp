#include "carta.h"

Carta::Carta(int numero, string palo) {
    this->numcarta = numero;
    this->palocarta = palo;
}

int Carta::GetNumcarta() {
    return this->numcarta;
}

string Carta::GetPalocarta() {
    return this->palocarta;
}

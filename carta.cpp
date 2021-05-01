#include "carta.h"

Carta::Carta(int numero, string palo, string direccion) {
    this->numcarta = numero;
    this->palocarta = palo;
    this->direccioncarta = direccion;
}

Carta::~Carta() {

}

int Carta::GetNumcarta() {
    return this->numcarta;
}

string Carta::GetPalocarta() {
    return this->palocarta;
}

string Carta::GetDireccioncarta() {
    return this->direccioncarta;
}

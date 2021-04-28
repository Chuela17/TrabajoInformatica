#include "monton.h"

Monton::Monton(stack<Carta> cartas) {
    this->cartas = cartas;
}

bool Monton::EstaVacio() {
    return cartas.empty();
}

Carta Monton::CogerCarta() {
    if (this->EstaVacio()) {
        throw "El monton esta vacio";
    }

    Carta topCarta = cartas.top();
    cartas.pop();
    return topCarta;
}

Carta Monton::ConsultarCarta() {
    return cartas.top();
}

void Monton::DejarCarta(Carta carta) {
    cartas.push(carta);
}

void Monton::DejarCarta(Monton cartas) {
    while (!cartas.EstaVacio()) {
        Carta carta = cartas.CogerCarta();
        this->DejarCarta(carta);
    }
}


#include "monton.h"

Monton::Monton() {

}

Monton::Monton(stack<Carta> cartas, int identificador) {
    this->cartas = cartas;
    this->identificador = identificador;
}

Monton::~Monton() {

}

bool Monton::EstaVacio() {
    return cartas.empty();
}

bool Monton::GetVisible() {
    return this->visible;
}

void Monton::SetVisible(bool visible) {
    this->visible = visible;
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

void Monton::DejarCarta(Monton *cartas) {
    while (!cartas->EstaVacio()) {
        Carta carta = cartas->CogerCarta();
        this->DejarCarta(carta);
    }
}

void Monton::SetMonton(stack<Carta> cartas) {
    this->cartas = cartas;
}

int Monton::GetIdentificador() {
    return this->identificador;
}

stack<Carta> Monton::GetStackCartas() {
    return this->cartas;
}

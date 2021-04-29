#include "montoncentro.h"

MontonCentro::MontonCentro(stack<Carta> cartas, string palo):MontonCrece(cartas) {
    this->palo = palo;
}

void MontonCentro::DejarCarta(Carta carta) {
    if (palo != carta.GetPalocarta()) {
        throw "Los palos no coinciden, no se puede dejar la carta";
    } else if (EstaVacio() && carta.GetNumcarta() == 1) {
        MontonCrece::DejarCarta(carta);
    } else if ((carta.GetNumcarta() > ConsultarCarta().GetNumcarta()) && (carta.GetNumcarta() - ConsultarCarta().GetNumcarta() == 1)) {
        MontonCrece::DejarCarta(carta);
    } else {
        throw "No se puede dejar la carta";
    }
}


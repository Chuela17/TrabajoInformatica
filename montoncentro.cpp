#include "montoncentro.h"

MontonCentro::MontonCentro():MontonCrece() {

}

MontonCentro::MontonCentro(stack<Carta> cartas, int id, string palo):MontonCrece(cartas, id) {
    this->palo = palo;
}

MontonCentro::~MontonCentro() {

}

bool MontonCentro::ComprobarDejarCartaVacio(Carta carta) {
    return EstaVacio() && carta.GetNumcarta() == 1;
}

bool MontonCentro::ComprobarDejarCartaSuperior(Carta carta) {
    return (!EstaVacio() && carta.GetNumcarta() > ConsultarCarta().GetNumcarta())
            && (carta.GetNumcarta() - ConsultarCarta().GetNumcarta() == 1);
}

bool MontonCentro::ComprobarDejarCarta(Carta carta) {
    return this->palo == carta.GetPalocarta()
            && (this->ComprobarDejarCartaVacio(carta)
            || this->ComprobarDejarCartaSuperior(carta));
}

void MontonCentro::DejarCarta(Carta carta) {
    if (this->palo != carta.GetPalocarta()) {
        throw "Los palos no coinciden, no se puede dejar la carta";
    } else if (this->ComprobarDejarCartaVacio(carta)) {
        MontonCrece::DejarCarta(carta);
    } else if (this->ComprobarDejarCartaSuperior(carta)) {
        MontonCrece::DejarCarta(carta);
    } else {
        throw "No se puede dejar la carta";
    }
}


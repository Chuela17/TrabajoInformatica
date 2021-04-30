#include "jugador.h"
#include <iostream>

Jugador::Jugador(Monton *monton_novisible, Monton *monton_visible, string nombre) {
    this->monton_novisible = monton_novisible;
    this->monton_visible = monton_visible;
    this->nombre = nombre;
}

Carta Jugador::CogerCarta() {
    return this->monton_novisible->CogerCarta();
}

void Jugador::DejarCarta(Carta carta, Monton *monton) {
    if (!monton->GetVisible()) {
        throw "No se puede dejar la carta";
    }

    if (monton != this->monton_visible) {
        if (abs(carta.GetNumcarta() - monton->ConsultarCarta().GetNumcarta()) != 1) {
            throw "No se puede dejar la carta";
        }
    }

    if (abs(carta.GetNumcarta() - monton->ConsultarCarta().GetNumcarta()) != 1) {
        //pierdesturnojaja
    }

    monton->DejarCarta(carta);
}

Monton *Jugador::GetMontonNoVisible() {
    return this->monton_novisible;
}

Monton *Jugador::GetMontonVisible() {
    return this->monton_visible;
}

bool Jugador::SinCartas() {
    return this->monton_visible->EstaVacio() && this->monton_novisible->EstaVacio();
}

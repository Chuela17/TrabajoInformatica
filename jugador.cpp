#include "jugador.h"

Jugador::Jugador() {

}

Jugador::Jugador(Monton monton_novisible, Monton monton_visible, string nombre) {
    this->monton_novisible = monton_novisible;
    this->monton_visible = monton_visible;
    this->nombre = nombre;
}

Jugador::~Jugador() {

}

Carta Jugador::CogerCarta() {
    return this->monton_novisible.CogerCarta();
}

bool Jugador::ComprobarDejarCarta(Carta carta) {
    return abs(carta.GetNumcarta() - this->monton_visible.ConsultarCarta().GetNumcarta()) == 1;
}

void Jugador::DejarCarta(Carta carta, Monton *monton) {
    if (!monton->GetVisible()) {
        throw "No se puede dejar la carta";
    }

    monton->DejarCarta(carta);
}

void Jugador::DejarCarta(Carta carta, MontonCentro *monton) {
    monton->DejarCarta(carta);
}

Monton *Jugador::GetMontonNoVisible() {
    return &this->monton_novisible;
}

Monton *Jugador::GetMontonVisible() {
    return &this->monton_visible;
}

bool Jugador::SinCartas() {
    return this->monton_visible.EstaVacio() && this->monton_novisible.EstaVacio();
}

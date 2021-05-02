#include "partida.h"
#include "monton.h"
#include <vector>
#include <qstring.h>

Partida::Partida() {

}

Partida::Partida(string nombre1, string nombre2) {
    stack<Carta> cartas_oros;
    this->oros = MontonCentro(cartas_oros, 6, "oros");
    stack<Carta> cartas_copas;
    this->copas = MontonCentro(cartas_copas, 5, "copas");
    stack<Carta> cartas_espadas;
    this->espadas = MontonCentro(cartas_espadas, 4, "espadas");
    stack<Carta> cartas_bastos;
    this->bastos = MontonCentro(cartas_bastos, 3, "bastos");

    vector<Carta> mazo_cartas = crearmazo();
    vector<Carta> mazobarajado = barajeo(mazo_cartas);

    size_t const mitad = mazobarajado.size() / 2;
    vector<Carta> mitad1(mazobarajado.begin(), mazobarajado.begin() + mitad);
    vector<Carta> mitad2(mazobarajado.begin() + mitad, mazobarajado.end());

    // Montones no visibles de los jugadores, barajados y separados
    stack<Carta> novisible1;
    stack<Carta> novisible2;

    for (int i = 0; i < mitad1.size(); i++) {
        novisible1.push(mitad1[i]);
        novisible2.push(mitad2[i]);
    }

    Monton novisiblej1(novisible1,0);
    Monton novisiblej2(novisible2,0);
    novisiblej1.SetVisible(false);
    novisiblej2.SetVisible(false);

    // Montones visibles de los jugadores
    stack<Carta> visible1;
    stack<Carta> visible2;

    Monton visiblej1(visible1,1);
    Monton visiblej2(visible2,2);

    // Creacion de jugadores
    Jugador jugador1(novisiblej1, visiblej1, nombre1);
    Jugador jugador2(novisiblej2, visiblej2, nombre2);
    this->jugador1 = jugador1;
    this->jugador2 = jugador2;
}

Partida::~Partida() {

}

bool Partida::HaTerminado() {
    return this->jugador1.SinCartas() || this->jugador2.SinCartas();
}

Jugador *Partida::SiguienteJugador() {
    if (this->turno == 1) {
        return &jugador1;
    } else {
        return &jugador2;
    }
}

void Partida::CambiarTurno(QLabel *etiqueta) {
    if (this->turno == 1) {
        this->turno = 2;
        etiqueta->setText(QString::fromStdString("Es el turno del Jugador 2"));
    } else {
        this->turno = 1;
        etiqueta->setText(QString::fromStdString("Es el turno del Jugador 1"));
    }
}

int Partida::ComprobarDejarCarta(Carta carta, Jugador *jugador) {
    int identificador = 0;

    if (oros.ComprobarDejarCarta(carta)) {
        identificador = 6;
    } else if (copas.ComprobarDejarCarta(carta)) {
        identificador = 5;
    } else if (espadas.ComprobarDejarCarta(carta)) {
        identificador = 4;
    } else if (bastos.ComprobarDejarCarta(carta)) {
        identificador = 3;
    } else if (&jugador1 == jugador) {
        if (!jugador2.GetMontonVisible()->EstaVacio() && jugador2.ComprobarDejarCarta(carta)){
            identificador = 2;
        } else if (!jugador1.GetMontonVisible()->EstaVacio() && jugador1.ComprobarDejarCarta(carta)){
            identificador = 1;
        }
    } else if (&jugador2 == jugador) {
        if (!jugador1.GetMontonVisible()->EstaVacio() && jugador1.ComprobarDejarCarta(carta)){
            identificador = 1;
        } else if (!jugador2.GetMontonVisible()->EstaVacio() && jugador2.ComprobarDejarCarta(carta)){
            identificador = 2;
        }
    }
    return identificador;
}

void Partida::DejarCarta(Carta carta, Jugador *jugador, int id_monton, QLabel *etiqueta) {
    int identificador = this->ComprobarDejarCarta(carta, jugador);

    if (id_monton != identificador) {
        this->CambiarTurno(etiqueta);
    }
}

MontonCentro *Partida::GetOros() {
    return &this->oros;
}

MontonCentro *Partida::GetCopas() {
    return &this->copas;
}

MontonCentro *Partida::GetEspadas() {
    return &this->espadas;
}

MontonCentro *Partida::GetBastos() {
    return &this->bastos;
}

Jugador *Partida::GetJugador1() {
    return &this->jugador1;
}

Jugador *Partida::GetJugador2() {
    return &this->jugador2;
}

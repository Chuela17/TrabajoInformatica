#include "informacion.h"

Informacion::Informacion(int numerojugador) {
    this->numerojugador = numerojugador;
}

Informacion::~Informacion() {

}

string Informacion::ObtenerInformacion1(Jugador *jugador1) {
    int numero_cartas_novisible = jugador1->GetMontonNoVisible()->GetStackCartas().size();
    int numero_cartas_visible = jugador1->GetMontonVisible()->GetStackCartas().size();

    int total_cartas = numero_cartas_novisible + numero_cartas_visible;

    string numero = to_string(total_cartas);
    string texto = "El numero de cartas que tiene el jugador 1 es: ";

    string informacion = texto + numero;

    return informacion;
}

string Informacion::ObtenerInformacion2(Jugador *jugador2) {
    int numero_cartas_novisible = jugador2->GetMontonNoVisible()->GetStackCartas().size();
    int numero_cartas_visible = jugador2->GetMontonVisible()->GetStackCartas().size();

    int total_cartas = numero_cartas_novisible + numero_cartas_visible;

    string numero = to_string(total_cartas);
    string texto = "El numero de cartas que tiene el jugador 2 es: ";

    string informacion = texto + numero;

    return informacion;
}

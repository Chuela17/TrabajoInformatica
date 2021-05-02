#ifndef PARTIDA_H
#define PARTIDA_H
#include "jugador.h"
#include "montoncentro.h"
#include "crearmazo.h"
#include <qlabel.h>

class Partida {
private:
    Jugador jugador1;
    Jugador jugador2;
    int turno = 1;
    MontonCentro oros;
    MontonCentro copas;
    MontonCentro espadas;
    MontonCentro bastos;
    void CambiarTurno(QLabel *);
public:
    Partida(); // Constructor
    Partida(string, string); // Constructor
    ~Partida(); // Destructor
    bool HaTerminado(); // Saber si la partida ha terminado o no
    Jugador *SiguienteJugador(); // Obtener el jugador al que le corresponda tener el turno
    int ComprobarDejarCarta(Carta, Jugador *); // Obtener el identificador del montón donde se debe dejar la carta
                                               // que haya sacado el jugador de su mazo
    void DejarCarta(Carta, Jugador *, int, QLabel *); // Dejar una carta
    MontonCentro *GetOros(); // Obtener el montón de oros
    MontonCentro *GetCopas(); // Obtener el montón de copas
    MontonCentro *GetEspadas(); // Obtener el montón de espadas
    MontonCentro *GetBastos(); // Obtener el montón de bastos
    Jugador *GetJugador1(); // Obtener el jugador 1
    Jugador *GetJugador2(); // Obtener el jugador 2
};

extern Partida mipartida;

#endif // PARTIDA_H

#include <carta.h>
#include "carta.cpp"
#include <vector>
#include <string>

using namespace std;

vector<Carta> crearmazo(){
    vector<Carta> baraja;

    Carta O1(1,"Oros");
    baraja.push_back(O1);
    Carta O2(2,"Oros");
    baraja.push_back(O2);
    Carta O3(3,"Oros");
    baraja.push_back(O3);
    Carta O4(4,"Oros");
    baraja.push_back(O4);
    Carta O5(5,"Oros");
    baraja.push_back(O5);
    Carta O6(6,"Oros");
    baraja.push_back(O6);
    Carta O7(7,"Oros");
    baraja.push_back(O7);
    Carta O10(10,"Oros");
    baraja.push_back(O10);
    Carta O11(11,"Oros");
    baraja.push_back(O11);
    Carta O12(12,"Oros");
    baraja.push_back(O12);

    Carta B1(1,"Bastos");
    baraja.push_back(B1);
    Carta B2(2,"Bastos");
    baraja.push_back(B2);
    Carta B3(3,"Bastos");
    baraja.push_back(B3);
    Carta B4(4,"Bastos");
    baraja.push_back(B4);
    Carta B5(5,"Bastos");
    baraja.push_back(B5);
    Carta B6(6,"Bastos");
    baraja.push_back(B6);
    Carta B7(7,"Bastos");
    baraja.push_back(B7);
    Carta B10(10,"Bastos");
    baraja.push_back(B10);
    Carta B11(11,"Bastos");
    baraja.push_back(B11);
    Carta B12(12,"Bastos");
    baraja.push_back(B12);

    Carta E1(1,"Espadas");
    baraja.push_back(E1);
    Carta E2(2,"Espadas");
    baraja.push_back(E2);
    Carta E3(3,"Espadas");
    baraja.push_back(E3);
    Carta E4(4,"Espadas");
    baraja.push_back(E4);
    Carta E5(5,"Espadas");
    baraja.push_back(E5);
    Carta E6(6,"Espadas");
    baraja.push_back(E6);
    Carta E7(7,"Espadas");
    baraja.push_back(E7);
    Carta E10(10,"Espadas");
    baraja.push_back(E10);
    Carta E11(11,"Espadas");
    baraja.push_back(E11);
    Carta E12(12,"Espadas");
    baraja.push_back(E12);

    Carta C1(1,"Copas");
    baraja.push_back(C1);
    Carta C2(2,"Copas");
    baraja.push_back(C2);
    Carta C3(3,"Copas");
    baraja.push_back(C3);
    Carta C4(4,"Copas");
    baraja.push_back(C4);
    Carta C5(5,"Copas");
    baraja.push_back(C5);
    Carta C6(6,"Copas");
    baraja.push_back(C6);
    Carta C7(7,"Copas");
    baraja.push_back(C7);
    Carta C10(10,"Copas");
    baraja.push_back(C10);
    Carta C11(11,"Copas");
    baraja.push_back(C11);
    Carta C12(12,"Copas");
    baraja.push_back(C12);
    return baraja;
}

#include <carta.h>
#include "carta.cpp"
#include <vector>
#include <string>

using namespace std;

vector<Carta> crearmazo(){
    vector<Carta> baraja;

    Carta O1(1, "oros", "QPushButton{image: url(:/new/prefix1/imagenes/1O)}");
    baraja.push_back(O1);
    Carta O2(2, "oros", "QPushButton{image: url(:/new/prefix1/imagenes/2O)}");
    baraja.push_back(O2);
    Carta O3(3, "oros", "QPushButton{image: url(:/new/prefix1/imagenes/3O)}");
    baraja.push_back(O3);
    Carta O4(4, "oros", "QPushButton{image: url(:/new/prefix1/imagenes/4O)}");
    baraja.push_back(O4);
    Carta O5(5, "oros", "QPushButton{image: url(:/new/prefix1/imagenes/5O)}");
    baraja.push_back(O5);
    Carta O6(6, "oros", "QPushButton{image: url(:/new/prefix1/imagenes/6O)}");
    baraja.push_back(O6);
    Carta O7(7, "oros", "QPushButton{image: url(:/new/prefix1/imagenes/7O)}");
    baraja.push_back(O7);
    Carta O10(8, "oros", "QPushButton{image: url(:/new/prefix1/imagenes/10O)}");
    baraja.push_back(O10);
    Carta O11(9, "oros", "QPushButton{image: url(:/new/prefix1/imagenes/11O)}");
    baraja.push_back(O11);
    Carta O12(10, "oros", "QPushButton{image: url(:/new/prefix1/imagenes/12O)}");
    baraja.push_back(O12);

    Carta B1(1, "bastos", "QPushButton{image: url(:/new/prefix1/imagenes/1B)}");
    baraja.push_back(B1);
    Carta B2(2, "bastos", "QPushButton{image: url(:/new/prefix1/imagenes/2B)}");
    baraja.push_back(B2);
    Carta B3(3, "bastos", "QPushButton{image: url(:/new/prefix1/imagenes/3B)}");
    baraja.push_back(B3);
    Carta B4(4, "bastos", "QPushButton{image: url(:/new/prefix1/imagenes/4B)}");
    baraja.push_back(B4);
    Carta B5(5, "bastos", "QPushButton{image: url(:/new/prefix1/imagenes/5B)}");
    baraja.push_back(B5);
    Carta B6(6, "bastos", "QPushButton{image: url(:/new/prefix1/imagenes/6B)}");
    baraja.push_back(B6);
    Carta B7(7, "bastos", "QPushButton{image: url(:/new/prefix1/imagenes/7B)}");
    baraja.push_back(B7);
    Carta B10(8, "bastos", "QPushButton{image: url(:/new/prefix1/imagenes/10B)}");
    baraja.push_back(B10);
    Carta B11(9, "bastos", "QPushButton{image: url(:/new/prefix1/imagenes/11B)}");
    baraja.push_back(B11);
    Carta B12(10, "bastos", "QPushButton{image: url(:/new/prefix1/imagenes/12B)}");
    baraja.push_back(B12);

    Carta E1(1, "espadas", "QPushButton{image: url(:/new/prefix1/imagenes/1E)}");
    baraja.push_back(E1);
    Carta E2(2, "espadas", "QPushButton{image: url(:/new/prefix1/imagenes/2E)}");
    baraja.push_back(E2);
    Carta E3(3, "espadas", "QPushButton{image: url(:/new/prefix1/imagenes/3E)}");
    baraja.push_back(E3);
    Carta E4(4, "espadas", "QPushButton{image: url(:/new/prefix1/imagenes/4E)}");
    baraja.push_back(E4);
    Carta E5(5, "espadas", "QPushButton{image: url(:/new/prefix1/imagenes/5E)}");
    baraja.push_back(E5);
    Carta E6(6, "espadas", "QPushButton{image: url(:/new/prefix1/imagenes/6E)}");
    baraja.push_back(E6);
    Carta E7(7, "espadas", "QPushButton{image: url(:/new/prefix1/imagenes/7E)}");
    baraja.push_back(E7);
    Carta E10(8, "espadas", "QPushButton{image: url(:/new/prefix1/imagenes/10E)}");
    baraja.push_back(E10);
    Carta E11(9, "espadas", "QPushButton{image: url(:/new/prefix1/imagenes/11E)}");
    baraja.push_back(E11);
    Carta E12(10, "espadas", "QPushButton{image: url(:/new/prefix1/imagenes/12E)}");
    baraja.push_back(E12);

    Carta C1(1, "copas", "QPushButton{image: url(:/new/prefix1/imagenes/1C)}");
    baraja.push_back(C1);
    Carta C2(2, "copas", "QPushButton{image: url(:/new/prefix1/imagenes/2C)}");
    baraja.push_back(C2);
    Carta C3(3, "copas", "QPushButton{image: url(:/new/prefix1/imagenes/3C)}");
    baraja.push_back(C3);
    Carta C4(4, "copas", "QPushButton{image: url(:/new/prefix1/imagenes/4C)}");
    baraja.push_back(C4);
    Carta C5(5, "copas", "QPushButton{image: url(:/new/prefix1/imagenes/5C)}");
    baraja.push_back(C5);
    Carta C6(6, "copas", "QPushButton{image: url(:/new/prefix1/imagenes/6C)}");
    baraja.push_back(C6);
    Carta C7(7, "copas", "QPushButton{image: url(:/new/prefix1/imagenes/7C)}");
    baraja.push_back(C7);
    Carta C10(8, "copas", "QPushButton{image: url(:/new/prefix1/imagenes/10C)}");
    baraja.push_back(C10);
    Carta C11(9, "copas", "QPushButton{image: url(:/new/prefix1/imagenes/11C)}");
    baraja.push_back(C11);
    Carta C12(10, "copas", "QPushButton{image: url(:/new/prefix1/imagenes/12C)}");
    baraja.push_back(C12);

    return baraja;
}

#include "montoncrece.h"

MontonCrece::MontonCrece() {

}

MontonCrece::MontonCrece(stack<Carta> cartas, int id):Monton(cartas, id) {

}

MontonCrece::~MontonCrece() {

}

Carta MontonCrece::CogerCarta() {
    throw "No se puede coger carta";
}

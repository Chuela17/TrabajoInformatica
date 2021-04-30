#include "montoncrece.h"

MontonCrece::MontonCrece() {

}

MontonCrece::MontonCrece(stack<Carta> cartas):Monton(cartas) {

}

Carta MontonCrece::CogerCarta() {
    throw "No se puede coger carta";
}

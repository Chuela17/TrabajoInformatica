#ifndef MONTONCRECE_H
#define MONTONCRECE_H
#include "monton.h"

class MontonCrece: public Monton {
public:
    MontonCrece();
    MontonCrece(stack<Carta>);
    Carta CogerCarta();
};

#endif // MONTONCRECE_H

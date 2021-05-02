#ifndef MONTONCRECE_H
#define MONTONCRECE_H
#include "monton.h"

class MontonCrece: public Monton {
public:
    MontonCrece(); // Constructor vacío
    MontonCrece(stack<Carta>, int); // Constructor
    ~MontonCrece(); // Destructor
    Carta CogerCarta(); // Coger una carta del montón, método modificado de la clase de la que hereda,
                        // puesto que en esta clase no se podrá coger carta
};

#endif // MONTONCRECE_H

#ifndef CARTA_H
#define CARTA_H
#include <string>

using namespace std;

class Carta {
private:
    int numcarta;
    string palocarta;

public:
    Carta(int, string);
    int GetNumcarta();
    string GetPalocarta();
};

#endif // CARTA_H

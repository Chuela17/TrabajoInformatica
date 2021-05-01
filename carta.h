#ifndef CARTA_H
#define CARTA_H
#include <string>

using namespace std;

class Carta {
private:
    int numcarta;
    string palocarta;
    string direccioncarta;

public:
    Carta(int, string, string);
    ~Carta();
    int GetNumcarta();
    string GetPalocarta();
    string GetDireccioncarta();
};

#endif // CARTA_H

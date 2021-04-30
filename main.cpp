#include <carta.h>
#include <crearmazo.h>
#include <vector>
#include <string>
#include <iostream>


using namespace std;

int main(){
    vector<Carta> prueba=crearmazo();
    vector<Carta> mazobarajado=barajeo(prueba);
    return 0;
}

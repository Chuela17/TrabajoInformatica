#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <carta.h>
using namespace std;

vector<Carta> barajeo(vector<Carta> baraja){

   time_t t;

   //Inicialización de srand//
   srand((unsigned) time(&t));

   //Bucle de salteado de números//
   int i=0;
   for (i=0;i<=40;i++){

   int n1 = rand() % 40;
   int n2 = rand() % 40;

   Carta aux(0,"");
   aux=baraja[n1];
   baraja[n1]=baraja[n2];
   baraja[n2]=aux;
   }
   return baraja;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main(){
   vector<int> baraja(40);
   int i=0;
   for(i=0;i<baraja.size();i++){
       baraja[i]=i+1;
   }
   int n;
   time_t t;

   //Inicialización de srand//
   srand((unsigned) time(&t));

   //Bucle de salteado de números//
   i=0;
   for (i=0;i<=40;i++){

   int n1 = rand() % 40;
   int n2 = rand() % 40;

   int aux=0;
   aux=baraja[n1];
   baraja[n1]=baraja[n2];
   baraja[n2]=aux;
   }
   return 0;
}

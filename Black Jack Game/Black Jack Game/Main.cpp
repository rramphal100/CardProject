#include <iostream>
#include "Deck.h"

using namespace std;

int main(){
   Deck* x = new Deck();
   x->shuffle();
   cout << x << endl;

   system("PAUSE");
   return 0;



}
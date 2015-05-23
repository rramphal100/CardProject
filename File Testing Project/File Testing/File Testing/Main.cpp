#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Stack.h"

using namespace std;

int main(){
   Deck x;
   cout << x << endl << endl;
   x.shuffle();
   cout << x << endl << endl;

   Card y = x.deal();
   y = x.deal();

   cout << y << endl << endl;

   system("PAUSE");
   return 0;
}
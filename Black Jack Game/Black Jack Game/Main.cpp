//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Node.h"

using namespace std;

int main(){
   Deck x;

   cout << x << endl << endl;

   x.shuffle();
   cout << x << endl << endl;

   system("PAUSE");
   return 0;



}
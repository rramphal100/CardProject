#include "Deck.h"
#include "Card.h"
#include "Stack.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

Deck::Deck() {
    int index = 0;
    for (int rank = 0; rank < 13; rank++) {
       for ( int suit = 0; suit < 4; suit++) {
          deck->push(Card(rank, suit)); //the "->" means to access a function from the class type that the pointer is storing an address for (this line is the same as a deck object x, then using x.push(...))
       }
    }
    index++;
}

void Deck::shuffle() {
    Card temp[52];
    for (int i=0; i<52; i++){
       temp[i] = deck->pop();
    }
    
    /*
    while (!deck->isFull()){
       int i = rand()%52;
       if (temp[i] == NULL) continue;
       else {
          deck->push(temp[i]);
          temp[i] = NULL;
       }
    }
}
    */
    
    int i1, i2;
    srand(time(0));
    for (int i=0; i<1000; i++){ //interchanges cards 1000 times per shuffle
       i1 = rand()%52; //pick 2 random indexes to swap with one another in this temp card array
       i2 = rand()%52;
       
       Card store = temp[i1]; //stores a temp copy of the card at index i1 of the temp card array for proper completion of the swap
       temp[i1] = temp[i2];
       temp[i2] = store;
    }
    
    for (int i=0; i<52; i++) deck->push(temp[i]);
}

int Deck::getCount() return deck->getCount();

Card Deck::deal() return deck->pop();

ostream& operator <<(ostream& out, const Deck& in){ //codes for how to output a deck called "in" with operator << using variable "out"
   Stack* copy = in.deck;
   for (int i = 0; i<copy.getCount(); i++){
      out << copy.deck[i] << endl;
   }
   return out;
}




































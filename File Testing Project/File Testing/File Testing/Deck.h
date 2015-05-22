#ifndef DECK_H
#define DECK_H

#include "Stack.h"
#include "Card.h"

class Deck
{
private:
   Stack* deck;
public:
   Deck();
   void shuffle();
   int getCount();
   const Card deal();
   //const Card* deal(int); //extra credit
   friend ostream& operator <<(ostream& out, const Deck& in);
};

#endif
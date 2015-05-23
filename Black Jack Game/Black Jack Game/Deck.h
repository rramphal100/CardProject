//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#ifndef DECK_H
#define DECK_H

#include "Stack.h"
#include "Card.h"

class Deck
{
private:
   Stack deck;
public:
   Deck();
   void shuffle();
   int getCount() const;
   const Card deal();
   //const Card* deal(int); //extra credit
   friend ostream& operator <<(ostream& out, const Deck& in);
};

#endif
//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#ifndef HAND_H
#define HAND_H
#include <iostream>
#include "LinkedList.h"
using namespace std;

class Hand{
private:
   LinkedList* hand;

public:
   Hand();
   Hand(const Hand&); //copy constructor (check syntax of big 3!)
   ~Hand(); //destructor
   Hand& operator = (Hand&); //assignment operator overload
   void addCard();
   void removeCard();
   int getTotalValue(); //returns value of the entire hand
   int getCount();
   void convertAcesDown(); //convert ace's value to 1
   /*can be like:
   while(value>21)
   //convert Ace value from 11 to 1
   */
   static int compareHand(const Hand&); //return 0 if  hands have the same total value,  +ve # if calling hand has higher value than parameter hand, etc.
   void display();
   friend ostream& operator << (ostream&, Hand&);
};
#endif
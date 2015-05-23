//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#ifndef HAND_H
#define HAND_H

#include "LinkedList.h"
#include <iostream>
using namespace std;

class Hand
{
private:
   LinkedList* hand;
public:
   Hand();
   Hand(const Hand&);
   ~Hand();
   Hand& operator=(const Hand&);
   int getCount() const;
   void insertByRank(Card*);
   void insertLast(Card*);
   void remove();
   int evaluate() const;
   //void convertAcesDown();
   //We used a method that converts aces down directly in evaluate()
   int compare(const Hand&) const;
   bool isEmpty() const;
   friend ostream& operator<<(ostream&, const Hand&);
};

#endif
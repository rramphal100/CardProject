#ifndef PLAYER_H
#define PLAYER_H
#include "Hand.h"
#include <iostream>
using namespace std;

class Player{
private:
   string name;
   Hand hand;
   int points;
public:
   Player();
   Player(string name);
   void setName(string name);
   string getName();

   void addCard(Card*);
   //get total value - if over 21 check for aces of value 11 and convert to value 1

   int evaluate();

   void showHand();
   friend ostream& operator << (ostream&, const Player&); //displays Player's info
};

#endif
//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#include "Hand.h"
#include <iostream>
using namespace std;

Hand::Hand() : hand(new LinkedList()) {}

Hand::Hand(const Hand& other) { //copy constructor overload
   for (int i = 0; i < getCount(); i++){
      delete (*hand).removeAtIndex(i);
   }
   delete hand;

   hand = new LinkedList();
   Node* current = new Node(*hand->getHead());

   /*for (int i = 0; i<other.getCount(); i++){
      current = new*/

   //count = other.getCount();
}

int Hand::getCount(){
   return hand->getSize();
}
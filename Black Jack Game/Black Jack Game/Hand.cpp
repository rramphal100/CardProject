#include "Hand.h"

Hand::Hand(){
   hand = new LinkedList();
}

Hand::Hand(const Hand& otherHand){
   hand = otherHand.hand;
}

Hand::~Hand(){
   if (hand != NULL) delete hand;
}

Hand& Hand::operator = (const Hand& otherHand){
   if (this != &otherHand){
      if (hand != NULL){
         delete hand;
      }
      hand = new LinkedList(*otherHand.hand);
   }
   return *this;
}

int Hand::getCount() const{
   return hand->getSize();
}

void Hand::insertByRank(Card* card){
   if (hand->getHead() == NULL){
      hand->insertAtTail(card);
      return;
   }
   int i = 0;
   while (i < getCount()){
      if (card->compareByRank((*hand)[i]) <= 0) break;
      ++i;
   }
   if (i < getCount()){
      hand->insertAtIndex(card, i);
      return;
   }
   hand->insertAtTail(card);
}

void Hand::insertLast(Card* card){
   hand->insertAtTail(card);
}

void Hand::remove(){
   if (hand != NULL) delete hand;
}

int Hand::evaluate() const{
   int value[10]; //array to store the possible values for a single card
   for (int i = 0; i < 10; ++i){
      value[i] = i + 1;
   }

   int handValue = 0;
   //stores the overall value of the hand (sum of all the cards' values)

   int numAces = 0; //stores how many aces are in the hand

   //determine the value of each possible card
   for (int i = 0; i < getCount(); ++i){
      int current = hand->getAtIndex(i)->getRank();
      if (current == 0){
         ++numAces;
         handValue += 11;
      }
      else if (current < 10) handValue += current + 1;
      else handValue += 10;
   }

   //adjust value for presence of aces in hand as necessary
   while (handValue > 21 && numAces > 0){
      handValue -= 10;
      //convert the value of each ace that it's necessary for from 11 to 1 by subtracting 10 from total value
      --numAces;
   }
   return handValue;
}

int Hand::compare(const Hand& otherHand) const{
   //compare the values of the 2 hands
   //return -1 if this has lower value than otherHand
   //return 0 if they have the same value
   //return 1 if this has larger value than otherHand
   int thisValue = evaluate();
   int otherValue = otherHand.evaluate();
   if (thisValue < otherValue) return -1;
   else if (thisValue == otherValue) return 0;
   return 1;
}

bool Hand::isEmpty() const{
   return hand->isEmpty();
}

ostream& operator << (ostream& out, const Hand& in){
   if (in.hand->getSize() == 0){
      out << "This hand is empty.\n";
      return out;
   }
   for (int i = 0; i < in.hand->getSize(); ++i){
      out << *in.hand->getAtIndex(i) << ", ";
   }
   return out;
}
//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card() {

   suit = -1;
   rank = -1;

}
Card::Card(int rank, int suit) { this->rank = rank; this->suit = suit; }

int Card::getSuit() { return suit; }
int Card::getRank() { return rank; }

void Card::setSuit(int suit) { this->suit = suit; }
void Card::setRank(int rank) { this->rank = rank; }

//negative means the current greater than the card passed in
int Card::compareByRank(const Card& card) { return rank - card.rank; }
int Card::compareBySuit(const Card& card) { return suit - card.suit; }

string Card::getRankAsString() const {

   string rankArray[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9",
      "10", "J", "Q", "K" };
   return rankArray[rank];

}

string Card::getSuitAsString() const {

   string suitArray[] = { "H", "S", "D", "C" };
   return suitArray[suit];


}

string Card::display(){
   return getRankAsString() + getSuitAsString();
}



ostream& operator <<(ostream& o, const Card& card) {
	/*o << endl;
	o << ".------. " << endl;
	o << "|  (')  |" << endl;
	o << "| (_X_) |" << endl;
	o << "| A ^ C |" << endl;
	o << "`-------'" << endl;*/
	o << card.getRankAsString() << card.getSuitAsString();
	return o;

}
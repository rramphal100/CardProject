#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card() {
	
	value = -1;
	rank = -1;
	
}
Card::Card(int rank, int suit) { this->rank = rank; this->suit = suit; }

int Card::getSuit() { return suit; }
int Card::getRank() { return rank; }

void Card::setSuit(int suit) { this->suit = suit; }
void Card::setRank(int rank) { this->rank = rank; }

//negative means the current greater than the card passed in
int compareByRank(const Card& card) { return rank - card.rank; } 
int Card::compareBySuit(const Card& card) {	return suit - card.suit; }

string Card::getRankAsString() const {
		
		string rankArray[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine",
								"Ten","Jack","Queen","King"};
		return rankArray[rank];
		
}

string Card::getSuitAsString() const {
	
	string suitArray[] = {"Hearts","Spades","Diamonds","Clubs"};
	return suitArray[suit];


}

ostream& operator <<(ostream& obj, const Card& card) {

	return obj << card.getRankAsString() << " of " << card.getSuitAsString() << endl;
	
	
}
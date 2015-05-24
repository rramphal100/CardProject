//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#include "Player.h"
#include <iostream>
    
    Player::Player():name(""), points(0) {
    }
    
    Player::Player(string name):name(name), points(0) {
    }
    
    void Player::setName(string n) {
        name = n;
    }
    
    string Player::getName() const{ return name; }
    
    void Player::showHand() {
        cout << hand << endl;
    }
    
    void Player::addCard(Card* d) {
        //TM: hand is NOT a linked list...
		hand.insertLast(d); 
		
		// i assume this is at the end of the "hand", you usually dont add from the top, however where its added I think is arbritary to blackjack
        // however can just switch to inserAthead(Card* data); Hand is a LinkedList* so this should work
    }
    
    int Player::evaluate() {
		points = hand.evaluate();
		
		return points;
    }
    
    ostream& operator<<(ostream& os, const Player& obj) {
		os << endl << "-----------------------------" <<endl;
		os << obj.name << endl;
        os << "Hand: " << obj.hand << "         ";
        os << "Score: " << obj.points<< endl<<endl;
        
        return os;
        
        
    }
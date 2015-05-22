//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#include "Player.h"
#include <iostream>
    
    Player::Player() {
        hand = new Hand();
        name = "noname";
        points = 0;
    }
    
    Player::Player(string name) {
        this->name = name;
        hand = new Hand();
        points = 0;
    }
    
    void Player::setName(string n) {
        name = n;
    }
    
    string Player::getName() { return name; }
    
    void Player::showHand() {
        cout << hand << endl;
    }
    
    void Player::addCard(Card* d) {
        hand->insertAtTail(d); // i assume this is at the end of the "hand", you usually dont add from the top, however where its added I think is arbritary to blackjack
        // however can just switch to inserAthead(Card* data); Hand is a LinkedList* so this should work
    }
    
    int Player::evaluate() {
        for (int i = 0; i < hand->getCount(); i++) {
            
            
        }    
    
    }
    
    ostream& Player::operator<<(ostream& os, const Player& obj) {
        
        os << obj.name << endl;
        os << obj.hand << endl;
        os << obj.points << endl;
        
        return os;
        
        
    }
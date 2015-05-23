//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <vector>
#include <string>
#include "Deck.h"
#include "Player.h"

typedef vector<Player*> PlayerVector;
enum MainMenu {NEWGAME, QUIT};
enum GameOptions {HIT, STAND};

class BlackJack
{
private:
	Deck deck;
	PlayerVector players;
public:
	BlackJack();
	void createPlayers();
	void deal();
	void dealSingleClard(Player* );
	void displayMainMenu();
	void startNewGame();
	void displayHands();

};

#endif
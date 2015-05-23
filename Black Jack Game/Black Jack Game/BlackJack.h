//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "Deck.h"
#include "Player.h"
#include <vector>

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
	void displayMainMenu();
	void startNewGame();

};

#endif
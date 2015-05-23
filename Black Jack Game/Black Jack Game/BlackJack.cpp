#include "BlackJack.h"

PlayerVector players;

BlackJack::BlackJack() {
	createPlayers();
	displayMainMenu();
}

void BlackJack::createPlayers() {
	//Create player object
	string name="test";
	//cout << "Please enter your name" << endl;
	//cin >> name;
	Player* p = new Player(name);
	players.push_back(p);

	//create dealer object
	Player* d = new Player("Dealer");
	players.push_back(d);

}

void BlackJack::startNewGame() {
	cout << endl << endl << "-------------------------------" << endl;
	cout << "Starting  new game..." << endl;
	deal();
	displayHands();


}

void BlackJack::deal() {
	cout << "Dealing cards..." << endl;
	for (int i = 0, l = players.size(); i < l; i++){
		Card* c = deck.deal(0);
		players.at(i)->addCard(c);
	}
}

void BlackJack::dealSingleClard(Player* player){
	Card* c = deck.deal(0);
	player->addCard(c);
}
void BlackJack::displayMainMenu() {
	int command;
	while (true){
		cout << endl << endl << "----------------------------------" << endl;
		cout << "0 - Start New Game\n1 - Quit" << endl;
		cin >> command;
		switch (command){
		case NEWGAME:
			startNewGame();
			continue;
		case QUIT:
			exit(0);
			continue;
		default:
			cout << "Invalid choice... Please select from the menu";
			continue;
		}
	}
}

void BlackJack::displayHands() {
	for (int i = 0, l = players.size(); i < l; i++){
		cout << *(players.at(i));
	}
}
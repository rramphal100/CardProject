#include "BlackJack.h"

PlayerVector players;

BlackJack::BlackJack() {
	createPlayers();
	displayMainMenu();
}

void BlackJack::createPlayers() {
	//Create player object
	string name;
	cout << "Please enter your name" << endl;
	cin >> name;
	Player* p = new Player(name);
	players.push_back(p);

	//create dealer object
	Player* d = new Player("Dealer");
	players.push_back(d);

}

void BlackJack::startNewGame() {
	cout << endl << endl << "-------------------------------" << endl;
	cout << "Starting  new game..." << endl;
	cout << "Dealing cards..." << endl;


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


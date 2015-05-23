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


}
void BlackJack::displayMainMenu() {
	int command;
	while (true){
		cout << "----------------------------------" << endl;
		cout << ""
	}
}

BlackJack::createPlayers() {



}
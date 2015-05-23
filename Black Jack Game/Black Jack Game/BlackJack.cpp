#include "BlackJack.h"

PlayerVector players;

string name;
BlackJack::BlackJack() {
	name = "pLayer 1";
	//cout << "Please enter your name" << endl;
	//cin >> name;
	startNewGame();
	displayMainMenu();
}

void BlackJack::createPlayers(const string& name) {
	players.clear();
	//create dealer object
	Player* d = new Player("Dealer");
	players.push_back(d);

	Player* p = new Player(name);
	players.push_back(p);



}

void BlackJack::startNewGame() {
	createPlayers(name);
	cout << endl << endl << "-------------------------------" << endl;
	cout << "Dealing cards..." << endl << endl;
	deal();
	displayGameState();
	displayGameMenu();


}

void BlackJack::deal() {
	deck.shuffle();
	//deal 2 cards to each player
	for (int i = 0, l = players.size(); i < l; i++){
		dealSingleCard(players.at(i));
		dealSingleCard(players.at(i));
	}
}

void BlackJack::dealSingleCard(Player* player){
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
void BlackJack::displayGameMenu() {
	int command;
	while (true){
		cout << endl << endl << "----------------------------------" << endl;
		cout << "0 - Hit\n1 - Stand" << endl;
		cin >> command;
		switch (command){
		case HIT:
			hit(players.at(1));
			continue;
		case STAND:
			stand(players.at(1));
			continue;
		default:
			cout << "Invalid choice... Please select from the menu";
			continue;
		}
	}
}

void BlackJack::hit(Player* p) {
	cout << p->getName() << " - hits....";
	dealSingleCard(p);
	displayGameState();
	if (p->evaluate() > 21) { displayResult(); }

}

void BlackJack::stand(Player* p) {
	cout << p->getName() << " - stands....";
	dealerMove();
}
void BlackJack::dealerMove() {
	Player* dealer = players.at(0);
	int points = dealer->evaluate();
	//not a very sophisticated algorithm...
	while (points < 16) {
		hit(dealer);
		points = dealer->evaluate();
	}
	displayResult();
}

void BlackJack::displayResult() {
	Player* player = players.at(1);
	Player* dealer = players.at(0);
	string res;
	int playerPoints = player->evaluate();
	int dealerPoints = dealer->evaluate();
	if (playerPoints > 21){
		res = player->getName() + " busted. Dealer won !!!";
	}
	else if (dealerPoints > 21){
		res = "Dealer busted. " + player->getName() + " won !!!";
	}
	else if (playerPoints == dealerPoints) {
		res = "Draw.";
	}
	else if (playerPoints > dealerPoints) {
		res = player->getName() + " won!!!";
	}
	else {
		res = dealer->getName() + " won!!!";
	}

	cout << endl << "***************************" << endl;
	cout << res;
	cout << endl << "***************************" << endl;
	displayMainMenu();
}

void BlackJack::displayGameState() {
	cout << string(50, '\n');
	for (int i = 0, l = players.size(); i < l; i++){
		players.at(i)->evaluate();
		cout << *(players.at(i));
	}
}
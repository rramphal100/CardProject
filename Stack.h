#ifndef STACK_H
#define STACK_H

#include "Card.h"

class Stack
{
private:
	static const int capacity  = 52;
	Card cards[52];
	int count;
public:
	Stack();
	void push(Card c);
	Card pop();
	Card peek();
	bool isEmpty();
	bool isFull();
	int getCount();
	string display();
	friend ostream& operator <<(ostream&, const Stack&);
};

#endif
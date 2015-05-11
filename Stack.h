#ifndef STACK_H
#define STACK_H

#include "Card.h"

class Stack
{
private:
	Card** stack;
	int capacity;
	int count;
public:
	Stack();
	Stack(int cap);
	Stack(const Stack& other);
	~Stack();
	bool push(const Card& c);
	Card* pop();
	Card* peek();
	bool isEmpty();
	bool isFull();
	int getCount();
	string display();
	friend ostream& operator <<(ostream&, const Stack&);
	Stack& operator=(const Stack& other);
};
#endif
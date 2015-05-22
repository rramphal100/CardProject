#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

class LinkedList
{
private:
   Node *head;
   Node *tail;
   int size;
public:
   LinkedList();
   LinkedList(LinkedList& otherList);
   Card* getHead();
   Card* getTail();
   Card* getAtIndex(int);
   int getSize();
   void insertAtHead(Card* data);
   void insertAtTail(Card* data);
   bool insertAtIndex(Card* data, int index);
   Card* removeAtHead();
   Card* removeAtTail();
   Card* removeAtIndex(int index);
   Card* remove(Card* data);
   bool contains(Card* data);
   int search(Card* data);
   bool isEmpty();
   const Card& operator[](int index);
   friend ostream& operator <<(ostream&, const LinkedList&);
   LinkedList& operator=(const LinkedList& otherList);
   ~LinkedList();
};

#endif
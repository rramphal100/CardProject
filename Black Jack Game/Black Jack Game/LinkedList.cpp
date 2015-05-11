#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(NULL), tail(NULL), size(0) {}

LinkedList::LinkedList(LinkedList& otherlist) { //copy constructor
   for (int i = 0; i<getSize(); i++){
      insertAtTail(otherlist.getAtIndex(i));
   }
}

Card* LinkedList::getHead(){
   return &head->getData();
}

Card* LinkedList::getTail(){
   return &tail->getData();
}

Card* LinkedList::getAtIndex(int i){
   Node* current = head;
   for (int j = 0; j <= i; j++){
      current = current->getNext();
   }
   return &current.getData();
}

int LinkedList::getSize(){
   return size;
}

void LinkedList::insertAtHead(Card* data){
   Node* c = new Node(*data);
   c->setNext(head);
   head = c;
   size++;
}

void LinkedList::insertAtTail(Card* data){
   tail->setNext(new Node(*data));
   tail = tail->getNext();
}

bool LinkedList::insertAtIndex(Card* data, int index){
   Node* current = head

















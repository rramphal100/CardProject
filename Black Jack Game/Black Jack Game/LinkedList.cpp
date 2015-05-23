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
   return &current->getData();
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
   Node* current = head;
   if (index == 0){
      insertAtHead(data);
      return true;
   }

   else if (index < size){
      for (int i = 0; i < index; i++){
         current = current->getNext();
      }
      Node* insert = new Node(*data);
      insert->setNext(current->getNext());
      current->setNext(insert);
      return true;
   }

   else return false;
}

Card* LinkedList::removeAtHead(){
   /*Node* current = head;
   head = head->getNext();
   return &current->getData();*/

   Card* data = &head->getData();
   Node* current = head;
   head = head->getNext();
   delete current;
   return data;
}

Card* LinkedList::removeAtTail(){
   /*Node* current = head;
   delete tail;
   for (int i = 0; i < size-1; i++){
      current = current->getNext();
   }
   current->setNext(NULL);
   tail = current;*/

   Card* data = &tail->getData();
   Node* current = head;
   for (int i = 0; i < size - 1; i++){
      current = current->getNext();
   }
   current->setNext(NULL);
   tail = current;
   return data;
}

Card* LinkedList::removeAtIndex(int index){
   Node* current = head;
   for (int i = 0; i < index - 1; i++){
      current = current->getNext();
   }
   Node* old = current->getNext();
   current->setNext(current->getNext()->getNext());
   Card* data = &old->getData();
   delete old;
   return data;
}


//please check this out, guys!! I'm not sure if my logic is correct! Same goes for the other functions in this file...
Card* LinkedList::remove(Card* data){
   Node* current = head;
   //for (int i = 0; i < size; i++){
   //   if (current->getNext()->getData().compareByRank(*data) == 0){
   //      if (current->getNext()->getData().compareBySuit(*data) == 0){
   //         //check all files for validity of using delete!! (are they dynamically allocated/have destructors??)
   //         Node* ret = current->getNext();
   //         current->setNext(current->getNext()->getNext());
   //         return &ret->getData();
   //      }
   //      else {

   //      }
   //   }
   //}

   for (int i = 0; i < size; i++){
      if (current->getData().compareByRank(*data) == 0 && current->getData().compareBySuit(*data) == 0){
         break; //double check this, it's not finished yet...

      }
   }
   if (current->getData().compareByRank(*data) == 0 && current->getData().compareBySuit(*data) == 0){
      Node* old = current;
      current = current->getNext();
      Card* data = &old->getData();

   }
   return data;
}
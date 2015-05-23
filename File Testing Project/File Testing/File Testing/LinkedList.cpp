//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(NULL), tail(NULL), size(0) {}

LinkedList::LinkedList(LinkedList& otherList) { //copy constructor
   size = 0;
   int otherSize = otherList.size;
   for (int i = 0; i<otherSize; i++){
      insertAtTail(new Card(*otherList.getAtIndex(i)));
   }
}

Card* LinkedList::getHead(){
   if (head == NULL) return NULL;
   return head->getData();
}

Card* LinkedList::getTail(){
   if (tail == NULL) return NULL;
   return tail->getData();
}

Card* LinkedList::getAtIndex(int i){
   if (size == 0) return NULL;
   Node* current = head;
   for (int j = 0; j < i; j++){ //iterate to the ith node
      current = current->getNext();
   }
   return current->getData();
}

int LinkedList::getSize(){
   return size;
}

void LinkedList::insertAtHead(Card* data){
   Node* c = new Node(data);
   c->setNext(head);
   head = c;
   if (size == 0) tail = head;
   ++size;
}

void LinkedList::insertAtTail(Card* data){
   if (size == 0){
      insertAtHead(data);
      return;
   }
   tail->setNext(new Node(data));
   tail = tail->getNext();
   ++size;
}

bool LinkedList::insertAtIndex(Card* data, int index){
   if (index == 0){
      insertAtHead(data);
      return true;
   }

   else if (index < size){
      Node* current = head;
      for (int i = 0; i < index-1; ++i){
         current = current->getNext();
      }
      Node* insert = new Node(data, current->getNext());
      current->setNext(insert);
      ++size;
      return true;
   }
   
   else if (index == size){
      insertAtTail(data);
      return true;
   }

   else return false;
}

Card* LinkedList::removeAtHead(){
   Card* data = head->getData();
   head = head->getNext();
   --size;
   return data;
}

Card* LinkedList::removeAtTail(){
   if (size == 0) return NULL;
   Card* data = tail->getData();
   Node* current = head;
   for (int i = 0; i < size - 1; i++){
      current = current->getNext();
   }
   current->setNext(NULL);
   tail = current;
   --size;
   return data;
}

Card* LinkedList::removeAtIndex(int index){
   if (size == 0) return NULL;
   if (index == 0) return removeAtHead();
   if (index < 0 || index >= size){
      cerr << "Error: Invalid index.\n";
      return NULL;
   }
   if (index == size - 1) return removeAtTail();
   if (index < size - 1){
      Node* remove = head;
      Node* previous = head;
      for (int i = 0; i < size - 1; ++i){
         previous = previous->getNext();
      }
      remove = previous;
      remove = remove->getNext();
      previous->setNext(previous->getNext()->getNext());
      --size;
      return remove->getData();
   }
   return NULL;
}

Card* LinkedList::remove(Card* data){
   Node* current = head;
   int i = 0;
   while (i < size){
      if (current->getData()->compareByRank(*data) == 0 && current->getData()->compareBySuit(*data) == 0){
         break;
      }
      current = current->getNext();
      ++i;
   }
   if (i < size) return removeAtIndex(i);
   else return NULL;
}

bool LinkedList::contains(Card* data){
   Node* current = head;
   int i = 0;
   while (i < size){
      if (current->getData()->compareByRank(*data) == 0 && current->getData()->compareBySuit(*data) == 0){
         break;
      }
      current = current->getNext();
      ++i;
   }
   if (i < size) return 1;
   return 0;
}

int LinkedList::search(Card* data){ //returns -1 if not found, returns index if found
   Node* current = head;
   int i = 0;
   while (i < size){
      if (current->getData()->compareByRank(*data) == 0 && current->getData()->compareBySuit(*data) == 0){
         break;
      }
      current = current->getNext();
      ++i;
   }
   if (i < size) return i;
   return -1;
}

bool LinkedList::isEmpty(){
   if (size == 0) return 1;
   return 0;
}

const Card& LinkedList::operator [](int index){
   while (index < 0 || index >= size){
      cerr << "Error: Invalid index specified. Please try again.\n";
      cin >> index;
   }
   Node* current = head;
   for (int j = 0; j < index; j++){ //iterate to the ith node
      current = current->getNext();
   }
   return *current->getData();
}

ostream& operator <<(ostream& out, const LinkedList& list){
   Node* current = list.head;
   for (int i = 0; i < list.size; i++){
      out << *current->getData() << "\n";
      current = current->getNext();
   }
   return out;
}

LinkedList& LinkedList::operator = (const LinkedList& otherList){
   if (this != &otherList){
      Node* current = head;
      for (int i = 0; i < size; ++i){ //empty the destination list prior to filling w/ new data
         Node* next = current->getNext();
         delete current;
         current = next;
      }

      size = 0;
      int otherSize = otherList.size;
      current = otherList.head;
      for (int i = 0; i<otherSize; i++){
         insertAtTail(new Card(*current->getData()));
         current = current->getNext();
      }
   }
   return *this;
}

LinkedList::~LinkedList(){
   if (size != 0){
      Node* current = head;
      for (int i = 0; i < size; ++i){
         Node* next = current->getNext();
         delete current;
         current = next;
      }
   }
}
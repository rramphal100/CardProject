#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

Stack::Stack(){
	count = 0;
}

void Stack::push(Card c){
   if (!isFull){
       cards[count] = c;
       count++;
   }
   else cerr << "Stack is full!!!" << endl;
}

Card Stack::pop() {
    if (!isEmpty){
      count--;
      return cards[count];
    }
    
    cerr << "Stack is empty!" << endl;
    //return NULL;
}

Card Stack::peek(){
    if (!isEmpty){
       return cards[count-1];
    }
    
    cerr << "Stack is empty!!" << endl;
    
    //return NULL;
}

bool Stack::isEmpty(){
   return count == 0;
}

int Stack::getCount() {
   return count;
}

string Stack::display(){
   string s = "";
   
   for (int i=count-1; i>=0; i--){
       s = s + cards[i].display() + "\n";
   }
   
   return s;
}

ostream& operator <<(ostream& out, const Stack& s){
   for (int i = s.count-1; i>=0; i--){
      out << s.cards[i] << "\n";
   }
}
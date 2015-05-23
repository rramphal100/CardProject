#include <iostream>
#include "LinkedList.h"
#include "Card.h"

using namespace std;

int main(){
   LinkedList x;
   Card* a = new Card(3, 3);
   x.insertAtHead(a);
   cout << x << endl << endl;
   Card* b = new Card(2, 2);
   x.insertAtHead(b);
   cout << x << endl << endl;

   Card* c = new Card(0, 0);
   x.insertAtTail(c);
   cout << x[3] << endl;
   system("PAUSE");
   return 0;
}
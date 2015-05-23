#include <iostream>
#include "LinkedList.h"
#include "Card.h"
#include "Hand.h"

using namespace std;

int main(){
   Hand x;
   Card* a = new Card(8, 1);
  
   Card* b = new Card(0, 0);

   Card* c = new Card(2, 2);

   Card* d = new Card(10, 2);
   x.insertLast(b);
   x.insertLast(a);
   x.insertLast(c);
   x.insertByRank(d);
   cout << x.evaluate() << endl << endl;

   x.remove();
   cout << x << endl << endl;

   system("PAUSE");
   return 0;
}
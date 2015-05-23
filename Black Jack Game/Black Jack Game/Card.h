#ifndef CARD_H
#define CARD_H

#include<iostream>
using namespace std;

class Card
{
private:
   //suit is represented with values 0-3
   int suit;
   //rank is represented with values 0-12
   int rank;
   int value;
public:
   Card();
   Card(int, int);
   int getSuit();
   int getRank();
   void setSuit(int);
   void setRank(int);
   int compareByRank(const Card&);
   int compareBySuit(const Card&);
   string getRankAsString() const;
   string getSuitAsString() const;
   string display();
   friend ostream& operator <<(ostream&, const Card&);
};

#endif
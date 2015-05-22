//Ryan Ramphal, Anthony Paliseno, Toufiq Mahmud
//CS211
//Blackjack Project

#include "Node.h"

Node::Node()
{
   data = Card();
   next = NULL;
}

Node::Node(Card c)
{
   data = c;
   next = NULL;
}

Node::Node(Card c, Node* n)
{
   data = c;
   next = n;
}

void Node::setData(Card c)
{
   data = c;
}

Card Node::getData()
{
   return data;
}

void Node::setNext(Node* n)
{
   next = n;
}

Node* Node::getNext()
{
   return next;
}
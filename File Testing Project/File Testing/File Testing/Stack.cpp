#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

Stack::Stack()
{
   stack = new Card*[100];
   capacity = 100;
   count = 0;
}

Stack::Stack(int size)
{
   stack = new Card*[size];
   capacity = size;
   count = 0;
}

Stack::Stack(const Stack& other)
{
   count = 0;
   capacity = other.capacity;
   stack = new Card*[capacity];

   for (int i = 0; i < other.count; i++)
      this->push(*(other.stack[i]));
}

Stack::~Stack()
{
   for (int i = 0; i < count; i++)
      delete stack[i];

   delete[] stack;
}

int Stack::getCount()
{
   return count;
}

bool Stack::push(const Card& c)
{
   if (!isFull())
   {
      stack[count] = new Card(c);
      count++;
      return true;
   }

   cout << "Stack is full!!!";
   return false;
}

Card* Stack::pop()
{
   if (!isEmpty())
   {
      count--;
      return stack[count];
   }

   cout << "Stack is empty!!!";
   return NULL;
}

Card* Stack::peek()
{
   if (!isEmpty())
      return stack[count];

   cout << "Stack is empty!!!";
   return NULL;
}

bool Stack::isEmpty()
{
   return count == 0;
}

bool Stack::isFull()
{
   return count == capacity;
}

Stack& Stack::operator=(const Stack& other)
{
   if (this == &other)
      return *this;

   for (int i = 0; i < count; i++)
      delete stack[i];

   delete[] stack;

   count = other.count;
   capacity = other.capacity;
   stack = new Card*[capacity];

   for (int i = 0; i < count; i++)
      *stack[i] = *(other.stack[i]);

   return *this;
}

string Stack::display()
{
   string str = "";

   for (int i = count - 1; i >= 0; i--)
      str += stack[i]->display() + "\n";

   return str;
}

ostream& operator<<(ostream& out, const Stack& stack)
{
   for (int i = stack.count - 1; i >= 0; i--)
      out << *(stack.stack[i]) << endl;

   return out;
}

#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string, std::to_string, std::ifstream, std::stringstream, std::getline;

class Stack
{
private:
  Node *top;
  void push(string, int, string, string, string, int);

public:
  // Constructor functions
  Stack()
  {
    top = NULL;
  }

  // Mutator functions
  void createStack(string);
  string pop();

  // Accessor function
  string displayAll();
  string showHead();
  string showTail();
};

void Stack::push(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  if (top == NULL)
  {
    top = freshNode;
    return;
  }
  Node *previousTop = top;
  top = freshNode;
  top->setNext(previousTop);
  return;
}

string Stack::pop()
{
  if (top == NULL)
  {
    return "The Stack is empty!";
  }
  Node *previousTop = top;
  string str = "";
  top = top->getNext();
  str = previousTop->getData();
  delete previousTop;
  return str;
}

string Stack::displayAll()
{
  if (top == NULL)
    return "The Stack is empty!";
  string str = "";
  for (Node *ptr = top; ptr != NULL; ptr = ptr->getNext())
  {
    str.append(ptr->getData());
    str.append("\n");
  }
  return str;
}

string Stack::showHead()
{
  if (top == NULL)
    return "The Stack is empty!";
  else
    return top->getData();
}

string Stack::showTail()
{
  if (top == NULL) // The containeer is empty
    return "The Stack is empty!";
  // else
  Node *ptr = top;

  // Walk down the list
  while (ptr->getNext() != NULL)
  {
    ptr = ptr->getNext();
  }

  return (ptr->getData());
}

void Stack::createStack(string filePath)
{
  string str;
  char ch;
  string Month;
  int Year;
  string Artist;
  string SongTitle;
  string RecordLabel;
  int WeeksAtNumberOne;

  ifstream file(filePath);
  if (!file)
  {
    exit(EXIT_FAILURE);
    return;
  }
  getline(file, str);

  while (!file.eof() && getline(file, str))
  {
    stringstream line(str);
    getline(line, Month, '*');
    line >> Year;
    line >> ch;
    getline(line, Artist, '*');
    getline(line, SongTitle, '*');
    getline(line, RecordLabel, '*');
    line >> WeeksAtNumberOne;
    push(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  }
  return;
}

#endif
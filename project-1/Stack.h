#ifndef STACK_H
#define STACK_H
#include "Node.h"
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
  // Constructor function
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
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the stack is empty, add the node to the top of the
  // stack
  if (top == NULL)
  {
    top = freshNode;
    return;
  }
  // Case 2: If the stack is not empty, add the fresh Node to the
  // top of the stack
  Node *previousTop = top;
  top = freshNode;
  top->setNext(previousTop);
  return;
}

string Stack::pop()
{
  // Case 1: If the stack is empty
  if (top == NULL)
  {
    return "The Stack is empty!";
  }
  // Case 2: If the stack has only on Node remaining, remove
  // the top Node and set the top attribute to NULL
  if (top->getNext() == NULL)
  {
    Node *ptrTop = top;
    top = NULL;
    string str = ptrTop->getData();
    delete ptrTop;
    return str;
  }
  // Case 3: If the stack has more than one Node remaining,
  // remove the top Node and move the next Node to the top
  Node *previousTop = top;
  string str = "";
  top = top->getNext();
  str = previousTop->getData();
  delete previousTop;
  return str;
};

string Stack::displayAll()
{
  // Case 1: If the stack is empty
  if (top == NULL)
    return "The Stack is empty!";
  // Case 2: If the stack is not empty, append all the data from
  // each Node in the stack to a string
  string str = "";
  for (Node *ptr = top; ptr != NULL; ptr = ptr->getNext())
  {
    str.append(ptr->getData());
    str.append("\n");
  }
  return str;
};

string Stack::showHead()
{
  // Case 1: If the stack is empty
  if (top == NULL)
    return ("The Stack is empty!");
  // Case 2: If the stack is not empty, return
  // the data at the top of the stack
  else
    return (top->getData());
};

string Stack::showTail()
{
  // Case 1: If the stack is empty
  if (top == NULL)
    return "The Stack is empty!";
  // Case 2: If the stack is not empty,
  // iterate through the stack until we reach the end
  // and return the data at the end of the stack
  Node *ptr = top;
  for (; ptr->getNext() != NULL; ptr = ptr->getNext())
    ;
  return (ptr->getData());
};

void Stack::createStack(string filePath)
{
  ifstream file(filePath);
  string str;
  string Month;
  string Artist;
  string SongTitle;
  string RecordLabel;
  char ch;
  int Year;
  int WeeksAtNumberOne;
  // if the file is open by another resource or the file is not found
  if (!file)
  {
    exit(EXIT_FAILURE);
    return;
  }
  // reads the headings of the file
  getline(file, str);
  // iterate through each line and add the data to the stack
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
};
#endif
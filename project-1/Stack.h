#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Stack
{
private:
  // define the attributes of the Stack
  Node *head;

public:
  // Constructor function
  Stack()
  {
    head = NULL;
  }
  // Mutator functions
  string createStack(string);
  string loadFromFile(string);
  string pop();
  void push(string, int, string, string, string, int);
  void purge() { head = NULL; }; // remove all references of the Nodes in the Stack to then be deleted
  // Accessor function
  string displayAll();
  string showHead();
  string showTail();
  // returns the state of the Stack
  bool isEmpty() { return ((head == NULL) ? true : false); };
};

void Stack::push(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the stack is empty, add the node to the head of the
  // stack
  if (head == NULL)
  {
    head = freshNode;
    return;
  }
  // Case 2: If the stack is not empty, add the fresh Node to the
  // head of the stack
  Node *previousHead = head;
  head = freshNode;
  head->setNext(previousHead);
  return;
};

string Stack::pop()
{
  // Case 1: If the stack is empty
  if (head == NULL)
    return "The Stack is empty!";
  // Case 2: If the stack has more than one Node remaining,
  // remove the head Node and move the next Node to the head
  Node *previousHead = head;
  string str = "";
  head = head->getNext();
   // get the data from the head before the head is deleted
  str = previousHead->getData();
  delete previousHead;
  return (str);
};

string Stack::displayAll()
{
  // Case 1: If the stack is empty
  if (head == NULL)
    return "The Stack is empty!";
  // Case 2: If the stack is not empty, append all the data from
  // each Node in the stack to a string
  string str = "";
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
  {
    str.append(ptr->getData());
    str.append("\n");
  }
  // return the data in the Stack to be displayed
  return (str);
};

string Stack::showHead()
{
  // Case 1: If the stack is empty
  if (head == NULL)
    return ("The Stack is empty!");
  // Case 2: If the stack is not empty, return
  // the data at the head of the stack
  else
    return (head->getData());
};

string Stack::showTail()
{
  // Case 1: If the stack is empty
  if (head == NULL)
    return "The Stack is empty!";
  // Case 2: If the stack is not empty,
  // iterate through the stack until we reach the end
  // and return the data at the end of the stack
  Node *ptr = head;
  for (; ptr->getNext() != NULL; ptr = ptr->getNext())
    ;
  return (ptr->getData());
};

string Stack::loadFromFile(string filePath)
{
  // create a file to read from 
  ifstream file(filePath);
  // defines all the fields in the file
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
    return ("The file can not be opened!!");
  }
  // reads the headings of the file
  getline(file, str);
  // iterate through each line and read each line from the file into a string 
  while (!file.eof() && getline(file, str))
  {
    // create a stream to get all the fields from
    stringstream line(str);
    getline(line, Month, '*');
    line >> Year;
    line >> ch;
    getline(line, Artist, '*');
    getline(line, SongTitle, '*');
    getline(line, RecordLabel, '*');
    line >> WeeksAtNumberOne;
    // add the data to the Stack
    push(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  }
   // send a success message indicating that all the data was added to the Stack
  return ("The Stack was successfully created!!");
};

string Stack::createStack(string filePath)
{
// Case 1: If the Stack is not empty, purge the Stack
  // and load all the data from the filePath to the Stack
  if (!isEmpty())
  {
    // remove all Nodes from the Stack
    purge();
    return (loadFromFile(filePath));
  }
  // Case 2:  If the Stack is empty, load all the data
  // from the filePath to the Stack
  else
    return (loadFromFile(filePath));
};
#endif

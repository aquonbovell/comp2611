#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string, std::to_string, std::ifstream, std::stringstream, std::getline;

class Queue

{
private:
  Node *head;
  void enqueue(string, int, string, string, string, int);

public:
  // Constructor functions
  Queue() { head = NULL; }

  // Mutator functions
  void createQueue(string);
  string dequeue();

  // Accessor function
  string displayAll();
  string showHead();
  string showTail();
};

void Queue::enqueue(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the date from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);

  if (head == NULL)
    head = freshNode;
  else
  {
    Node *currentNode = head;
    for (; currentNode->getNext() != NULL; currentNode = currentNode->getNext())
      ;
    currentNode->setNext(freshNode);
    return;
  }
}

string Queue::dequeue()
{
  if (head == NULL)
    return "The Queue is empty!";
  if (head->getNext() == NULL)
  {
    Node *ptrHead = head;
    head = NULL;
    string str = ptrHead->getData();
    delete ptrHead;
    return str;
  }
  Node *ptrHead = head;
  head = head->getNext();
  string str = ptrHead->getData();
  delete ptrHead;
  return str;
}

string Queue::displayAll()
{
  if (head == NULL)
    return "The Queue is empty!";
  string str = "";
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
  {
    str.append(ptr->getData());
    str.append("\n");
  }
  return str;
}

string Queue::showHead()
{
  if (head == NULL)
    return "The Queue is empty!";
  else
    return head->getData();
}

string Queue::showTail()
{
  if (head == NULL) // The containeer is empty
    return "The Priority Queue is empty!";
  // else
  Node *ptr = head;

  // Walk down the list
  while (ptr->getNext() != NULL)
  {
    ptr = ptr->getNext();
  }

  return (ptr->getData());
}

void Queue::createQueue(string filePath)
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
    enqueue(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  }
  return;
}

#endif
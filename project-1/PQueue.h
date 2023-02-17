#ifndef PQUEUE_H
#define PQUEUE_H
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string, std::to_string, std::ifstream, std::stringstream, std::getline;

class PriorityQueue
{
private:
  Node *head;
  void insert(string, int, string, string, string, int);

public:
  // Constructor functions
  PriorityQueue() { head = NULL; }

  // Mutator functions
  void createPriorityQueue(string);
  string dequeue();

  // Accessor function
  string displayAll();
  string showHead();
  string showTail();
};

void PriorityQueue::insert(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the date from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);

  // Case 1: Is the list empty?
  if (head == NULL)
  {
    head = freshNode;
    return;
  }

  // Case 2: the new node should be the new first node
  if (freshNode->getWeeksAtNumberOne() > head->getWeeksAtNumberOne())
  {
    freshNode->setNext(head);
    head = freshNode;
    return;
  }

  // freshNode must be stored "somewhere" down the list
  Node *previous = head;
  Node *current = head->getNext();

  while (current != NULL && current->getWeeksAtNumberOne() >= freshNode->getWeeksAtNumberOne())
  {
    previous = current;
    current = current->getNext();
  }

  // Why did we stop iterating?
  if (current == NULL) // We are at the end of the list
  {
    previous->setNext(freshNode);
    return;
  }

  freshNode->setNext(current);
  previous->setNext(freshNode);
  return;
}

string PriorityQueue::dequeue()
{
  if (head == NULL)
    return "The Priority Queue is empty";
  // else
  Node *ptr = head;
  string str = head->getData();

  head = head->getNext();
  delete ptr;

  return str;
}

string PriorityQueue::displayAll()
{
  if (head == NULL)
    return "The Priority Queue is empty";
  // else
  Node *ptr = head;

  string str = "";

  while (ptr != NULL)
  {
    str.append(ptr->getData());
    str.append("\n");
    ptr = ptr->getNext();
  }

  return str;
}

string PriorityQueue::showHead()
{
  if (head == NULL)
    return "The Priority Queue is empty";
  // else
  return head->getData();
}

string PriorityQueue::showTail()
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

void PriorityQueue::createPriorityQueue(string filePath)
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
    insert(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  }
  return;
}
#endif
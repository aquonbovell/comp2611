#ifndef DEQUE_H
#define DEQUE_H
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::string, std::to_string, std::ifstream, std::stringstream, std::getline;

class Deque
{
private:
  Node *head;
  Node *tail;
  void enqueueHead(string, int, string, string, string, int);
  void enqueueTail(string, int, string, string, string, int);

public:
  // Constructor functions
  Deque()
  {
    head = NULL;
    tail = NULL;
  }

  // Mutator functions
  void createDeque(string);
  string dequeueHead();
  string dequeueTail();

  // Accessor function
  string displayAll();
  string showHead();
  string showTail();
};

void Deque::enqueueHead(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  if (head == NULL && tail == NULL)
  {
    head = freshNode;
    tail = freshNode;
    return;
  }
  else
  {
    Node *previousHead = head;
    head = freshNode;
    head->setNext(previousHead);
    return;
  }
}

void Deque::enqueueTail(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  if (head == NULL && tail == NULL)
  {
    head = freshNode;
    tail = freshNode;
    return;
  }
  else
  {
    Node *previousTail = tail;
    tail = freshNode;
    previousTail->setNext(tail);
    return;
  }
}

string Deque::dequeueHead()
{
  if (head == NULL)
    return "The Deque is empty!";
  if (head == tail)
  {
    Node *ptrHead = head;
    head = NULL;
    tail = NULL;
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

string Deque::dequeueTail()
{
  if (tail == NULL)
    return "The Deque is empty";
  if (tail == head)
  {
    Node *ptrTail = tail;
    head = NULL;
    tail = NULL;
    string str = ptrTail->getData();
    delete ptrTail;
    return str;
  }
  Node *currentNode = head;
  for (; currentNode->getNext() != tail; currentNode = currentNode->getNext())
    ;
  Node *ptrTail = tail;
  tail = currentNode;
  tail->setNext(NULL);
  string str = ptrTail->getData();
  delete ptrTail;
  return str;
}

string Deque::displayAll()
{

  if (head == NULL || tail == NULL)
    return "The Deqeue is empty!";
  else
  {
    string str = "";
    for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
    {
      str.append(ptr->getData());
      str.append("\n");
    }
    return str;
  }
}

string Deque::showHead()
{
  if (head == NULL)
    return "The Deqeue is empty!";
  else
    return head->getData();
}

string Deque::showTail()
{
  if (tail == NULL)
    return "The Deqeue is empty!";
  return (tail->getData());
}

void Deque::createDeque(string filePath)
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
    if (Year >= 1995 && Year <= 1999)
      enqueueHead(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
    else
      enqueueTail(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  }
  return;
}

#endif
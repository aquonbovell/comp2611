#ifndef DEQUE_H
#define DEQUE_H
#include "Node.h"
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
  void loadFromFile(string);
  string dequeueHead();
  string dequeueTail();
  void purge();
  // Accessor function
  string displayAll();
  bool isEmpty();
  string showHead();
  string showTail();
};

void Deque::enqueueHead(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the deque is empty, add the Node to the head
  // and tail of the deque
  if (head == NULL || tail == NULL)
  {
    head = freshNode;
    tail = freshNode;
    return;
  }
  // Case 2: If the deque is not empty, add the Node to the
  // head of the deque
  Node *previousHead = head;
  head = freshNode;
  head->setNext(previousHead);
  return;
};

void Deque::enqueueTail(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the deque is empty, add the node to the head of the
  // deque
  if (head == NULL || tail == NULL)
  {
    head = freshNode;
    tail = freshNode;
    return;
  }
  // Case 2: If the deque is not empty, add the Node to the
  // tail of the deque
  Node *previousTail = tail;
  tail = freshNode;
  previousTail->setNext(tail);
  return;
};

string Deque::dequeueHead()
{
  // Case 1: If the deque is empty
  if (head == NULL || tail == NULL)
    return "The Deque is empty!";
  // Case 2: If the deque has only one Node remaining, remove
  // the Node and set both the head and tail attribute to NULL
  if (head == tail)
  {
    Node *ptrHead = head;
    head = NULL;
    tail = NULL;
    string str = ptrHead->getData();
    delete ptrHead;
    return str;
  }
  // Case 3: If the deque has more than one Node remaining,
  // remove the head Node and move the next Node to the head
  Node *ptrHead = head;
  head = head->getNext();
  string str = ptrHead->getData();
  delete ptrHead;
  return (str);
};

string Deque::dequeueTail()
{
  // Case 1: If the deque is empty
  if (tail == NULL || head == NULL)
    return "The Deque is empty";
  // Case 2: If the deque has only one Node remaining, remove
  // the Node and set both the head and tail attribute to NULL
  if (tail == head)
  {
    Node *ptrTail = tail;
    head = NULL;
    tail = NULL;
    string str = ptrTail->getData();
    delete ptrTail;
    return (str);
  }
  // Case 3: If the deque has more than one Node remaining,
  // remove the tail Node and move the previous Node to the tail
  Node *currentNode = head;
  for (; currentNode->getNext() != tail; currentNode = currentNode->getNext())
    ;
  Node *ptrTail = tail;
  tail = currentNode;
  tail->setNext(NULL);
  string str = ptrTail->getData();
  delete ptrTail;
  return (str);
};

string Deque::displayAll()
{
  // Case 1: If the deque is empty
  if (head == NULL || tail == NULL)
    return "The Deqeue is empty!";
  // Case1: If the deque is not empty, append all the data
  // from each Node in the deque to a string
  string str = "";
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
  {
    str.append(ptr->getData());
    str.append("\n");
  }
  return (str);
};

string Deque::showHead()
{
  // Case 1: If the deque is empty
  if (head == NULL)
    return "The Deqeue is empty!";
  else
    // Case 2: If the deque is not empty, return the data
    // at the head
    return (head->getData());
};

string Deque::showTail()
{
  // Case 1: If the deque is empty
  if (tail == NULL)
    return "The Deqeue is empty!";
  // Case 2: If the deque is not empty, return the data
  // at the tail
  return (tail->getData());
};

void Deque::createDeque(string filePath)
{

  if (!isEmpty())
  {
    purge();
    loadFromFile(filePath);
    return;
  }
  else
  {
    loadFromFile(filePath);
    return;
  }
};

void Deque::loadFromFile(string filePath)
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
  // iterate through each line and add the data to the deque
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
};

bool Deque::isEmpty()
{
  return ((head == NULL || tail == NULL) ? true : false);
};

void Deque::purge()
{
  while (head != NULL)
  {
    dequeueHead();
  }
}
#endif
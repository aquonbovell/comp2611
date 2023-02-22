#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
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
  // Constructor function
  Queue() { head = NULL; }
  // Mutator functions
  void createQueue(string);
  void loadFromFile(string);
  string dequeue();
  void purge();
  // Accessor function
  bool isEmpty();
  string displayAll();
  string showHead();
  string showTail();
};

void Queue::enqueue(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the queue is empty, add the node to the head of the
  // queue
  if (head == NULL)
  {
    head = freshNode;
    return;
  }
  // Case 2: If the queue is not empty, add the fresh Node to the
  // end of the queue
  Node *currentNode = head;
  for (; currentNode->getNext() != NULL; currentNode = currentNode->getNext())
    ;
  currentNode->setNext(freshNode);
  return;
};

string Queue::dequeue()
{
  // Case 1: If the queue is empty
  if (head == NULL)
    return "The Queue is empty!";
  // Case 2: If the queue has more than one Node remaining,
  // remove the head Node and move the next Node to the head
  Node *ptrHead = head;
  head = head->getNext();
  string str = ptrHead->getData();
  delete ptrHead;
  return (str);
};

string Queue::displayAll()
{
  // Case 1: If the queue is empty
  if (head == NULL)
    return "The Queue is empty!";
  // Case 2: If the queue is not empty, append all the data from
  // each Node in the queue to a string
  string str = "";
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
  {
    str.append(ptr->getData());
    str.append("\n");
  }
  return (str);
};

string Queue::showHead()
{
  // Case 1: If the queue is empty
  if (head == NULL)
    return ("The Queue is empty!");
  // Case 2: If the queue is not empty, return
  // the data at the head of the queue
  else
    return (head->getData());
};

string Queue::showTail()
{
  // Case 1: If the queue is empty
  if (head == NULL)
    return "The Priority Queue is empty!";
  // Case 2: If the queue is not empty,
  // iterate through the queue until we reach the end
  // and return the data at the end of the queue
  Node *ptr = head;
  for (; ptr->getNext() != NULL; ptr = ptr->getNext())
    ;
  return (ptr->getData());
};

void Queue::createQueue(string filePath)
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

void Queue::loadFromFile(string filePath)
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
  // iterate through each line and add the data to the queue
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
};

bool Queue::isEmpty()
{
  return (head == NULL ? true : false);
};

void Queue::purge()
{
  while (head != NULL)
  {
    dequeue();
  }
};
#endif
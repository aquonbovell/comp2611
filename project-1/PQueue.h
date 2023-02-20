#ifndef PQUEUE_H
#define PQUEUE_H
#include "Node.h"
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
  // Constructor function
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
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the priority queue is empty, add the node to the head of the
  // priority queue
  if (head == NULL)
  {
    head = freshNode;
    return;
  }
  // Case 2: If the priority queue is not empty and the fresh Node
  // should be the new first Node
  if (freshNode->getWeeksAtNumberOne() > head->getWeeksAtNumberOne())
  {
    freshNode->setNext(head);
    head = freshNode;
    return;
  }
  // Case 3: If the priority queue is not empty and the fresh Node
  // must be stored "somewhere" down the list
  Node *previous = head;
  Node *current = head->getNext();
  while (current != NULL && current->getWeeksAtNumberOne() >= freshNode->getWeeksAtNumberOne())
  {
    previous = current;
    current = current->getNext();
  }
  // If the fresh Node is to stored at the end of the list
  if (current == NULL)
  {
    previous->setNext(freshNode);
    return;
  }
  // If the fresh Node is to stored somewhere within the list
  freshNode->setNext(current);
  previous->setNext(freshNode);
  return;
};

string PriorityQueue::dequeue()
{
  // Case 1: If the priority queue is empty
  if (head == NULL)
    return ("The Priority Queue is empty");
  // Case 2: If the priority queue has more than one Node remaining,
  // remove the head Node and move the next Node to the head
  Node *ptr = head;
  string str = head->getData();
  head = head->getNext();
  delete ptr;
  return str;
};

string PriorityQueue::displayAll()
{
  // Case 1: If the priority queue is empty
  if (head == NULL)
    return "The Priority Queue is empty";
  // Case 2: If the priority queue is not empty, append all the data from
  // each Node in the queue to a string
  string str = "";
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
  {
    str.append(ptr->getData());
    str.append("\n");
  }
  return str;
};

string PriorityQueue::showHead()
{
  // Case 1: If the priority queue is empty
  if (head == NULL)
    return ("The Queue is empty!");
  // Case 2: If the priority queue is not empty, return
  // the data at the head
  else
    return (head->getData());
};

string PriorityQueue::showTail()
{
  // Case 1: If the priority queue is empty, return
  // the data at the tail
  if (head == NULL)
    return "The Priority Queue is empty!";
  // Case 2: If the priority queue is not empty,
  // iterate through the queue until we reach the end
  // and return the data at the tail
  Node *ptr = head;
  for (; ptr->getNext() != NULL; ptr = ptr->getNext())
    ;
  return (ptr->getData());
};

void PriorityQueue::createPriorityQueue(string filePath)
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
    insert(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  }
  return;
};
#endif
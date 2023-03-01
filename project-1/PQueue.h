#ifndef PQUEUE_H
#define PQUEUE_H
#include "Node.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class PriorityQueue
{
private:
  // define the attributes of the Priority Queue
  Node *head;

public:
  // Constructor function
  PriorityQueue() { head = NULL; } // set the attributes to NULL
  // Mutator functions
  string loadFromFile(string);
  string createPriorityQueue(string);
  string dequeue();
  void insert(string, int, string, string, string, int);
  void purge() { head = NULL; }; // remove all references of the Nodes in the Priority Queue to then be deleted
  // Accessor function
  string displayAll();
  string showHead();
  string showTail();
  // returns the state of the Priority Queue
  bool isEmpty() { return (head == NULL ? true : false); };
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
  // iterate through the Priority Queue to reach where the new Node is
  // to be added
  while (current != NULL && current->getWeeksAtNumberOne() >= freshNode->getWeeksAtNumberOne())
  {
    previous = current;
    current = current->getNext();
  }
  // If the fresh Node is to be stored at the end of the list
  if (current == NULL)
  {
    previous->setNext(freshNode);
    return;
  }
  // If the fresh Node is to be stored somewhere within the list
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
  // get the data from the head before the head is deleted
  string str = head->getData();
  head = head->getNext();
  delete ptr;
  return (str);
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
    // append each data from each Node in the Priority Queue to a single string
    str.append(ptr->getData());
    str.append("\n");
  }
  // return the data in the Priority Queue to be displayed
  return (str);
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
  // iterate through the Priority Queue to reach the last Node in the Priority Queue
  for (; ptr->getNext() != NULL; ptr = ptr->getNext())
    ;
  return (ptr->getData());
};

string PriorityQueue::createPriorityQueue(string filePath)
{
  // Case 1: If the Priority Queue is not empty, purge the Priority Queue
  // and load all the data from the filePath to the Priority Queue
  if (!isEmpty())
  {
    // remove all Nodes from the Priority Queue
    purge();
    return (loadFromFile(filePath));
  }
  // Case 2:  If the Priority Queue is empty, load all the data
  // from the filePath to the Priority Queue
  else
    return (loadFromFile(filePath));
};

string PriorityQueue::loadFromFile(string filePath)
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
    // add the data to the Priority Queue
    insert(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  }
  // send a success message indicating that all the data was added to the Priority Queue
  return ("The Priority Queue was successfully created!!");
}
#endif

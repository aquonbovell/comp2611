#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Queue
{
private:
  // define the attributes of the Queue
  Node *head;

public:
  // Constructor function
  Queue() { head = NULL; } // set the attributes to NULL
  // Mutator functions
  string createQueue(string);
  string loadFromFile(string);
  string dequeue();
  void enqueue(string, int, string, string, string, int);
  void purge() { head = NULL; }; // remove all references of the Nodes in the Queue to then be deleted
  // Accessor function
  string displayAll();
  string showHead();
  string showTail();
  // returns the state of the Deque
  bool isEmpty() { return ((head == NULL) ? true : false); };
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
  // iterate through the Queue to reach the end of the Queue
  for (; currentNode->getNext() != NULL; currentNode = currentNode->getNext())
    ;
  // add the Node to the end of the Queue
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
  // get the data from the head before the head is deleted
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
    // append each data from each Node in the Queue to a single string
    str.append(ptr->getData() + "\n");
  }
  // return the data in the Priority Queue to be displayed
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

string Queue::createQueue(string filePath)
{
  // Case 1: If the Queue is not empty, purge the Queue
  // and load all the data from the filePath to the Queue
  if (!isEmpty())
  {
    // remove all Nodes from the Queue
    purge();
    return (loadFromFile(filePath));
  }
  // Case 2:  If the Queue is empty, load all the data
  // from the filePath to the Queue
  else
    return (loadFromFile(filePath));
};

string Queue::loadFromFile(string filePath)
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
    // add the data to the Queue
    enqueue(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  }
  // send a success message indicating that all the data was added to the Queue
  return ("The Queue was successfully created!!");
};
#endif

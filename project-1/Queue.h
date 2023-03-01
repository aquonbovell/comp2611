#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <fstream>
#include <string>

using namespace std;

class Queue
{
private:
  // define the attributes of the Queue
  Node *head_;

public:
  // Constructor function
  Queue() : head_(NULL) {} // set the attribute to NULL
  // Mutator functions
  // This method takes a string as input and creates a Queue from the string. The string is expected to contain a series of asterisk-separated values, with each value representing the data for a node in the Queue.
  string createQueue(const string &);
  // This method takes a filename as input and loads a Queue from a file. The file is expected to contain a series of comma-separated values, with each value representing the data for a node in the Queue.
  string loadFromFile(const string &);
  // This method removes the head node from the Queue and returns its data.
  string dequeue();
  // This method creates a new node with the given data and inserts it at the head of the Queue.
  void enqueue(const string &, int, const string &, const string &, const string &, int);
  // This method removes all nodes from the Queue.
  void purge() { head_ = NULL; };
  // Accessor functions
  // This method returns a string representation of the Queue, with each node's data separated by a newline character
  string displayAll() const;
  // This method returns the data of the head node without removing it.
  string showHead() const;
  // This method returns the data of the tail node without removing it.
  string showTail() const;
  // This method returns true if the Queue is empty, and false otherwise.
  const bool isEmpty() const { return ((head_ == NULL) ? true : false); };
};

void Queue::enqueue(const string &Month, int Year, const string &Artist, const string &SongTitle, const string &RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the queue is empty, add the node to the head of the
  // queue
  if (head_ == NULL)
  {
    head_ = freshNode;
    return;
  }
  // Case 2: If the queue is not empty, add the fresh Node to the
  // end of the queue
  Node *currentNode = head_;
  // iterate through the Queue to reach the end of the Queue
  for (; currentNode->get_next() != NULL; currentNode = currentNode->get_next())
    ;
  // add the Node to the end of the Queue
  currentNode->set_next(freshNode);
  return;
};

string Queue::dequeue()
{
  // Case 1: If the queue is empty
  if (head_ == NULL)
    return "The Queue is empty!!";
  // Case 2: If the queue has more than one Node remaining,
  // remove the head Node and move the next Node to the head
  Node *ptrHead = head_;
  head_ = head_->get_next();
  // get the data from the head before the head is deleted
  string str = ptrHead->get_data();
  delete ptrHead;
  return (str);
};

string Queue::displayAll() const
{
  // Case 1: If the queue is empty
  if (head_ == NULL)
    return "The Queue is empty!!";
  // Case 2: If the queue is not empty, append all the data from
  // each Node in the queue to a string
  string str = "";
  for (Node *ptr = head_; ptr != NULL; ptr = ptr->get_next())
  {
    // append each data from each Node in the Queue to a single string
    str.append(ptr->get_data() + "\n");
  }
  // return the data in the Queue to be displayed
  return (str);
};

string Queue::showHead() const
{
  // Case 1: If the queue is empty
  if (head_ == NULL)
    return ("The Queue is empty!!");
  // Case 2: If the queue is not empty, return
  // the data at the head of the queue
  return (head_->get_data());
};

string Queue::showTail() const
{
  // Case 1: If the queue is empty
  if (head_ == NULL)
    return "The Queue is empty!!";
  // Case 2: If the queue is not empty,
  // iterate through the queue until we reach the end
  // and return the data at the end of the queue
  Node *ptr = head_;
  for (; ptr->get_next() != NULL; ptr = ptr->get_next())
    ;
  return (ptr->get_data());
};

string Queue::createQueue(const string &filePath)
{
  // Clear the Queue to prepare for loading new data
  purge();
  // Load all the data from the file to the Queue
  return (loadFromFile(filePath));
};

string Queue::loadFromFile(const string &filePath)
{
  // create a file to read from
  ifstream file(filePath);
  if (!file.is_open()) // check if the file was opened successfully
    return ("The file can not be opened!!");
  // defines all the fields in the file
  string header;
  string newlinechar;
  string month;
  string artist;
  string songtitle;
  string recordLabel;
  char separator;
  int year;
  int weeksatnumberone;
  // Read the first line to skip the header
  getline(file, header);
  // iterate through each line and parse the fields from the file
  while (getline(file, month, '*') &&
         file >> year &&
         file >> separator &&
         getline(file, artist, '*') &&
         getline(file, songtitle, '*') &&
         getline(file, recordLabel, '*') &&
         file >> weeksatnumberone && getline(file, newlinechar, '\n'))
  {
    // add the data to the Queue
    enqueue(month, year, artist, songtitle, recordLabel, weeksatnumberone);
  }
  // send a success message indicating that all the data was added to the Queue
  return ("The Queue was successfully created!!");
};
#endif

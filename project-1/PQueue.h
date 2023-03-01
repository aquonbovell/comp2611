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
  Node *head_;

public:
  // Constructor function
  PriorityQueue() : head_(NULL) {} // set the attribute to NULL
  // Mutator functions
  // This method takes a string as input and creates a Priority Queue from the string. The string is expected to contain a series of asterisk-separated values, with each value representing the data for a node in the Priority Queue.
  const string createPriorityQueue(const string &);
  // This method takes a filename as input and loads a Priority Queue from a file. The file is expected to contain a series of comma-separated values, with each value representing the data for a node in the Priority Queue.
  const string loadFromFile(const string &);
  // This method removes the head node from the Priority Queue and returns its data.
  const string dequeue();
  // This method creates a new node with the given data and inserts it at the head of the Priority Queue.
  void insert(const string &, int, const string &, const string &, const string &, int);
  // This method removes all nodes from the Priority Queue.
  void purge() { head_ = NULL; };
  // Accessor functions
  // This method returns a string representation of the Priority Queue, with each node's data separated by a newline character
  const string displayAll() const;
  // This method returns the data of the head node without removing it.
  const string showHead() const;
  // This method returns the data of the tail node without removing it.
  const string showTail() const;
  // This method returns true if the Priority Queue is empty, and false otherwise.
  const bool isEmpty() const { return ((head_ == NULL) ? true : false); };
};

void PriorityQueue::insert(const string &Month, int Year, const string &Artist, const string &SongTitle, const string &RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the priority queue is empty, add the node to the head of the
  // priority queue
  if (head_ == NULL)
  {
    head_ = freshNode;
    return;
  }
  // Case 2: If the priority queue is not empty and the fresh Node
  // should be the new first Node
  if (freshNode->get_weeks_at_number_one() > head_->get_weeks_at_number_one())
  {
    freshNode->set_next(head_);
    head_ = freshNode;
    return;
  }
  // Case 3: If the priority queue is not empty and the fresh Node
  // must be stored "somewhere" down the list
  Node *previous = head_;
  Node *current = head_->get_next();
  // iterate through the Priority Queue to reach where the new Node is
  // to be added
  while (current != NULL && current->get_weeks_at_number_one() >= freshNode->get_weeks_at_number_one())
  {
    previous = current;
    current = current->get_next();
  }
  // If the fresh Node is to be stored at the end of the list
  if (current == NULL)
  {
    previous->set_next(freshNode);
    return;
  }
  // If the fresh Node is to be stored somewhere within the list
  freshNode->set_next(current);
  previous->set_next(freshNode);
  return;
};

const string PriorityQueue::dequeue()
{
  // Case 1: If the priority queue is empty
  if (head_ == NULL)
    return ("The Priority Queue is empty");
  // Case 2: If the priority queue has more than one Node remaining,
  // remove the head Node and move the next Node to the head
  Node *ptr = head_;
  // get the data from the head before the head is deleted
  string str = head_->get_data();
  head_ = head_->get_next();
  delete ptr;
  return (str);
};

const string PriorityQueue::displayAll() const
{
  // Case 1: If the priority queue is empty
  if (head_ == NULL)
    return "The Priority Queue is empty";
  // Case 2: If the priority queue is not empty, append all the data from
  // each Node in the queue to a string
  string str = "";
  for (Node *ptr = head_; ptr != NULL; ptr = ptr->get_next())
  {
    // append each data from each Node in the Priority Queue to a single string
    str.append(ptr->get_data() + "\n");
  }
  // return the data in the Priority Queue to be displayed
  return (str);
};

const string PriorityQueue::showHead() const
{
  // Case 1: If the priority queue is empty
  if (head_ == NULL)
    return ("The Queue is empty!");
  // Case 2: If the priority queue is not empty, return
  // the data at the head
  else
    return (head_->get_data());
};

const string PriorityQueue::showTail() const
{
  // Case 1: If the priority queue is empty, return
  // the data at the tail
  if (head_ == NULL)
    return "The Priority Queue is empty!";
  // Case 2: If the priority queue is not empty,
  // iterate through the queue until we reach the end
  // and return the data at the tail
  Node *ptr = head_;
  // iterate through the Priority Queue to reach the last Node in the Priority Queue
  for (; ptr->get_next() != NULL; ptr = ptr->get_next())
    ;
  return (ptr->get_data());
};

const string PriorityQueue::createPriorityQueue(const string &filePath)
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
  return (loadFromFile(filePath));
};

const string PriorityQueue::loadFromFile(const string &filePath)
{
  ifstream file(filePath);
  if (!file.is_open()) // check if the file was opened successfully
    return ("The file could not be opened.");
  string line;
  string month;
  string artist;
  string songTitle;
  string recordLabel;
  char separator;
  int year;
  int weeksAtNumberOne;
  // Read the first line to skip the header
  getline(file, line);
  // Read each line of the file
  while (getline(file, line))
  {
    // Create a stringstream from the line
    stringstream ss(line);
    // Parse the fields from the line
    getline(ss, month, '*');
    ss >> year;
    ss >> separator;
    getline(ss, artist, '*');
    getline(ss, songTitle, '*');
    getline(ss, recordLabel, '*');
    ss >> weeksAtNumberOne;
    // add the data to the Priority Queue
    insert(month, year, artist, songTitle, recordLabel, weeksAtNumberOne);
  }
  // Close the file
  file.close();
  return ("The Deque was successfully created!");
}
#endif

// ==================================================================================
//
//  Queue.h
//  COMP2611 - Project #1 - 417002714
//
//  Created by Aquon Bovell on 02/15/2023
//  © 2023 Aquon Bovell. All rights reserved
//
// ==================================================================================
#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <fstream>

using std::ifstream;

// defines the blueprint of the Queue
class Queue
{
private:
  // the attributes of the Queue
  Node *head_;

public:
  // Constructor function

    // default constructor - set attributes values to their default values
  Queue() : head_(NULL) {}

  // Mutator functions
  
  // This method takes a string which represents a file path and creates
  // a Queue from that file. The file is expected to contain a series of
  // asterisk-separated values, with each value representing the data 
  // for a node in the Queue.
  const string createQueue(const string &);
  // This method removes the node from the head of the Queue and
  // returns its data.
  const string dequeue();
  // This method creates a new node with the data from the fields of the
  // file opened and adds the node to the Queue
  void enqueue(const string &, int, const string &, const string &, const string &, int);
  // This method removes all nodes from the Queue.
  void purge() { head_ = NULL; };

  // Accessor functions

  // This method returns a string representation of the Queue,
  // with each node's data separated by a newline character
  const string displayAll() const;
  // This method returns the data of the head node without removing it.
  const string showHead() const;
  // This method returns the data of the tail node without removing it.
  const string showTail() const;
  // This method returns true if the Queue is empty, and false otherwise.
  const bool isEmpty() const { return ((head_ == NULL) ? true : false); };
};

void Queue::enqueue(const string &Month, int Year, const string &Artist, const string &SongTitle, const string &RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
   // Case 1: If the Queue is empty, add the new Node to the head
  // of the Queue
  if (head_ == NULL)
  {
    head_ = freshNode;
    return;
  }
  // Case 2: If the Queue is not empty, add the new Node to the 
  // end of the Queue
  Node *currentNode = head_;
  // iterate through the Queue to reach the end of the Queue
  for (; currentNode->get_next() != NULL; currentNode = currentNode->get_next())
    ;
  // makee the old tail Node point to the new tail Node
  currentNode->set_next(freshNode);
  return;
};

const string Queue::dequeue()
{
  // Case 1: If the Queue is empty, return a message indicating
  // that the Queue is empty
  if (head_ == NULL)
    return "The Queue is empty!!";
  // Case 2: If the Queue has more than one Node remaining,
  // remove the head Node and move the Node after the head
  // to the head of the  Queue
  Node *ptrHead = head_;
  // move the next Node to the head of the Queue
  head_ = head_->get_next();
  // grab the data from the head Node before it is deleted
  string str = ptrHead->get_data();
  delete ptrHead;
  return (str);
};

const string Queue::displayAll() const
{
  // Case 1: If the Queue is empty, return a message indicating
  // that the Queue is empty
  if (head_ == NULL)
    return "The Queue is empty!!";
  // Case 2: If the Queue is not empty, append all the data
  // from each Node in the Queue to a string

  // a container to hold all the data in the Queue
  string str = "";
  // iterate through the Queue
  for (Node *ptr = head_; ptr != NULL; ptr = ptr->get_next())
  {
    // append the data from each Node in the Queue to a single string
    str.append(ptr->get_data() + "\n");
  }
  return (str);
};

const string  Queue::showHead() const
{
  // Case 1: If the Queue is empty, return a message indicating
  // that the Queue is empty
  if (head_ == NULL)
    return ("The Queue is empty!!");
  // Case 2: If the Queue is not empty, return
  // the data at the head of the Queue
  return (head_->get_data());
};

const string Queue::showTail() const
{
  // Case 1: If the Queue is empty, return a message indicating
  // that the Queue is empty
  if (head_ == NULL)
    return "The Queue is empty!";
  // Case 2: If the Queue is not empty,
  // iterate through the queue until we reach the end
  // and return the data at the tail of the Queue
  Node *ptr = head_;
  // iterate through the Queue to reach the last Node in the Queue
  for (; ptr->get_next() != NULL; ptr = ptr->get_next())
    ;
  return (ptr->get_data());
};

const string Queue::createQueue(const string & filePath)
{
  // Clear the Queue to prepare for loading new data
  purge();

  // create a file to read from
  ifstream file(filePath);
  // check if the file was opened successfully
  if (!file.is_open()) 
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

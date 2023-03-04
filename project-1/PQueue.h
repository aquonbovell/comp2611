// ==================================================================================
//
//  PQueue.h
//  COMP2611 - Project #1 - 417002714
//
//  Created by Aquon Bovell on 02/15/2023
//  © 2023 Aquon Bovell. All rights reserved
//
// ==================================================================================
#ifndef PQUEUE_H
#define PQUEUE_H
#include "Node.h"
#include <fstream>

using std::ifstream;

// defines the blueprint of the Priority Queue
class PriorityQueue
{
private:
  // the attributes of the Priority Queue
  Node *head_;

public:
  // Constructor function

  // default constructor - set attributes values to their default values
  PriorityQueue() : head_(NULL) {}
  // Mutator functions

  // This method takes a string which represents a file path and creates
  // a Priority Queue from that file. The file is expected to contain a
  // series of asterisk-separated values, with each value representing
  // the data for a node in the Priority Queue.
  const string createPriorityQueue(const string &);
  // This method removes the node from the head of the Priority Queue and
  // returns its data.
  const string dequeue();
  // This method creates a new node with the data from the fields of the
  // file opened and inserts the node into the Priority Queue to maintain
  // priority - sorted by weeks_at_number_one_ in descending order
  void insert(const string &, int, const string &, const string &, const string &, int);
  // This method removes all nodes from the Priority Queue.
  void purge() { head_ = NULL; };

  // Accessor functions

  // This method returns a string representation of the Priority Queue,
  // with each node's data separated by a newline character
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
  // Case 1: If the Prority Queue is empty, add the new Node to the head
  // of the Prority Queue
  if (head_ == NULL)
  {
    head_ = freshNode;
    return;
  }
  // Case 2: If the Priority queue is not empty and the new Node
  // should be the new first Node
  if (freshNode->get_weeks_at_number_one() > head_->get_weeks_at_number_one())
  {
    // make the new head Node to point to the old head Node
    freshNode->set_next(head_);
    // make the new Node the head od the Priority Queue
    head_ = freshNode;
    return;
  }
  // Case 3: If the Priority Queue is not empty and the new Node
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
  // If the new Node is to be added to the end of the list
  if (current == NULL)
  {
    // make the old tail Node point to the new tail Node
    previous->set_next(freshNode);
    return;
  }
  // If the new Node is to be stored somewhere within the list
  // make the new Node point to the Node after where the new Node is inserted
  freshNode->set_next(current);
  // make the Node before where the new Node is inserted point to it
  previous->set_next(freshNode);
  return;
};

const string PriorityQueue::dequeue()
{
  // Case 1: If the Priority Queue is empty, return a message indicating
  // that the Priority Queue is empty
  if (head_ == NULL)
    return ("The Priority Queue is empty!!");
  // Case 2: If the priority queue has more than one Node remaining,
  // remove the head Node and move the Node after the head
  // to the head of the Priority Queue
  Node *ptr = head_;
  // grab the data from the head Node before it is deleted
  string str = head_->get_data();
  // move the next Node to the head of the Priority Queue
  head_ = head_->get_next();
  delete ptr;
  return (str);
};

const string PriorityQueue::displayAll() const
{
  // Case 1: If the Priority Queue is empty, return a message indicating
  // that the Priority Queue is empty
  if (head_ == NULL)
    return "The Priority Queue is empty!!";
  // Case 2: If the Priority Queue is not empty, append all the data
  // from each Node in the Priority Queue to a string

  // a container to hold all the data in the Priority Queue
  string str = "";
  // iterate through the Priority Queue
  for (Node *ptr = head_; ptr != NULL; ptr = ptr->get_next())
  {
    // append the data from each Node in the Priority Queue to a single string
    str.append(ptr->get_data() + "\n");
  }
  return (str);
};

const string PriorityQueue::showHead() const
{
  // Case 1: If the Priority Queue is empty, return a message indicating
  // that the Priority Queue is empty
  if (head_ == NULL)
    return ("The Priority Queue is empty!!");
  // Case 2: If the Priority Queue is not empty, return
  // the data at the head of the Priority Queue
  return (head_->get_data());
};

const string PriorityQueue::showTail() const
{
  // Case 1: If the Priority Queue is empty, return a message indicating
  // that the Priority Queue is empty
  if (head_ == NULL)
    return "The Priority Queue is empty!";
  // Case 2: If the Priority Queue is not empty,
  // iterate through the queue until we reach the end
  // and return the data at the tail of the Priority Queue
  Node *ptr = head_;
  // iterate through the Priority Queue to reach the last Node in the Priority Queue
  for (; ptr->get_next() != NULL; ptr = ptr->get_next())
    ;
  return (ptr->get_data());
};

const string PriorityQueue::createPriorityQueue(const string &filePath)
{
  // Clear the Priority Queue to prepare for loading new data
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
    // insert the data into the Priority Queue
    insert(month, year, artist, songtitle, recordLabel, weeksatnumberone);
  }
  // send a success message indicating that all the data was added to the Priority Queue
  return ("The Priority Queue was successfully created!!");
};
#endif

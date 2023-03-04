// ==================================================================================
//
//  Deeque.h
//  COMP2611 - Project #1 - 417002714
//
//  Created by Aquon Bovell on 02/15/2023
//  © 2023 Aquon Bovell. All rights reserved
//
// ==================================================================================
#ifndef DEQUE_H
#define DEQUE_H
#include "Node.h"
#include <fstream>

using std::ifstream;

// defines the blueprint of the Deque
class Deque
{
private:
  // the attributes of the Deque
  Node *head_;
  Node *tail_;

public:
  // Constructor functions

  // default constructor - set attributes values to their default values
  Deque() : head_(NULL), tail_(NULL) {}

  // Mutator functions

  // This method takes a string which represents a file path and creates
  // a deque from that file. The file is expected to contain a series of
  // asterisk-separated values, with each value representing the data
  // for a node in the deque.
  const string createDeque(const string &);
  // This method removes the node from the head of the deque and returns 
  // its data.
  const string dequeueHead();
  // This method removes the node from the tail of the deque and returns 
  // its data.
  const string dequeueTail();
  // This method creates a new node with the data from the fields of the
  // file opened and inserts the node at the head of the deque.
  void enqueueHead(const string &, int, const string &, const string &, const string &, int);
  /// This method creates a new node with the data from the fields of the
  // file opened and inserts the node at the tail of the deque.
  void enqueueTail(const string &, int, const string &, const string &, const string &, int);
  // This method removes all nodes from the deque.
  void purge()
  {
    head_ = NULL;
    tail_ = NULL;
  };

  // Accessor functions

  // This method returns a string representation of the deque, with each
  // node's data separated by a newline character
  const string displayAll() const;
  // This method returns the data of the head node without removing it.
  const string showHead() const;
  // This method returns the data of the tail node without removing it.
  const string showTail() const;
  // This method returns true if the deque is empty, and false otherwise.
  const bool isEmpty() const { return ((head_ == NULL || tail_ == NULL) ? true : false); };
};

void Deque::enqueueHead(const string &Month, int Year, const string &Artist, const string &SongTitle, const string &RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the deque is empty, add the new Node to the head
  // and tail of the deque
  if (head_ == NULL || tail_ == NULL)
  {
    head_ = freshNode;
    tail_ = freshNode;
    return;
  }
  // Case 2: If the deque is not empty, add the new Node to the
  // head of the deque
  Node *previousHead = head_;
  head_ = freshNode;
  // make the new head Node to point to the old head Node
  head_->set_next(previousHead);
  return;
}

void Deque::enqueueTail(const string &Month, int Year, const string &Artist, const string &SongTitle, const string &RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the deque is empty, add the new Node to the tail
  // and tail of the deque
  if (head_ == NULL || tail_ == NULL)
  {
    head_ = freshNode;
    tail_ = freshNode;
    return;
  }
  // Case 2: If the deque is not empty, add the new Node to the
  // tail of the deque
  Node *previousTail = tail_;
  tail_ = freshNode;
  // make the old tail Node to point to the new tail Node
  previousTail->set_next(tail_);
  return;
}

const string Deque::dequeueHead()
{
  // Case 1: If the deque is empty, return a message indicating
  // that the deque is empty
  if (head_ == NULL || tail_ == NULL)
    return ("The Deque is empty!!");
  // Case 2: If the deque has only one Node remaining, remove
  // the Node and set both the head and tail attribute to NULL
  if (head_ == tail_)
  {
    Node *ptrHead = head_;
    // set the attributes to NULL to remove the last Node reference
    head_ = NULL;
    tail_ = NULL;
    // grab the data from the head before the head is deleted
    string str = ptrHead->get_data();
    delete ptrHead;
    return (str);
  }
  // Case 3: If the deque has more than one Node remaining,
  // remove the head Node and move the Node after the head
  // to the top of the Deque
  Node *ptrHead = head_;
  // move the next Node to the head of the Deque
  head_ = head_->get_next();
  // grab the data from the head Node before it is deleted
  string str = ptrHead->get_data();
  delete ptrHead;
  return (str);
}

const string Deque::dequeueTail()
{
  // Case 1: If the deque is empty, return a message indicating
  // that the deque is empty
  if (tail_ == NULL || head_ == NULL)
    return ("The Deque is empty!!");
  // Case 2: If the deque has only one Node remaining, remove
  // the Node and set both the head and tail attribute to NULL
  if (tail_ == head_)
  {
    Node *ptrTail = tail_;
    // set the attributes to NULL to remove the last Node reference
    head_ = NULL;
    tail_ = NULL;
    // grab the data from the tail before the tail is deleted
    string str = ptrTail->get_data();
    delete ptrTail;
    return (str);
  }
  // Case 3: If the deque has more than one Node remaining,
  // remove the tail Node and move the Node before the tail
  // to the end of the Deque
  Node *currentNode = head_;
  // iterate through the Deque to reach the second to last Node in the Deque
  for (; currentNode->get_next() != tail_; currentNode = currentNode->get_next())
    ;
  Node *ptrTail = tail_;
  tail_ = currentNode;
  // set the new tail's next attribute to NULL, as the tail is the last Node
  tail_->set_next(NULL);
  // grab the data from the tail Node before it is deleted
  string str = ptrTail->get_data();
  delete ptrTail;
  return (str);
}

const string Deque::displayAll() const
{
  // Case 1: If the deque is empty, return a message indicating
  // that the deque is empty
  if (head_ == NULL || tail_ == NULL)
    return ("The Deque is empty!!");
  // Case 2: If the deque is not empty, append all the data 
  // from each Node in the Deque to a string

  // a container to hold all the data in the Deque
  string str = "";
  // iterate through the Deque
  for (Node *ptr = head_; ptr != NULL; ptr = ptr->get_next())
  {
    // append the data from each Node in the Deque to the container string
    str.append(ptr->get_data() + "\n");
  }
  return (str);
}

const string Deque::showHead() const
{
  // Case 1: If the deque is empty, return a message indicating
  // that the deque is empty
  if (head_ == NULL)
    return ("The Deqeue is empty!!");
  // Case 2: If the deque is not empty, return the data
  // at the head of the Deque
  return (head_->get_data());
}

const string Deque::showTail() const
{
  // Case 1: If the deque is empty, return a message indicating
  // that the deque is empty
  if (tail_ == NULL)
    return ("The Deqeue is empty!!");
  // Case 2: If the deque is not empty, return the data
  // at the tail of the Deque
  return (tail_->get_data());
}

const string Deque::createDeque(const string &filePath)
{
  // Clear the deque to prepare for loading new data from
  // filePath
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
    // add the data to the Deque if within range
    if (year >= 1995 && year <= 1999)
      enqueueHead(month, year, artist, songtitle, recordLabel, weeksatnumberone);
    // add the data to the Deque if within range
    else if (year >= 1990 && year <= 1994)
      enqueueTail(month, year, artist, songtitle, recordLabel, weeksatnumberone);
  }
  // send a success message indicating that all the data was added to the Deque
  return ("The Deque was successfully created!!");
}
#endif

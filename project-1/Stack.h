// ==================================================================================
//
//  Stack.h
//  COMP2611 - Project #1 - 417002714
//
//  Created by Aquon Bovell on 02/15/2023
//  © 2023 Aquon Bovell. All rights reserved
//
// ==================================================================================
#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <fstream>

using std::ifstream;

// defines the blueprint of the Stack
class Stack
{
private:
  // the attributes of the Stack
  Node *head_;

public:
  // Constructor function

  // default constructor - set attributes values to their default values
  Stack() : head_(NULL) {}

  // Mutator functions

  // This method takes a string which represents a file path and creates
  // a Stack from that file. The file is expected to contain a
  // series of asterisk-separated values, with each value representing
  // the data for a node in the Stack.
  const string createStack(const string &);
  // This method removes the node from the head of the Stack and
  // returns its data.
  const string pop();
  // This method creates a new node with the data from the fields of the
  // file opened and pushs the node onto the Stack
  void push(const string &, int, const string &, const string &, const string &, int);
  // This method removes all nodes from the Stack.
  void purge() { head_ = NULL; };

  // Accessor functions

  // This method returns a string representation of the Stack,
  // with each node's data separated by a newline character
  const string displayAll() const;
  // This method returns the data of the head node without removing it.
  const string showHead() const;
  // This method returns the data of the tail node without removing it.
  const string showTail() const;
  // This method returns true if the Stack is empty, and false otherwise.
  const bool isEmpty() const { return ((head_ == NULL) ? true : false); };
};

void Stack::push(const string &Month, int Year, const string &Artist, const string &SongTitle, const string &RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the Stack is empty, add the new Node to the head
  // of the Stack
  if (head_ == NULL)
  {
    head_ = freshNode;
    return;
  }
  // Case 2: If the Stack is not empty, push the fresh Node onto the
  // head of the Stack
  Node *previousHead = head_;
  head_ = freshNode;
  // make the new Node the head of the Stack and point to the old
  // head Node
  head_->set_next(previousHead);
  return;
};

const string Stack::pop()
{
  // Case 1: If the Stack is empty, return a message indicating
  // that the Stack is empty
  if (head_ == NULL)
    return "The Stack is empty!!";
  // Case 2: If the stack has more than one Node remaining,
  // remove the head Node and move the Node after the head
  // to the head of the Stack
  Node *previousHead = head_;
  string str = "";
  // move the next Node to the head of the Stack
  head_ = head_->get_next();
  // grab the data from the head Node before it is deleted
  str = previousHead->get_data();
  delete previousHead;
  return (str);
};

const string Stack::displayAll() const
{
  // Case 1: If the Stack is empty, return a message indicating
  // that the Stack is empty
  if (head_ == NULL)
    return "The Stack is empty!!";
  // Case 2: If the Stack is not empty, append all the data
  // from each Node in the Stack to a string

  // a container to hold all the data in the Stack
  string str = "";
  // iterate through the Stack
  for (Node *ptr = head_; ptr != NULL; ptr = ptr->get_next())
  {
    // append the data from each Node in the Stack to a single string
    str.append(ptr->get_data() + "\n");
  }
  return (str);
};

const string Stack::showHead() const
{
  // Case 1: If the Stack is empty, return a message indicating
  // that the Stack is empty
  if (head_ == NULL)
    return ("The Stack is empty!!");
  // Case 2: If the Stack is not empty, return
  // the data at the head of the Stack
  return (head_->get_data());
};

const string Stack::showTail() const
{
  // Case 1: If the Stack is empty, return a message indicating
  // that the Stack is empty
  if (head_ == NULL)
    return "The Stack is empty!!";
  // Case 2: If the Stack is not empty,
  // iterate through the queue until we reach the end
  // and return the data at the tail of the Stack
  Node *ptr = head_;
  // iterate through the Stack to reach the last Node in the Stack
  for (; ptr->get_next() != NULL; ptr = ptr->get_next())
    ;
  return (ptr->get_data());
};

const string Stack::createStack(const string &filePath)
{
  // Clear the Stack to prepare for loading new data
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
    // push the data onto the Stack
    push(month, year, artist, songtitle, recordLabel, weeksatnumberone);
  }
  // send a success message indicating that all the data was added to the Stack
  return ("The Stack was successfully created!!");
};
#endif

#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <fstream>
#include <string>

using namespace std;

class Stack
{
private:
  // define the attributes of the Stack
  Node *head_;

public:
  // Constructor function
  Stack() : head_(NULL) {}
  // Mutator functions
  // Mutator functions
  // This method takes a string as input and creates a Stack from the string. The string is expected to contain a series of asterisk-separated values, with each value representing the data for a node in the Stack.
  string createStack(const string &);
  // This method takes a filename as input and loads a Stack from a file. The file is expected to contain a series of comma-separated values, with each value representing the data for a node in the Stack.
  string loadFromFile(const string &);
  // This method removes the head node from the Stack and returns its data.
  string pop();
  // This method creates a new node with the given data and inserts it at the head of the Stack.
  void push(const string &, int, const string &, const string &, const string &, int);
  // This method removes all nodes from the Stack.
  void purge() { head_ = NULL; };
  // Accessor functions
  // This method returns a string representation of the Stack, with each node's data separated by a newline character
  string displayAll() const;
  // This method returns the data of the head node without removing it.
  string showHead() const;
  // This method returns the data of the tail node without removing it.
  string showTail() const;
  // This method returns true if the Stack is empty, and false otherwise.
  const bool isEmpty() const { return ((head_ == NULL) ? true : false); };
};

void Stack::push(const string &Month, int Year, const string &Artist, const string &SongTitle, const string &RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the stack is empty, add the node to the head of the
  // stack
  if (head_ == NULL)
  {
    head_ = freshNode;
    return;
  }
  // Case 2: If the stack is not empty, add the fresh Node to the
  // head of the stack
  Node *previousHead = head_;
  head_ = freshNode;
  head_->set_next(previousHead);
  return;
};

string Stack::pop()
{
  // Case 1: If the stack is empty
  if (head_ == NULL)
    return "The Stack is empty!!";
  // Case 2: If the stack has more than one Node remaining,
  // remove the head Node and move the next Node to the head
  Node *previousHead = head_;
  string str = "";
  head_ = head_->get_next();
  // get the data from the head before the head is deleted
  str = previousHead->get_data();
  delete previousHead;
  return (str);
};

string Stack::displayAll() const
{
  // Case 1: If the stack is empty
  if (head_ == NULL)
    return "The Stack is empty!!";
  // Case 2: If the stack is not empty, append all the data from
  // each Node in the stack to a string
  string str = "";
  for (Node *ptr = head_; ptr != NULL; ptr = ptr->get_next())
  {
    str.append(ptr->get_data() + "\n");
  }
  // return the data in the Stack to be displayed
  return (str);
};

string Stack::showHead() const
{
  // Case 1: If the stack is empty
  if (head_ == NULL)
    return ("The Stack is empty!!");
  // Case 2: If the stack is not empty, return
  // the data at the head of the stack
  return (head_->get_data());
};

string Stack::showTail() const
{
  // Case 1: If the stack is empty
  if (head_ == NULL)
    return "The Stack is empty!!";
  // Case 2: If the stack is not empty,
  // iterate through the stack until we reach the end
  // and return the data at the end of the stack
  Node *ptr = head_;
  for (; ptr->get_next() != NULL; ptr = ptr->get_next())
    ;
  return (ptr->get_data());
};

string Stack::loadFromFile(const string &filePath)
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
    // add the data to the Stack
    push(month, year, artist, songtitle, recordLabel, weeksatnumberone);
  }
  // send a success message indicating that all the data was added to the Stack
  return ("The Stack was successfully created!!");
};

string Stack::createStack(const string &filePath)
{
  // Clear the Stack to prepare for loading new data
  purge();
  // Load all the data from the file to the Stack
  return (loadFromFile(filePath));
};
#endif

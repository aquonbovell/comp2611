#ifndef DEQUE_H
#define DEQUE_H
#include "Node.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Deque
{
private:
  // define the attributes of the Deque
  Node *head_;
  Node *tail_;

public:
  // Constructor functions
  Deque() : head_(NULL), tail_(NULL) {} // set the attributes to NULL
  // Mutator functions
  // This method takes a string as input and creates a deque from the string. The string is expected to contain a series of asterisk-separated values, with each value representing the data for a node in the deque.
  const string createDeque(const string &);
  // This method takes a filename as input and loads a deque from a file. The file is expected to contain a series of comma-separated values, with each value representing the data for a node in the deque.
  const string loadFromFile(const string &);
  // This method removes the head node from the deque and returns its data.
  const string dequeueHead();
  // This method removes the tail node from the deque and returns its data
  const string dequeueTail();
  // This method creates a new node with the given data and inserts it at the head of the deque.
  void enqueueHead(const string &, int, const string &, const string &, const string &, int);
  // This method creates a new node with the given data and inserts it at the tail of the deque.
  void enqueueTail(const string &, int, const string &, const string &, const string &, int);
  // This method removes all nodes from the deque.
  void purge()
  {
    head_ = NULL;
    tail_ = NULL;
  };
  // Accessor functions
  // This method returns a string representation of the deque, with each node's data separated by a newline character
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
  // Case 1: If the deque is empty, add the Node to the head
  // and tail of the deque
  if (head_ == NULL || tail_ == NULL)
  {
    head_ = freshNode;
    tail_ = freshNode;
    return;
  }
  // Case 2: If the deque is not empty, add the Node to the
  // head of the deque
  Node *previousHead = head_;
  head_ = freshNode;
  head_->set_next(previousHead);
  return;
}

void Deque::enqueueTail(const string &Month, int Year, const string &Artist, const string &SongTitle, const string &RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the deque is empty, add the node to the head of the
  // deque
  if (head_ == NULL || tail_ == NULL)
  {
    head_ = freshNode;
    tail_ = freshNode;
    return;
  }
  // Case 2: If the deque is not empty, add the Node to the
  // tail of the deque
  Node *previousTail = tail_;
  tail_ = freshNode;
  previousTail->set_next(tail_);
  return;
}

const string Deque::dequeueHead()
{
  // Case 1: If the deque is empty
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
    // get the data from the head before the head is deleted
    string str = ptrHead->get_data();
    delete ptrHead;
    return (str);
  }
  // Case 3: If the deque has more than one Node remaining,
  // remove the head Node and move the next Node to the head
  Node *ptrHead = head_;
  head_ = head_->get_next();
  // get the data from the head before the head is deleted
  string str = ptrHead->get_data();
  delete ptrHead;
  return (str);
}

const string Deque::dequeueTail()
{
  // Case 1: If the deque is empty
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
    // get the data from the tail before the tail is deleted
    string str = ptrTail->get_data();
    delete ptrTail;
    return (str);
  }
  // Case 3: If the deque has more than one Node remaining,
  // remove the tail Node and move the previous Node to the tail
  Node *currentNode = head_;
  // iterate through the Deque to reach the last Node in the Deque
  for (; currentNode->get_next() != tail_; currentNode = currentNode->get_next())
    ;
  Node *ptrTail = tail_;
  tail_ = currentNode;
  // set the tail next attribute to NULL, as the tail is the last Node
  tail_->set_next(NULL);
  // get the data from the tail before the tail is deleted
  string str = ptrTail->get_data();
  delete ptrTail;
  return (str);
}

const string Deque::displayAll() const
{
  // Case 1: If the deque is empty
  if (head_ == NULL || tail_ == NULL)
    return ("The Deque is empty!!");
  // Case1: If the deque is not empty, append all the data
  // from each Node in the deque to a string
  string str = "";
  // iterate through the Deque
  for (Node *ptr = head_; ptr != NULL; ptr = ptr->get_next())
  {
    // append each data from each Node in the Deque to a single string
    str.append(ptr->get_data() + "\n");
  }
  // return the data in the Deque to be displayed
  return (str);
}

const string Deque::showHead() const
{
  // Case 1: If the deque is empty
  if (head_ == NULL)
    return ("The Deqeue is empty!!");
  // Case 2: If the deque is not empty, return the data
  // at the head
  return (head_->get_data());
}

const string Deque::showTail() const
{
  // Case 1: If the deque is empty
  if (tail_ == NULL)
    return ("The Deqeue is empty!!");
  // Case 2: If the deque is not empty, return the data
  // at the tail
  return (tail_->get_data());
}

const string Deque::createDeque(const string &filePath)
{
  // Case 1: If the Deque is not empty, purge the Deque
  // and load all the data from the filePath to the Deque
  if (!isEmpty())
  {
    // remove all Nodes from the Deque
    purge();
    return (loadFromFile(filePath));
  }
  // Case 2:  If the Deque is empty, load all the data
  // from the filePath to the Deque
  return (loadFromFile(filePath));
}

const string Deque::loadFromFile(const string &filePath)
{
  ifstream file(filePath);
  if (!file.is_open()) // check if the file was opened successfully
    return ("The file could not be opened.");
  string str;
  string month;
  string artist;
  string songTitle;
  string recordLabel;
  char separator;
  char newline;
  int year;
  int weeksAtNumberOne;
  // Read the first line to skip the header
  // getline(file, month);
  // Read each line of the file
  // reads the headings of the file
  getline(file, str);
  // iterate through each line and read each line from the file into a string
  while (getline(file, month, '*') && file >> year && file >> separator && getline(file, artist, '*') &&
         getline(file, songTitle, '*') &&
         getline(file, recordLabel, '*') &&
         file >> weeksAtNumberOne && getline(file, separator))
  {
    // create a stream to get all the fields from
    // stringstream line(str);
    // getline(file, month, '*');
    // file >> year;
    // file >> separator;
    // getline(file, artist, '*');
    // getline(file, songTitle, '*');
    // getline(file, recordLabel, '*');
    // file >> weeksAtNumberOne;
    // Add the data to the deque based on the year
    if (year >= 1995 && year <= 1999)
      enqueueHead(month, year, artist, songTitle, recordLabel, weeksAtNumberOne);
    else if (year >= 1990 && year <= 1994)
      enqueueTail(month, year, artist, songTitle, recordLabel, weeksAtNumberOne);
  }
  // Close the file
  file.close();
  return ("The Deque was successfully created!");
}
#endif

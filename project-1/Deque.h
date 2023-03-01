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
  Node *head;
  Node *tail;

public:
  // Constructor functions
  Deque()
  {
    // set the attributes to NULL
    head = NULL;
    tail = NULL;
  }
  // Mutator functions
  string createDeque(string);
  string loadFromFile(string);
  string dequeueHead();
  string dequeueTail();
  void enqueueHead(string, int, string, string, string, int);
  void enqueueTail(string, int, string, string, string, int);
  void purge()
  {
    // remove all references of the Nodes in the Deque
    // to then be deleted
    head = NULL;
    tail = NULL;
  };
  // Accessor function
  string displayAll();
  string showHead();
  string showTail();
  // returns the state of the Deque
  bool isEmpty() { return ((head == NULL || tail == NULL) ? true : false); };
};

void Deque::enqueueHead(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the deque is empty, add the Node to the head
  // and tail of the deque
  if (head == NULL || tail == NULL)
  {
    head = freshNode;
    tail = freshNode;
    return;
  }
  // Case 2: If the deque is not empty, add the Node to the
  // head of the deque
  Node *previousHead = head;
  head = freshNode;
  head->setNext(previousHead);
  return;
}

void Deque::enqueueTail(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  // Create the new node with the data from the parameter list
  Node *freshNode = new Node(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  // Case 1: If the deque is empty, add the node to the head of the
  // deque
  if (head == NULL || tail == NULL)
  {
    head = freshNode;
    tail = freshNode;
    return;
  }
  // Case 2: If the deque is not empty, add the Node to the
  // tail of the deque
  Node *previousTail = tail;
  tail = freshNode;
  previousTail->setNext(tail);
  return;
}

string Deque::dequeueHead()
{
  // Case 1: If the deque is empty
  if (head == NULL || tail == NULL)
    return "The Deque is empty!";
  // Case 2: If the deque has only one Node remaining, remove
  // the Node and set both the head and tail attribute to NULL
  if (head == tail)
  {
    Node *ptrHead = head;
    // set the attributes to NULL to remove the last Node reference
    head = NULL;
    tail = NULL;
    // get the data from the head before the head is deleted
    string str = ptrHead->getData();
    delete ptrHead;
    return str;
  }
  // Case 3: If the deque has more than one Node remaining,
  // remove the head Node and move the next Node to the head
  Node *ptrHead = head;
  head = head->getNext();
  // get the data from the head before the head is deleted
  string str = ptrHead->getData();
  delete ptrHead;
  return (str);
}

string Deque::dequeueTail()
{
  // Case 1: If the deque is empty
  if (tail == NULL || head == NULL)
    return "The Deque is empty!";
  // Case 2: If the deque has only one Node remaining, remove
  // the Node and set both the head and tail attribute to NULL
  if (tail == head)
  {
    Node *ptrTail = tail;
    // set the attributes to NULL to remove the last Node reference
    head = NULL;
    tail = NULL;
    // get the data from the tail before the tail is deleted
    string str = ptrTail->getData();
    delete ptrTail;
    return (str);
  }
  // Case 3: If the deque has more than one Node remaining,
  // remove the tail Node and move the previous Node to the tail
  Node *currentNode = head;
  // iterate through the Deque to reach the last Node in the Deque
  for (; currentNode->getNext() != tail; currentNode = currentNode->getNext())
    ;
  Node *ptrTail = tail;
  tail = currentNode;
  // set the tail next attribute to NULL, as the tail is the last Node
  tail->setNext(NULL);
  // get the data from the tail before the tail is deleted
  string str = ptrTail->getData();
  delete ptrTail;
  return (str);
}

string Deque::displayAll()
{
  // Case 1: If the deque is empty
  if (head == NULL || tail == NULL)
    return "The Deqeue is empty!";
  // Case1: If the deque is not empty, append all the data
  // from each Node in the deque to a string
  string str = "";
  // iterate through the Deque
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
  {
    // append each data from each Node in the Deque to a single string
    str.append(ptr->getData() + "\n");
  }
  // return the data in the Deque to be displayed
  return (str);
}

string Deque::showHead()
{
  // Case 1: If the deque is empty
  if (head == NULL)
    return "The Deqeue is empty!";
  else
    // Case 2: If the deque is not empty, return the data
    // at the head
    return (head->getData());
}

string Deque::showTail()
{
  // Case 1: If the deque is empty
  if (tail == NULL)
    return "The Deqeue is empty!";
  // Case 2: If the deque is not empty, return the data
  // at the tail
  return (tail->getData());
}

string Deque::createDeque(string filePath)
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
  else
    return (loadFromFile(filePath));
}

string Deque::loadFromFile(string filePath)
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
    // add the data to the front if the year is between 1995 and 1999
    if (Year >= 1995 && Year <= 1999)
      enqueueHead(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
    // add the data to the back if the year is between 1990 and 1994
    else
      enqueueTail(Month, Year, Artist, SongTitle, RecordLabel, WeeksAtNumberOne);
  }
  // send a success message indicating that all the data was added to the Deque
  return ("The Deque was successfully created!!");
}
#endif

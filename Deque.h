#ifndef DEQUE_H
#define DEQUE_H
#include <string>
using std::string;

class Node
{
private:
  string Value;
  Node *next;

public:
  // Constructor
  Node();
  Node(string);

  // Mutator functions
  void setName(string Vx) { Value = Vx; }
  void setNext(Node *ptr) { next = ptr; }

  // Accessor functions
  string getName() { return Value; }
  Node *getNext() { return next; }
};

Node::Node()
{
  Value = "";
  next = NULL;
}

Node::Node(string Vx)
{
  Value = Vx;
  next = NULL;
}

class Deque
{
private:
  Node *head;
  Node *tail;

public:
  // Constructor functions
  Deque()
  {
    head = NULL;
    tail = NULL;
  }

  // Mutator functions
  void enqueueHead(string);
  void enqueueTail(string);
  string dequeueHead();
  string dequeueTail();

  // Accessor function
  bool find(string);
  string getAllData();
  string getFront();
  string getBack();
  bool isEmpty();
  int size();
};

void Deque::enqueueHead(string label)
{
  Node *freshNode = new Node(label);
  if (head == NULL && tail == NULL)
  {
    head = freshNode;
    tail = freshNode;
    return;
  }
  else
  {
    Node *previousHead = head;
    head = freshNode;
    head->setNext(previousHead);
    return;
  }
}

void Deque::enqueueTail(string label)
{
  Node *freshNode = new Node(label);
  if (head == NULL && tail == NULL)
  {
    head = freshNode;
    tail = freshNode;
    return;
  }
  else
  {
    Node *previousTail = tail;
    tail = freshNode;
    previousTail->setNext(tail);
    return;
  }
}

string Deque::dequeueHead()
{
  if (head == NULL)
    return "The Deque is empty!";
  if (head == tail)
  {
    Node *ptrHead = head;
    head = NULL;
    tail = NULL;
    string str = ptrHead->getName();
    delete ptrHead;
    return str;
  }
  Node *ptrHead = head;
  head = head->getNext();
  string str = ptrHead->getName();
  delete ptrHead;
  return str;
}

string Deque::dequeueTail()
{
  if (tail == NULL)
    return "The Deque is empty";
  if (tail == head)
  {
    Node *ptrTail = tail;
    head = NULL;
    tail = NULL;
    string str = ptrTail->getName();
    delete ptrTail;
    return str;
  }
  Node *currentNode = head;
  for (; currentNode->getNext() != tail; currentNode = currentNode->getNext())
    ;
  Node *ptrTail = tail;
  tail = currentNode;
  tail->setNext(NULL);
  string str = ptrTail->getName();
  delete ptrTail;
  return str;
}

bool Deque::find(string val)
{
  if (head == NULL)
  {
    return false;
  }
  else
  {
    for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
      if (ptr->getName().compare(val) == 0)
        return true;
    return false;
  }
}

string Deque::getAllData()
{

  if (head == NULL || tail == NULL)
    return "The Deqeue is empty!";
  else
  {
    string str = "";
    for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
    {
      str.append(ptr->getName());
      str.append("\n");
    }
    return str;
  }
}

string Deque::getFront()
{
  if (head == NULL)
    return "The Deqeue is empty!";
  else
    return head->getName();
}

string Deque::getBack()
{
  if (tail == NULL)
    return "The Deqeue is empty!";
  return (tail->getName());
}

bool Deque::isEmpty()
{
  return (head == NULL ? true : false);
}

int Deque::size()
{
  int count = 0;
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
    count++;
  return count;
}

#endif
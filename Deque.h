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
  void addToHead(string);
  string deleteHead();
  void addToTail(string);
  string deleteTail();

  // Accessor function
  string getAllData();
  string getFront();
  string getBack();
  int count();
  bool find(string);
};

void Deque::addToHead(string label)
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
  }
}

void Deque::addToTail(string label)
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

string Deque::deleteHead()
{
  if (head == NULL)
    return "The Deque is empty";

  if (head == tail)
  {
    Node *ptrHead = head;
    head = NULL;
    tail = NULL;
    // grab data from ptrHead and return it
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

string Deque::deleteTail()
{
  if (tail == NULL)
    return "The Deque is empty";

  if (tail == head)
  {
    Node *ptrTail = tail;
    tail = NULL;
    string str = ptrTail->getName();
    delete ptrTail;

    return str;
  }
  Node *currentNode = head;
  for (; currentNode->getNext() != tail; currentNode = currentNode->getNext())
  {
  }

  Node *ptrTail = tail;
  tail = currentNode;
  tail->setNext(NULL);
  string str = ptrTail->getName();
  delete ptrTail;
  return str;
}

bool Deque::find(string val)
{
  bool result;
  if (val.compare(tail->getName()) == 0)
    result = true;
  else
  {
    for (Node *ptr = head; ptr != tail; ptr = ptr->getNext())
    {
      if (ptr->getName().compare(val) == 0)
      {
        result = true;
      }
      else
        result = false;
    }
  }
  return result;
}

string Deque::getFront()
{
  if (head == NULL)
    return "The Deqeue is empty!";
  // else
  return head->getName();
}

string Deque::getBack()
{
  if (tail == NULL) // The containeer is empty
    return "The Deqeue is empty!";
  // else
  return (tail->getName());
}

string Deque::getAllData()
{
  string str = "";
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
  {
    str.append(ptr->getName());
    str.append("\n");
  }
  return str;
}

int Deque::count()
{
  int count = 0;
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
  {
    count++;
  }
  return count;
}

#endif

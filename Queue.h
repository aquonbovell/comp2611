#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
using std::string, std::to_string;

class Node
{
private:
  int idNo;
  string name;
  float gpa;
  Node *next;

public:
  // Constructor
  Node();
  Node(int, string, float);

  // Mutator functions
  void setIDNo(int value) { idNo = value; }
  void setName(string label) { name = label; }
  void setGPA(float num) { gpa = num; }
  void setNext(Node *ptr) { next = ptr; }

  // Accessor functions
  string getData();
  int getIDNo() { return idNo; }
  string getName() { return name; }
  float getGPA() { return gpa; }
  Node *getNext() { return next; }
};

Node::Node()
{
  idNo = -9999;
  name = "";
  gpa = 0.0;
  next = NULL;
};

Node::Node(int num, string label, float grade)
{
  idNo = num;
  name = label;
  gpa = grade;
  next = NULL;
};

string Node::getData()
{
  string str = "";
  str.append(to_string(idNo));
  str.append("\t");
  str.append(name);
  str.append("\t");
  str.append(to_string(gpa));
  return str;
};

class Queue
{
private:
  Node *head;

public:
  // Constructor functions
  Queue() { head = NULL; }

  // Mutator functions
  void enqueue(int, string, float);
  string dequeue();

  // Accessor function
  string getAllData();
  string getFront();
  int size();
  bool isEmpty();
};

void Queue::enqueue(int num, string label, float grade)
{
  if (head == NULL)
    head = new Node(num, label, grade);
  else
  {
    Node *currentNode = head;
    for (; currentNode->getNext() != NULL; currentNode = currentNode->getNext())
      ;
    currentNode->setNext(new Node(num, label, grade));
    return;
  }
}

string Queue::dequeue()
{
  if (head == NULL)
    return "The Queue is empty!";
  if (head->getNext() == NULL)
  {
    Node *ptrHead = head;
    head = NULL;
    string str = ptrHead->getName();
    delete ptrHead;
    return str;
  }
  Node *ptrHead = head;
  head = head->getNext();
  string str = ptrHead->getData();
  delete ptrHead;
  return str;
}

string Queue::getAllData()
{
  if (head == NULL)
    return "The Queue is empty!";
  string str = "";
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
  {
    str.append(ptr->getData());
    str.append("\n");
  }
  return str;
}

bool Queue::isEmpty()
{
  if (head == NULL)
    return false;
  return true;
}

string Queue::getFront()
{
  if (head == NULL)
    return "The Queue is empty!";
  else
    return head->getData();
}

int Queue::size()
{
  if (head == NULL)
    return 0;
  int count = 0;
  for (Node *ptr = head; ptr != NULL; ptr = ptr->getNext())
    count++;
  return count;
}

#endif
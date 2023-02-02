#ifndef PQUEUE_H
#define PQUEUE_H
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
}

Node::Node(int num, string label, float grade)
{
  idNo = num;
  name = label;
  gpa = grade;
  next = NULL;
}

string Node::getData()
{
  string str = "";

  str.append(to_string(idNo));
  str.append("\t");
  str.append(name);
  str.append("\t");
  str.append(to_string(gpa));

  return str;
}

class PriorityQueue
{
private:
  Node *head;

public:
  // Constructor functions
  PriorityQueue() { head = NULL; }

  // Mutator functions
  void insert(int, string, float);
  string dequeue();

  // Accessor function
  string getAllData();
  string getFront();
  string getLast();
  bool find(int);
};

void PriorityQueue::insert(int num, string label, float score)
{
  // Create the new node with the date from the parameter list
  Node *temp = new Node(num, label, score);

  // Case 1: Is the list empty?
  if (head == NULL)
  {
    head = temp;
    return;
  }

  // Case 2: the new node should be the new first node
  if (temp->getIDNo() < head->getIDNo())
  {
    temp->setNext(head);
    head = temp;
    return;
  }

  // temp must be stored "somewhere" down the list
  Node *previous = head;
  Node *current = head->getNext();

  while (current != NULL && current->getIDNo() < temp->getIDNo())
  {
    previous = current;
    current = current->getNext();
  }

  // Why did we stop iterating?
  if (current == NULL) // We are at the end of the list
  {
    previous->setNext(temp);
    return;
  }

  temp->setNext(current);
  previous->setNext(temp);
  return;
}

string PriorityQueue::dequeue()
{
  if (head == NULL)
    return "The Priority Queue is empty";
  // else
  Node *ptr = head;
  string str = head->getData();

  head = head->getNext();
  delete ptr;

  return str;
}

string PriorityQueue::getAllData()
{
  if (head == NULL)
    return "The Priority Queue is empty";
  // else
  Node *ptr = head;

  string str = "";

  while (ptr != NULL)
  {
    str.append(ptr->getData());
    str.append("\n");
    ptr = ptr->getNext();
  }

  return str;
}

string PriorityQueue::getFront()
{
  if (head == NULL)
    return "The Priority Queue is empty";
  // else
  return head->getData();
}

string PriorityQueue::getLast()
{
  if (head == NULL) // The containeer is empty
    return "The Priority Queue is empty!";
  // else
  Node *ptr = head;

  // Walk down the list
  while (ptr->getNext() != NULL)
  {
    ptr = ptr->getNext();
  }

  return (ptr->getData());
}

bool PriorityQueue::find(int val)
{
  Node *ptr = head;

  for (; ptr != NULL && ptr->getIDNo() != val && ptr->getIDNo() < val; ptr = ptr->getNext())
    ;

  if (ptr->getIDNo() == val)
    return true;
  else
    return false;
}
#endif
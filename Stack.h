#ifndef STACK_H
#define STACK_H
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

class Stack
{
private:
  Node *top;

public:
  // Constructor functions
  Stack()
  {
    top = NULL;
  }

  // Mutator functions
  void push(string);
  string pop();

  // Accessor function
  string getAllData();
  bool isEmpty();
  int size();
};

void Stack::push(string label)
{
  if (top == NULL)
  {
    top = new Node(label);
    return;
  }
  Node *previousTop = top;
  top = new Node(label);
  top->setNext(previousTop);
  return;
}

string Stack::pop()
{
  if (top == NULL)
  {
    return "The Stack is empty!";
  }
  Node *previousTop = top;
  string str = "";
  top = top->getNext();
  str = previousTop->getName();
  delete previousTop;
  return str;
}

string Stack::getAllData()
{
  if (top == NULL)
    return "The Stack is empty!";
  string str = "";
  for (Node *ptr = top; ptr != NULL; ptr = ptr->getNext())
  {
    str.append(ptr->getName());
    str.append("\n");
  }
  return str;
}

bool Stack::isEmpty(){
  if(top==NULL)
    return true;
  return false;
}

int Stack::size(){
  if(top== NULL)
    return 0;
  int count = 0;
  for (Node *ptr = top; ptr != NULL; ptr = ptr->getNext())
    count++;
  return count;
}

#endif
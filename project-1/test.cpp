#include "Queue.h"
// #include "Stack.h"
#include <iostream>

int main(){
  Queue *d = new Queue();
  d->createQueue("../catalog.txt");
  d->dequeue();
  d->dequeue();
  d->dequeue();
  d->dequeue();
  d->dequeue();
  d->dequeue();
  d->dequeue();
  d->dequeue();
  d->dequeue();
  d->dequeue();
  d->dequeue();
  d->dequeue();
  std::cout<<d->displayAll();
}
#include "Queue.h"
#include <iostream>

int main()
{
  Queue *q = new Queue();
  q->enqueue("Jan", 1900, "Buju", "Sometime", "Jam Rock", 6);
  q->displayAll();
  q->enqueue("Jan", 1900, "Buju", "Sometime", "Jam Rock", 6);
  q->displayAll();
  q->enqueue("Jan", 1900, "Buju", "Sometime", "Jam Rock", 6);
  q->displayAll();
}
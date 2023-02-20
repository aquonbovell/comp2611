#include "Deque.h"
// #include "Stack.h"
#include <iostream>

int main(){
  Deque *d = new Deque();
  d->createDeque("catalog.txt");
  std::cout<<d->displayAll();
}
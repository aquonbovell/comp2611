#include "Deque.h"
#include <iostream>

int main(){
  Deque *dq = new Deque();
  std::cout<<dq->createDeque("catalog.txt");
  dq->enqueueHead("Jan", 1332, "Bubu", "Song", "Jam Rock", 14);
  std::cout<<dq->displayAll();
  return 0;
}

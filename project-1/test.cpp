#include "Deque.h"
#include <iostream>

int main(){
  Deque *dq = new Deque();
  dq->enqueueHead("Jan", 1332, "Bubu", "Song", "Jam Rock", 14);
  dq->enqueueHead("Jan", 32, "Bubu", "Song", "Jam Rock", 14);
  std::cout<<dq->displayAll();
  return 0;
}

#include "PQueue.h"
#include "Deque.h"
#include <iostream>

int main(){
  Deque *node = new Deque();
  std::cout<<node->createDeque("./catalog.txt");
  // std::cout<<dq->createDeque("../catlog.txt");
  // node->enqueueHead("Jan", 1332, "Bubu", "Song", "Jam Rock", 14);
  std::cout<<node->displayAll();
  return 0;
}

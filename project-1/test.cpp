#include "Stack.h"
#include <iostream>

int main(){
  Stack *dq = new Stack();
  std::cout<<dq->createStack("catalog.txt");
  // dq->enqueueHead("Jan", 1332, "Bubu", "Song", "Jam Rock", 14);
  std::cout<<dq->displayAll();
  return 0;
}

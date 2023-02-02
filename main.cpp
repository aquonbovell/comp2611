#include "Deque.h"
#include <iostream>

int main(){
  Deque dq = Deque();
  dq.addToTail("Jesus");
  dq.addToTail("Aquo");
  dq.addToHead("ear");
  dq.addToTail("early");
  std::cout<<dq.getFront()<<"\n";
  std::cout<<dq.getBack()<<"\n\n";
  std::cout<<dq.getAllData()<<"\n";
  std::cout<<dq.count()<<"\n";
}
#include "Deque.h"
#include <iostream>
using std::cout, std::boolalpha;

int main(){
  Deque dq = Deque();
  dq.enqueueTail("Jason");
  dq.enqueueTail("Aquon");
  dq.enqueueHead("Deshawn");
  dq.enqueueHead("Gabby");
  dq.enqueueTail("Gregry");
  dq.enqueueTail("Linoel");
  cout<<"Deque: All Data\n"<<dq.getAllData()<<"\n";
  cout<<"Deque: Front\n"<<dq.getFront()<<"\n";
  cout<<"Deque: Back\n"<<dq.getBack()<<"\n\n";
  cout<<"Deque: Count\n"<<dq.size()<<"\n";
  dq.dequeueHead();
  cout<<"\n";
  cout<<"Is Linoel in the Deque? "<<boolalpha<<dq.find("Linoel")<<"\n";
  cout<<"Deque: All Data\n"<<dq.getAllData()<<"\n";
  cout<<"Deque: Front\n"<<dq.getFront()<<"\n";
  cout<<"Deque: Back\n"<<dq.getBack()<<"\n\n";
  cout<<"Deque: Count\n"<<dq.size()<<"\n";
  dq.dequeueTail();
  cout<<"\n";
  cout<<"Deque: All Data\n"<<dq.getAllData()<<"\n";
  cout<<"Deque: Front\n"<<dq.getFront()<<"\n";
  cout<<"Deque: Back\n"<<dq.getBack()<<"\n\n";
  cout<<"Deque: Count\n"<<dq.size()<<"\n";
  cout<<"Is Empty? "<<boolalpha<<dq.isEmpty()<<"\n";
  dq.dequeueTail();
  dq.dequeueHead();
  dq.dequeueTail();
  dq.dequeueHead();
  cout<<"\n";
  cout<<"Deque: All Data\n"<<dq.getAllData()<<"\n";
  cout<<"Deque: Front\n"<<dq.getFront()<<"\n";
  cout<<"Deque: Back\n"<<dq.getBack()<<"\n\n";
  cout<<"Deque: Count\n"<<dq.size()<<"\n";
  cout<<"Is Empty? "<<boolalpha<<dq.isEmpty()<<"\n";
  cout<<"Is Linoel in the Deque? "<<boolalpha<<dq.find("Linoel");
}
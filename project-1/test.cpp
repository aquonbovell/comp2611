#include "PQueue.h"
#include <iostream>

int main()
{
  PriorityQueue *pq = new PriorityQueue();
  std::cout << pq->isEmpty()<<std::endl;
  pq->createPriorityQueue("../catalog.txt");
  std::cout << pq->isEmpty()<<std::endl;
  std::cout<<pq->displayAll()<<std::endl;
  pq->createPriorityQueue("../catalog.txt");
  std::cout << std::boolalpha<< pq->isEmpty()<<std::endl;

}
// #include "Queue.h"
#include "Stack.h"
#include <iostream>
using std::cout, std::boolalpha;

int main(){
  // Queue q = Queue();
  // q.enqueue(3,"hell0",38.3);
  // q.enqueue(3,"lokk",38.3);
  // // std::cout<<std::boolalpha<<q.isEmpty();
  // q.enqueue(3,"ojjj",38.3);
  // q.dequeue();
  // q.dequeue();
  // std::cout<<q.getAllData();
  // std::cout<<q.dequeue();
  // std::cout<<q.size();
  // std::cout<<q.dequeue();
  
  
  Stack st = Stack();
  std::cout<<st.pop();
  st.push("Jake");
  st.push("Justion");
  // std::cout<<st.pop();
  st.push("Justin");
  std::cout<<st.getAllData();
  std::cout<<st.size();
}
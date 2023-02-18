// #include "Queue.h"
// #include "Stack.h"
#include <iostream>
#include <algorithm>

int main(){
  std::string str = "\nDecember";
  str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
  std::cout<<str;
}
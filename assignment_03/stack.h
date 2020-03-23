#include <iostream>
#include "node.h"

class stack{
public:
  stack();
  void push(int data);
  int pop();
  int top();
  bool is_empty();

private:
  *Node head;
};

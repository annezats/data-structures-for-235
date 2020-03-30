#include <iostream>
#include "node.h"

class queue{
public:
  queue();
  ~queue();
  void enqueue(int data);
  int dequeue();
  int front();
  bool is_empty();

private:
  *Node head;
  *Node tail;
};

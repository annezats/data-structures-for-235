#include <iostream>
#include "stack.h"

stack::stack(){
  head=nullptr;
}

void Stack::push(int data){
    Node *t = new Node(int data);
    t->setNext(head->getNext()); //connects t to front of list
    head->setNext(t);//connects head to t, gets rid of other thing
}

int stack::pop(){
  int data = head->getData();
  head->setData(head->getNext());
  return data;
  //removes a value from the top
}

int stack::top(){
  return head->getData();
}

bool stack::is_empty(){
  if (head->getNext()==nullptr)
    return true;
  else
    return false;
}

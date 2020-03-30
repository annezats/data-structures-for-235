#include <iostream>
#include "queue.h"

#define QUEUE_ERR_EMPTY 1

       //     Tail
//            \|/
// head->1->2->3->nullptr
queue::queue(){
  head=nullptr;
  tail = nullptr;
}

queue::~queue(){
  if (head != nullptr) {
    Node *t, *t2;
    t = head;
    while (t!=nullptr){
      t2 = t;
      t = t->getNext();
      delete t2;
    }
  }
}

void queue::enqueue(int data){
  Node * t = new Node(data);
  if (head== nullptr){
    head->setNext(t);
    tail->setNext(t);
  }
  else{
    tail->setNext(t); //adds next item
    tail = t; //makes tail point to next item
  }
  delete t;
}

int queue::dequeue(){
  if (head==nullptr){
    throw QUEUE_ERR_EMPTY;
  }
  int data = tail->getData();
  Node *t = head;
  while (t->getNext() != tail){ //makes t find prev pointer from tail
    t = t->getNext();
  }
  tail = t;//makes tail point to the previous one
  t= t->getNext();
  delete t;
  tail->setNext(nullptr);
  return data;

}

int queue::front(){
  return head->getData();
}

bool queue::is_empty(){
  if (head->getNext()==nullptr)
    return true;
  else
    return false;
}

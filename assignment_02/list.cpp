#include <iostream>

#include <string>
#include "List.h"

List::List(){
  front = nullptr; //front->next->next->back
  back = nullptr; //back ->prev->prev->front
  current = nullptr;
}

List::~List(){
  std::cout << "In the destructor\n";
  if (front != nullptr){
    Node *t,*t2;

    t=front->getNext();
    while (t!=nullptr){
      t2=t;
      t=t->getNext();
      delete t2;
    }
    delete front;
  }


}

void List::insert(std::string data){
  Node *t = new Node(data,nullptr,nullptr);//
  if (front==nullptr){
    front= t;
    back = t;
  }
  else{
    t->setNext(front); //connecting t to the front of the list
    front->setPrev(t);// adding t to the front of the list
    front = t; //making t the new front of the list
  }
}

std::string List::getDebugString(){
  std::string s = "";   std::string v = "";
  Node *t = front;
  while (t != nullptr){
    s = s + t->getData()+"->";
    t=t->getNext();
  }
  do{//
    t->getPrev();//
    v = v + t->getData()+"<-";//
  }while (t!=nullptr);//
  s=s+ " backwards" + v + " NULL\n";//
  return s;
}

void List::push_back(std::string s){
  Node *t = new Node(s);
  if (front==nullptr){
    front = t;
    back = t;
  }
  else{
    back->setNext(t); //adding t to the back of the list
    t->setPrev(back); //connecting t to the back of the list
    back = t; //making t the new back of the list
  }
}

int List::size(){
  Node *t = front;
  int i = 0;
  while (t!=nullptr){
    t=t->getNext();
    i++;
  }
  return i;
}

void List::remove(int i){
  Node *t, *t2;
  if (i>size()-1)
    return;
  if (i==0){
    t=front;
    front=front->getNext();
    delete t;
    return;
  }
  t=front;
  while (i>0){
    i--;
    t2=t;
    t=t->getNext();
  }
t2->setNext(t->getNext());
(t->getNext())->setPrev(t2);//
 delete t;
}

std::string &List::operator[](int i){

  if (i>size()-1)
    return dummy;
  Node *t = front;
  while (i>0){
    i--;
    t=t->getNext();
  }
  return t->getRef();
}

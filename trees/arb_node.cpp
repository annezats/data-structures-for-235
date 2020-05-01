#include "node.h"

Node::Node() {
  data = 0;
  //VECTOR STUFF
}

Node::Node(int data){
  this->data = data;
  //VECTOR STUFF
}

Node::Node(int data, vector <Node*> vec){
  this->data = data;
  this->childrenlist = vec;
}

int Node::getData(){
  return data;
}

Node * Node::getChild(int index){
  return chidlrenlist[index];
}

int Node::getNumChildren(){
  return this->childrenlist.size();
}


void Node::setData(int d){
  data = d;
}

void Node::setChild(Node *child){
  this->childrenlist.push_back(child);
}

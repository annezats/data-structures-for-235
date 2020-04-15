#include "tree.h"
#include <iostream>
#include "node.h"
tree::tree(){
  root = nullptr;
}

void tree::insert( int data){

}

std::string tree::get_debug_string(){
  if (root == nullptr)
    return " ";
  else
    return std::to_string(root->getData());
}

void tree::setup(){
  Node *n = new Node(20);
  Node *m = new Node(30);
  Node *p = new Node(40);
  Node *s = new Node(10);
  root = s;
  root->setLeft(n);
  root->setRight(p);
  root->getLeft()->setLeft(m);

}

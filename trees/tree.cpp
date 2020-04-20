#include "tree.h"
#include <iostream>
#include "node.h"
tree::tree(){
  root = nullptr;
}

void tree::insert(int data){
  if (root==nullptr)
    root= new Node(data);
  else
  insert_helper(root, data);
}

void tree::insert_helper(Node * thisnode, int data){
  if (data> thisnode->getData()){
    if (thisnode->getRight()==nullptr){
      Node*n = new Node(data);
      thisnode->setRight(n);
    }
    else
      insert_helper(thisnode->getRight(), data);
  }

  if (data< thisnode->getData()){
    if (thisnode->getLeft()==nullptr){
      Node*n = new Node(data);
      thisnode->setLeft(n);
    }
    else
      insert_helper(thisnode->getLeft(), data);
  }
}

std::string tree::make_debug_string(Node * root){ //makes debugger starting at any node
  if (root == nullptr){
    return " ";
  }
  else if (root->getLeft()==nullptr && root->getRight()==nullptr){
      return std::to_string(root->getData());
    }
    //else return "("+ std::to_string(root->getData()) + "-->" + make_debug_string(root->getLeft())+ ","+ make_debug_string(root->getRight())+ ")";
    else return  std::to_string(root->getData()) +"-->" +  "("+make_debug_string(root->getLeft())+ "),("+ make_debug_string(root->getRight())+ ")";
    //the line in the comment returns the same correct thing but formatted differently (more confusingly)
}

std::string tree::get_debug_string(){
  return make_debug_string(root); //executes the maker with specifically the root of this tree
}

void tree::setup(){
  Node *n = new Node(20);
  Node *m = new Node(30);
  Node *p = new Node(50);
  Node *s = new Node(10);
  Node *t = new Node(40);
  Node *u = new Node(60);
  root = s;
  root->setLeft(n);
  root->setRight(p);
  root->getLeft()->setLeft(m);
  root->getLeft()->setRight(t);
  root->getRight()->setLeft(u);
}

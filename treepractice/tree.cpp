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

void tree::remove (int data){
  //setup
  //find the Node, keep track of its parent
  Node* parent= searchforparent(root, data);//WORKS
  //std::cout<< "parent worked"<< std::endl;
  Node *mynode = nullptr; bool isleft; Node *child = nullptr;
  if (parent->getRight()->getData()==data){
    mynode = parent->getRight();
    isleft = false;//keeps track of if right or left of parent
  }
  else {
    mynode= parent->getLeft();
    isleft = true;
  }
  int c=4;//case counter
  if (mynode->getLeft() == nullptr && mynode->getRight() == nullptr){
    c = 1;//has no children
    std::cout<< "CASE1 worked"<< std::endl;

  }
  if (mynode->getLeft() == nullptr && mynode->getRight() != nullptr){
    c = 2; //has right child
    child = mynode->getRight();
    std::cout<< "CASE2 p1 worked"<< std::endl;

  }
  if (mynode->getLeft() != nullptr && mynode->getRight() == nullptr){
    c = 2; //has left child
    child = mynode->getLeft();
    std::cout<< "CASE2 p2 worked"<< std::endl;

  }
  if (mynode->getLeft() != nullptr && mynode->getRight() != nullptr){
    c = 3; //has both children
    std::cout<< "CASE3 worked"<< std::endl;

  }
  switch (c){
    case 1 :   //if no children, delete node, set parent's children to null
      delete mynode;
      if (isleft){
        parent->setLeft(nullptr);
      }
      else parent->setRight(nullptr);
      break;
    case 2: //if one right child, delete node, set parent's child to child
      std::cout<< "CASE2 worked"<< std::endl;
      delete mynode;
      if (isleft){
        parent->setLeft(child);
      }
      else parent->setRight(child);
      break;
    case 3: //if two children, find smallest of right children, stick value into node, remove smallest (duplicate)
      std::cout<< "CASE3 worked"<< std::endl;
      Node * smallest = searchforsmallest(mynode->getRight());
      std::cout<< "search for smallest worked"<< std::endl;
      int smallestvalue = smallest->getData();
      Node * smallestparent = searchforparent(mynode->getRight(),smallestvalue);
      mynode->setData(smallestvalue);
      delete smallest;
      smallestparent->setLeft(nullptr);
      break;
  }
}

Node * tree::searchforparent(Node * mynode, int data){
  std::cout<< "got into search for parent"<< mynode->getData()<<std::endl;
  if (mynode->getRight()== nullptr && mynode->getLeft()== nullptr){
    std::cout<< "hit dead end"<< std::endl;
    return nullptr;
  }
  if (mynode->getRight()->getData()== data || mynode->getLeft()->getData()== data){
    std::cout<< "hit parent"<< std::endl;
    return mynode;
  }
  std::cout<< "abt to go into problem"<< std::endl;
  std::cout<< mynode->getRight()->getData()<< std::endl;
  if (mynode->getRight() != nullptr){//WHY DOESNT IT GO HERE??
    std::cout<< "abt to go into searchedright"<< std::endl;
    Node * searchedright = searchforparent(mynode->getRight(), data);
    std::cout<< "got out of searchedright"<< std::endl;
    if (searchedright != nullptr){
      std::cout<< "passing along thing"<< std::endl;
      return searchedright;
    }
  }
  std::cout<< "abt to go into searchedleft"<< std::endl;
  Node * searchedleft = searchforparent(mynode->getLeft(), data);
  std::cout<< "got out of searched left"<< std::endl;

  return searchedleft;
}


Node * tree::searchforsmallest(Node * mynode){
  if (mynode->getLeft()== nullptr){
    return mynode;
  }
  Node * goleft = searchforsmallest( mynode->getLeft());
  return goleft;
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

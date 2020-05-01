#include <iostream>
#include "node.h"
#include "tree.h"

int num_nodes(Node * root){
  //std::cout<<"starting "<<std::to_string(root->getData())<<std::endl;
  if (root->getLeft()==nullptr && root->getRight()==nullptr){
    //std::cout<<"reached leaf"<<std::endl;
    return 1;
  }
  int left = 0; int right = 0;
  if (root->getLeft() != nullptr){
    left = num_nodes(root->getLeft());
    //std::cout<<"finished left"<<std::to_string(left)<<std::endl;
  }
  if (root->getRight() != nullptr){
    right = num_nodes(root->getRight());
    //std::cout<<"finished right"<<std::to_string(right)<<std::endl;
  }
  //std::cout<<std::to_string(root->getData())<<"going back up "<< std::to_string(left + right) <<std::endl;
  return left + right + 1;
}

int sum_nodes(Node * root){
  if (root->getLeft()==nullptr && root->getRight()==nullptr){
    return root->getData();
  }
  int left = 0; int right = 0;
  if (root->getLeft() != nullptr){
    left = sum_nodes(root->getLeft());
  }
  if (root->getRight() != nullptr){
    right = sum_nodes(root->getRight());
  }
  return left + right + root->getData();
}

int num_leaves(Node * root){
  if (root->getLeft()==nullptr && root->getRight()==nullptr){
    return 1;
  }
  int left = 0; int right = 0;
  if (root->getLeft() != nullptr){
    left = num_leaves(root->getLeft());
  }
  if (root->getRight() != nullptr){
    right = num_leaves(root->getRight());
  }
  return left + right;
}

int main()
{
  Node *n = new Node(20);
  Node *m = new Node(30);
  Node *o = new Node(40);
  Node *p = new Node(50);
  Node *q = new Node(60);
  Node *r = new Node(70);
  Node *s = new Node(10);
  s->setLeft(n);
  s->setRight(p);
  n->setLeft(m);
  m->setLeft(o);
  p->setLeft(q);
  p->setLeft(r);
  std::cout<< s->getData() << std::endl;
  std::cout<< s->getLeft()->getData() <<"  "<< s->getRight()->getData()<< std::endl;
  //std::cout<< n->getLeft()->getData() << "  " << p->getLeft()->getData() <<"  "<< p->getRight()->getData()<< std::endl;
  //std::cout<< m->getLeft()->getData() << std::endl;
  //^^ those give a segmentation fault. hahah
  tree *tree1= new tree();
  tree1->setup();
  std::cout<<tree1->get_debug_string()<< std::endl;

  tree *tree2= new tree();
  tree2->insert(10);
  //std::cout<<tree2->get_debug_string()<< std::endl;
  //std::cout<<tree2->root->getData()<< std::endl;
  tree2->insert(20);
  tree2->insert(30);
  tree2->insert(5);
  tree2->insert(17);
  tree2->insert(22);
  tree2->insert(35);
  tree2->insert(408);
  tree2->insert(3);
  tree2->insert(9);
  std::cout<<tree2->get_debug_string()<< std::endl;
  std::cout << "challenge 1 : size:" << num_nodes(tree2->root)<< std::endl;
  std::cout << "challenge 2 : sum:" << sum_nodes(tree2->root)<< std::endl;
  std::cout << "challenge 3 : num leaves:" << num_leaves(tree2->root)<< std::endl;

  return 0;
}

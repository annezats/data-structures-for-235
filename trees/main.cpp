#include <iostream>
#include "node.h"
#include "tree.h"

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

  tree2->remove(3);
  std::cout<<tree2->get_debug_string()<< std::endl; //WORKS
  //WORKS
  //Node * smallesttest = tree2->searchforsmallest(tree2->root->getRight());
  //std::cout<<smallesttest->getData()<<std::endl;
  //doesnt work
  /*tree2->remove(17);
  std::cout<<tree2->get_debug_string()<< std::endl;
  tree2->remove(20);
  std::cout<<tree2->get_debug_string()<< std::endl;
  */
  return 0;
}

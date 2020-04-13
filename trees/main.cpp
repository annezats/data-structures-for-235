#include <iostream>
#include "Node.h"


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
  std::cout<< n->getLeft()->getData() << "  " << p->getLeft()->getData() <<"  "<< p->getRight()->getData()<< std::endl;
std::cout<< m->getLeft()->getData() << std::endl;

  return 0;
}

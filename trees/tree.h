#pragma once
#include "node.h"
#include <string>

class tree{
public:
  std::string get_debug_string();
  std::string make_debug_string(Node * root);
  void insert(int data);
  tree();
  void setup(); //hardcodes a tree for setup
private:
  Node * root;
};

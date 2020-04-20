#pragma once
#include "node.h"
#include <string>

class tree{
public:
  std::string get_debug_string();
  std::string make_debug_string(Node * root);
  void insert(int data);
  void insert_helper(Node * root, int data);
  tree();
  void setup(); //hardcodes a tree for setup
private:
  Node * root;
};

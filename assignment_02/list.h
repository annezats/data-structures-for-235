#include <iostream>

#include <string>
#include "Node.h"

class List{
private:
    std::string dummy="";
  Node *front;
  Node *back;
  Node *current;
public:
  List();
  ~List();
  void insert(std::string data); //adds to front
  std::string getDebugString();
  void push_back(std::string); //adds to back
  int size() ;
  void remove(int i);
  std::string &operator[](int); // overloaded square brackets
};

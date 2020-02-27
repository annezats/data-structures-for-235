#pragma once

class Node{
 private:
  std::string data;
  Node *next;
  Node *prev; //new
 public:
  Node();
  Node(std::string data);
  Node(std::string data, Node* next, Node* prev);//
  void setData(std::string data);

  void setNext(Node *next);
  void setPrev(Node *prev); //new
  std::string getData();
  std::string &getRef();
  Node* getNext();
  Node* getPrev(); //new

};

#pragma once
#include <vector>

/*QUESTION: Can you think of any computer based solutions to problems that implement
trees where each node can have an arbitrary number of children?
When creating a binary tree creating left and right pointers makes sense since we only
have a few possibilities but as you potentially have more and more children we need a better solution.
MY ANSWER: just make a vector of pointers to children? like the node has a vector instead of right and getLeft
i am not sure how to make that work for the tree though.
CHALLENGE: Try to design a simple data structure that can be used to represent an
arbitrary tree.
After you've spent some time answering the question and challenge watch this video:
*/

class Node{
private:
  int data;
  vector <Node*> childrenlist;
public:
  Node();
  Node(int data);
  Node(int data, vector <Node*> vec);
  int getData();
  int getNumChildren();
  Node *getChild(int index);

  void setData(int d);
  void setChild(Node *child);

};

//// node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class node {
 public:
  node(int data);
  ~node();

  void setNext(node* n);

  int getValue();
  node* getNext();

 private:
  int value;
  node* next;
} ;
#endif //NODE_H

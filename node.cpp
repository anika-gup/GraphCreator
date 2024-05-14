//node.cpp
#include "node.h"
#include <iostream>
#include <cstring>

using namespace std;

node::node(int data) {
  value = data;
  next = NULL;
}
node::~node() {
  // i still have no idea what this does YAY !
}
void node::setNext(node* n) {
  next = n;
}
int node::getValue() {
  return value;
}
node* node::getNext() {
  return next;
}

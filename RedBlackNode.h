//
// Created by Youssef on 6/12/21.
//

#include <iostream>
#include <string>

using namespace std;

#ifndef REDBLACK__REDBLACKNODE_H
#define REDBLACK__REDBLACKNODE_H


struct RedBlackNode {
  std::string data;
  RedBlackNode *parent;
  RedBlackNode *left;
  RedBlackNode *right;
  int color;
};

typedef RedBlackNode *NodePtr;


#endif //REDBLACK__REDBLACKNODE_H

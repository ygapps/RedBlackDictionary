//
// Created by Youssef on 6/12/21.
//

#include "RedBlackNode.h"
#include <iostream>
#include <string>

#ifndef REDBLACK_CMAKE_BUILD_DEBUG_REDBLACKTREE_H
#define REDBLACK_CMAKE_BUILD_DEBUG_REDBLACKTREE_H

class RedBlackTree {
private:
  NodePtr root;
  NodePtr TNULL;
  int tree_size;



  NodePtr searchTreeHelper(NodePtr node, string key);
  void insertFix(NodePtr k);
  void printHelper(NodePtr root, string indent, bool last);

public:
  RedBlackTree() {
    TNULL = new RedBlackNode;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
    tree_size = 0;
  }



  bool searchTree(string k);
  void leftRotate(NodePtr x);
  void rightRotate(NodePtr x);
  void insert(string key);
  RedBlackTree load(string filename);
  NodePtr getRoot();
  void printTree();
  int height(NodePtr root);
  int printHeight(int oldHeight);
  int getSize();

};

#endif //REDBLACK_CMAKE_BUILD_DEBUG_REDBLACKTREE_H

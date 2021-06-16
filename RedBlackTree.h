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

  void initializeNULLNode(NodePtr node, NodePtr parent);

  void preOrderHelper(NodePtr node);
  void inOrderHelper(NodePtr node);
  void postOrderHelper(NodePtr node);

  NodePtr searchTreeHelper(NodePtr node, string key);

  void deleteFix(NodePtr x);
  void rbTransplant(NodePtr u, NodePtr v);
  void deleteNodeHelper(NodePtr node, string key);

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

  void preorder();
  void inorder();
  void postorder();

  bool searchTree(string k);
  NodePtr minimum(NodePtr node);
  NodePtr maximum(NodePtr node);
  NodePtr successor(NodePtr x);
  NodePtr predecessor(NodePtr x);

  void leftRotate(NodePtr x);
  void rightRotate(NodePtr x);
  void insert(string key);
  RedBlackTree load(string filename);

  NodePtr getRoot();

  void deleteNode(string data);
  void printTree();
  
  int height(NodePtr root);
  int printHeight(int oldHeight);
  int size(NodePtr node);
  int getSize();
};

#endif //REDBLACK_CMAKE_BUILD_DEBUG_REDBLACKTREE_H

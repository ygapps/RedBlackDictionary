//
// Created by Youssef on 6/11/21.
//
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "RedBlackTree.h"





NodePtr RedBlackTree::searchTreeHelper(NodePtr node,std:: string key) {

    if (node == TNULL || key==node->data) {

    return node;
  }

  if (key < node->data) {
    return searchTreeHelper(node->left, key);
  }
  return searchTreeHelper(node->right, key);
}
bool RedBlackTree::searchTree(string k) {

    NodePtr search_helper_result= searchTreeHelper(this->root,k);
    if(search_helper_result==TNULL)return false;

    return true;
}

// For balancing the tree after insertion
void RedBlackTree::insertFix(NodePtr k) {
  NodePtr u;
  while (k->parent->color == 1) {
    if (k->parent == k->parent->parent->right) {
      u = k->parent->parent->left;
      if (u->color == 1) {
        u->color = 0;
        k->parent->color = 0;
        k->parent->parent->color = 1;
        k = k->parent->parent;
      } else {
        if (k == k->parent->left) {
          k = k->parent;
          rightRotate(k);
        }
        k->parent->color = 0;
        k->parent->parent->color = 1;
        leftRotate(k->parent->parent);
      }
    } else {
      u = k->parent->parent->right;

      if (u->color == 1) {
        u->color = 0;
        k->parent->color = 0;
        k->parent->parent->color = 1;
        k = k->parent->parent;
      } else {
        if (k == k->parent->right) {
          k = k->parent;
          leftRotate(k);
        }
        k->parent->color = 0;
        k->parent->parent->color = 1;
        rightRotate(k->parent->parent);
      }
    }
    if (k == root) {
      break;
    }
  }
  root->color = 0;
}

void RedBlackTree::printHelper(NodePtr root, string indent, bool last) {
  if (root != TNULL) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }

    string sColor = root->color ? "RED" : "BLACK";
    cout << root->data << "(" << sColor << ")" << endl;
    printHelper(root->left, indent, false);
    printHelper(root->right, indent, true);
  }
}
void RedBlackTree::leftRotate(NodePtr x) {
  NodePtr y = x->right;
  x->right = y->left;
  if (y->left != TNULL) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr) {
    this->root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void RedBlackTree::rightRotate(NodePtr x) {
  NodePtr y = x->left;
  x->left = y->right;
  if (y->right != TNULL) {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr) {
    this->root = y;
  } else if (x == x->parent->right) {
    x->parent->right = y;
  } else {
    x->parent->left = y;
  }
  y->right = x;
  x->parent = y;
}

// Inserting a node
void RedBlackTree::insert(string key) {
  NodePtr node = new RedBlackNode;
  node->parent = nullptr;
  node->data = key;
  node->left = TNULL;
  node->right = TNULL;
  node->color = 1;

  NodePtr y = nullptr;
  NodePtr x = this->root;
  this->tree_size++;

  while (x != TNULL) {
    y = x;
    if (node->data < x->data) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  node->parent = y;
  if (y == nullptr) {
    root = node;
  } else if (node->data < y->data) {
    y->left = node;
  } else {
    y->right = node;
  }

  if (node->parent == nullptr) {
    node->color = 0;
    return;
  }

  if (node->parent->parent == nullptr) {
    return;
  }

  insertFix(node);
}

NodePtr RedBlackTree::getRoot() {
  return this->root;
}



void RedBlackTree::printTree() {
  if (root) {
    printHelper(this->root, "", true);
  }
}

int RedBlackTree::height(NodePtr root) {
  if(root == TNULL){
    return 0;
  }
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  return std::max(leftHeight,rightHeight)+1;
}
//This return the actual tree height
int RedBlackTree::printHeight(int oldHeight){
  if(oldHeight==0)
    return 0;
  else
    return oldHeight-1;
}
int RedBlackTree::getSize(NodePtr node)
{
    if(node==TNULL)
        return 0;
    else
        return(getSize(node->left)+1+getSize(node->right));
}
RedBlackTree RedBlackTree::load(string filename) {
    RedBlackTree tree;

       string word;
        int count=0;
        fstream file;
        file.open(filename,ios::in);//read
        if (file.is_open()) {
            while (getline(file, word)) {
                file >> word;
                std::for_each(word.begin(), word.end(), [](char & c) {
                    c = ::tolower(c);
                });
                tree.insert(word);
                count++;


            }
        }
            else
            {
                cout<<"error opening file\n";
                exit(1);
            }

            file.close();
            cout<<"Dictionary Loaded Successfully...!\n";
            cout<<"..........................................\n";
            cout<<"size of dictionary before insertion :"<<count<<"\n";

            cout<<"..........................................\n";
            cout<<"Height of dictionary before insertion:" << printHeight(tree.height(tree.root))<<"\n";
            cout<<"..........................................\n";




    return tree;

        }






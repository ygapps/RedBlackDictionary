#include <iostream>
#include <string>
#include <algorithm>
#include "RedBlackTree.h"

RedBlackTree tree=tree.load(R"(../Dictionary.txt)"); //function to load dictionary file in RBT search tree


static void printDicSize(RedBlackTree tree){
    cout<<"Size of the Dictionary is "<<tree.getSize(tree.getRoot())<<"\n";   // printing number of nodes
}
static void printRBTHeight(RedBlackTree tree){
    int oldHeight = tree.height(tree.getRoot());
    int height =tree.printHeight(oldHeight);                 //printing the height of tree
    cout<<"Height of Red black tree is "<<height<<"\n";
}
static void insert(RedBlackTree tree){
    cout<<"Please Enter the Keyword for Insertion:";       //allow user to insert word
    string word;
    cin>>word;

    if(tree.searchTree(word)){
        cout<<"ERROR:Word already in the dictionary!\n";
        return;
    }
    tree.insert(word);
    cout<<"Keyword : is inserted successfully\n";
    printDicSize(tree);
    printRBTHeight(tree);
}

static void search(RedBlackTree tree){
    cout<<"Please Enter the keyword for Searching\n";
   string word;
   cin>>word;
    std::for_each(word.begin(), word.end(), [](char & c) {
        c = ::tolower(c);
    });

    string result=tree.searchTree(word)==true? "Found":"Unfound";   //allow user to sear for a word
    cout<<"Keyword  is " <<result<<"\n";
}

int main() {



    cout<<"\t\t\t\t\t\t              ************Welcome to Dictionary*********\n";
    int choice=0;
    while(choice!=5)
    {
        cout<<"\t\t\t\t\t                           *********menu:**********\n";
        cout<<"enter:\n\t\t\t\t\t1:inset a word                  \n\t\t\t\t\t2:search for a word \n\t\t\t\t\t3:print height of a tree          \n\t\t\t\t\t4:print size of tree        \n\t\t\t\t\t5:exit\n";
        //cout<<tree.getRoot()->data;
        cout<<"answer:";
        cin>>choice;

        switch(choice)
        {
            case 1: {
                insert(tree);

                break;
            }
            case 2: {
                search(tree);
                break;
            }
            case 3: {
                printRBTHeight(tree);
                break;
            }
            case 4: {
                printDicSize(tree);
                break;
            }
            case 5: {
                cout<<"**************GoodBye*************\n";
                exit(1);
                break;
            }
            default:{
                cout<<"ERROR!:enter from 1 to 8\n";
            }
        }
    }
    

    return 0;
}
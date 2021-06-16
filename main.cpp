#include <iostream>
#include <string>
#include "RedBlackTree.h"
#include "fstream"
RedBlackTree tree;

static void printDicSize(RedBlackTree tree){
    cout<<"Size of the Dictionary is "<<tree.getSize()<<"\n";
}
static void printRBTHeight(RedBlackTree tree){
    int height=tree.height(tree.getRoot())-1;
    cout<<"Height of Red black tree is "<<height<<"\n";
}
static void insert(RedBlackTree tree){
    cout<<"Please Enter the Keyword for Insertion:";
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
    string result=tree.searchTree(word)==true? "Found":"Unfound";
    cout<<"Keyword  is " <<result<<"\n";
}

int main() {



    tree.load(R"(E:\6th term\ds2\assignment1\ass2\Dictionary.txt)");
    cout<<"\t\t\t\t\t\t              ************Welcome to Dictionary*********\n";
    int choice=0;
    while(choice!=5)
    {
        cout<<"\t\t\t\t\t                           *********menu:**********\n";
        cout<<"enter:\n\t\t\t\t\t1:inset a word                 \n\t\t\t\t\t2:search for a word \n\t\t\t\t\t3:print height of a tree          \n\t\t\t\t\t4:print size of tree        \n\t\t\t\t\t5:exit\n";
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
                printDicSize(tree);
                break;
            }
            case 4: {
                printRBTHeight(tree);
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


    //printf("Enter a sentence: \n");
    //gets(sentence);
    //char* token = strtok(sentence," ");
    //while(token!=NULL)
    //{
      //  Search(root,token);
        //token=strtok(NULL," ");
   // }

    return 0;
}
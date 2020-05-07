//This program is a red black tree, a self balancing data structure tree. User can add by console or file and print the tree. 
//Because the Cygwin command line is black, this tree is technically "Red White Tree", white numbers will represent black ones.
//Ethan Wang

#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

bool SEARCH(Node* root, int number);
void DELETE(Node *&root, int number); 
Node* ADD(Node* head, Node* nNode);
void RLEFT(Node *&root, Node *&nNode);
void RRIGHT(Node *&root, Node *&nNode);
void UPDATE(Node *&root, Node *&nNode);
void PRINT(Node* head, int format);

//MainLine Function Caller
int main() {
  bool running = true;
  char* input = new char[30];
  int input2 = 0;
  Node* head = NULL; 
  while (running == true) {
  cout << "Hello, welcome to red black tree, this has become the bane of my existence. \nBSD, pass fail grading please. \n";
  cout << "You can do many things with this tree that is red and black. You can ADD, you can READ, you can SEARCH, you can DELETE, you can PRINT, you can EXIT. That is all. \n";
  cin.getline(input, 30);
  if (strcmp(input, "ADD") == 0) {
    cout << "What number do you want to add \n";
    cin >> input2;
    cin.get();
    Node* point = new Node();
    point -> setData(input2);
    head = ADD(head, point);
    UPDATE(head, point); 
  }
  //Input through file, I didnt feel like this needed a function because its the same process of add just repeated
  else if (strcmp(input, "READ") == 0) {
    int counter = 0;
    int* array = new int[1000];
    char* name = new char[50];
    cout << "File Name? \n";
    cin.getline(name, 50);
    ifstream inFile;
    inFile.open(name);
    char* input3 = new char[400];
    inFile.getline(input3, 400);
    char* token = strtok(input3, ",");
    while(token != NULL) {
      array[counter] = atoi(token);
      token = strtok(NULL, ", ");
      counter++;
    }
    for (int i = 0; i < counter; i++) {
      Node* point = new Node();
      point -> setData(array[i]);
      head = ADD(head, point);
      UPDATE(head, point); 
    }
    
  }
  else if (strcmp(input, "PRINT") == 0) {
    if (head == NULL) {
      cout << "Can't Print Nothing \n";
    }
    else {
      PRINT(head, 0);
      cout << "\n";
    }
  }
  else if (strcmp(input, "DELETE") == 0) {

  }
  else if (strcmp(input, "SEARCH") == 0) {

  }
  else if (strcmp(input, "EXIT") == 0) {
    running = false; 
  }
  else {
    cout << "Valid Input or Whatttttttt........ \n"; 
  }
  }
  return 0; 
}
//Add node through console
Node* ADD(Node* head, Node* nNode) {
  if (head == NULL) {
    return nNode; 
  }
  else if (head -> getData() >= nNode -> getData()) {
    head -> setLeft(ADD(head-> getLeft(), nNode));
    head-> getLeft() -> setParent(head); 

  }
  else if (head -> getData() < nNode -> getData()) {
    head -> setRight(ADD(head ->getRight(), nNode));
    head -> getRight()-> setParent(head); 
  }
  return head; 
}

//Print out the tree
void PRINT(Node* head, int format) {
  if (head == NULL) 
    return; 
  format = format + 5;
  PRINT(head -> getRight(), format);
  cout << '\n';
  for (int i = 5; i < format; i++)
    cout << " ";
  if (head -> getColor() == 1) {
    cout << "\033[1;31m" << head -> getData() << "\033[0m"; 
  }
  else {
    cout << head -> getData(); 
  }
      PRINT(head -> getLeft(), format); 
  
}

//Left Rotation 
void RLEFT(Node *&root, Node *&nNode) {
  Node *right = nNode -> getRight();
  nNode -> setRight(right -> getLeft());
  if (nNode-> getRight() != NULL) {
    nNode -> getRight() -> setParent(nNode); 
  }
  right -> setParent(nNode -> getParent());
  if (nNode -> getParent() == NULL) {
    root = right;
  }
  else if (nNode == nNode->getParent() -> getLeft()) {
    nNode -> getParent() -> setLeft(right); 
  }
  else {
    nNode -> getParent() -> setRight(right);
  }
  right -> setLeft(nNode);
  nNode -> setParent(right);
}

//Right Rotation
void RRIGHT(Node *&root, Node *&nNode) {
  Node *left = nNode -> getLeft();
  nNode -> setLeft(left-> getRight());
  if (nNode-> getLeft() != NULL) {
    nNode -> getLeft() -> setParent(nNode);
  }
  left -> setParent(nNode -> getParent());
  if (nNode -> getParent() == NULL) {
    root = left;
  }
  else if (nNode == nNode -> getParent() -> getLeft()) {
    nNode -> getParent() -> setLeft(left); 
  }
  else {
    nNode -> getParent() -> setRight(left); 
  }
  left -> setRight(nNode);
  nNode -> setParent(left); 
}

//Updates and fixes tree after every addition
void UPDATE(Node *&root, Node *&nNode) {
  Node *parent = NULL;
  Node *gParent = NULL;
  while ((nNode != root) && (nNode -> getColor() != 2) && (nNode -> getParent() -> getColor() == 1)) {
  parent = nNode -> getParent();
  gParent = nNode -> getParent() -> getParent();
  if (parent == gParent -> getLeft()) {
    Node* uncle = gParent -> getRight();
  if (uncle != NULL && uncle -> getColor() == 1) {
    gParent -> setColor(1);
    parent -> setColor(2);
    uncle -> setColor(2);
    nNode = gParent; 
}
  else {
    if (nNode == parent -> getRight()) {
      RLEFT(root, parent); 
      nNode = parent;
      parent = nNode -> getParent();
    }
    RRIGHT(root, gParent); 
    int pcolor = parent -> getColor();
    int gcolor = gParent -> getColor();
    parent -> setColor(gcolor);
    gParent -> setColor(pcolor);
    nNode = parent;
  }
}
 else {
   Node *uncle = gParent -> getLeft();
   if ((uncle != NULL) && (uncle -> getColor() == 1)){
     gParent -> setColor(1);
     parent -> setColor(2);
     uncle -> setColor(2);
     nNode = gParent;
   }
   else {
     if (nNode == parent -> getLeft()) {
       RRIGHT(root, parent); 
       nNode = parent; 
       parent = nNode -> getParent();
     }
     RLEFT(root, gParent); 
     int pcolor = parent -> getColor();
     int gcolor = gParent -> getColor();
     parent -> setColor(gcolor);
     gParent -> setColor(pcolor);
     nNode = parent;
   }
 }
}
  root -> setColor(2); 
}

bool SEARCH(Node* root, int number) {

}

void DELETE(Node*& root, int number) {

}

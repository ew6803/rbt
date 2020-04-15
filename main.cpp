//asfafsa

#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

Node* addNode(Node* head, Node* point) {
  if (head == NULL) {
    return point; 
  }
  else if (head -> getData() >= point -> getData()) {
    head -> setLeft(addNode(head-> getLeft(), point));
    head-> getLeft() -> setParent(head); 

  }
  else if (head -> getData() < point -> getData()) {
    head -> setRight(addNode(head ->getRight(), point));
    head -> getRight()-> setParent(head); 
  }
  return head; 
}


void printTree() {

}

int main() {
  bool running = true;
  char* input = new char[30];
  int input2 = 0;
  Node* head = NULL; 
  while (running == true) {
  cout << "Hello, welcome to red black tree, this has become the bane of my existence. \nBSD, pass fail grading please. \n";
  cout << "You can do many things with this tree that is red and black. You can ADD, you can PRINT, you can EXIT. That is all. \n";
  cin.getline(input, 30);
  if (strcmp(input, "ADD") == 0) {
    cout << "What number do you want to add \n";
    cin >> input2;
    cin.get();
    Node* point = new Node();
    point -> setData(input2);
    head = addNode(head, point);
  }
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
      head = addNode(head, point);
    }
    
  }
  else if (strcmp(input, "PRINT") == 0) {

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

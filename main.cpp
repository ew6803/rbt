//asfafsa

#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

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

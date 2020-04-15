//asfafsa

#include "Node.h"
#include <iostream>
#include <ctsdlib>
#include <cstring>
#include <cmath>

using namespace std;

Node* addNode() {

}


void printTree() {

}

int main() {
  bool running = true;
  char* input = new char[30];
  int input2 = 0; 
  cout << "Hello, welcome to red black tree, this has become the bane of my existence. \n. BSD, pass fail grading please. \n";
  cout << "You can do many things with this tree that is red and black. You can ADD, you can PRINT, you can EXIT. That is all. \n"
  cin.getline(input, 30);
  if (strcmp(input, "ADD") == 0) {
    cout << "What number do you want to add \n";
    cin << input2;
    cin.get(); 
  }
  else if (strcmp(input, "PRINT") == 0) {

  }
  else if (strcmp(input, "EXIT") == 0) {

  }
  else {
    cout << "Valid Input or Whatttttttt........ \n"; 
  }
  return 0; 
}

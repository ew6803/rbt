#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node();
  Node* getLeft();
  Node* getRight();
  int getData();
  Node* getParent();
  void setLeft(Node*);
  void setRight(Node*);
  void setData(int);
  void setParent(Node*);
  int getColor();
  void setColor(int);
  Node* getSibling();
  void setSibling(Node*); 
  ~Node();
 private:
  Node* left;
  Node* right;
  int data;
  Node* parent;
  int color;
  Node* sibling;
};

#endif

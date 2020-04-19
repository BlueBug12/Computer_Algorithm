#include <iostream>

using namespace std;

struct node{
  node* parent;
  node* right_child;
  node* left_child;
  int value;
};

class Binary_Tree{

public:
  Binary_Tree(){}
  ~Binary_Tree(){}
  node* search(int target){}
  node* max(){}
  node* min(){}
  node* successor(node* n){}
  node* predecessor(node* n){}
  node* insert(node* n){}
  void delete(node* n){}
private:
  node* root;
};
int main(){

  return 0;
}

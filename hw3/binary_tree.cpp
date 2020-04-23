#include <iostream>
#include <utility>
#include <fstream>
#include <string>
using namespace std;

struct node{
  node* parent;
  node* right;
  node* left;
  int key;
};

class Binary_Tree{

public:
  Binary_Tree(){
    root=NULL;
  }
  ~Binary_Tree(){
    posorder_delete(root);
  }
  void posorder_delete(node* n){
    if(n!=NULL){
      posorder_delete(n->left);
      posorder_delete(n->right);
      //cout<<"delete: "<<n->key<<endl;
      delete n;
    }
  }
  void inorder_traverse(node* n){
    if(n!=NULL){
      inorder_traverse(n->left);
      cout<<n->key<<" ";
      inorder_traverse(n->right);
    }
  }
  node* root_node(){
    return root;
  }
  node* search(const int target){
    node* temp=root;
    while(temp!=NULL){
      if(target>temp->key){
        temp=temp->right;
      }
      else if(target<temp->key){
        temp=temp->left;
      }
      else{
        return temp;
      }
    }
    return NULL;
  }
  node* min(node* n){
    while(n->left!=NULL){
      n=n->left;
    }
    return n;
  }
  node* max(node* n){
    while(n->right!=NULL){
      n=n->right;
    }
    return n;
  }
  node* successor(const node* n){
    if(n==NULL)
      return NULL;
    if(n->right!=NULL)
      return min(n->right);

    node* temp=n->parent;
    while(temp!=NULL&&n==temp->right){
      n=temp;
      temp=temp->parent;
    }
    return temp;
  }

  node* predecessor(const node* n){
    if(n==NULL)
      return NULL;
    if(n->left!=NULL)
      return max(n->left);

    node* temp=n->parent;
    while(temp!=NULL&&n==temp->left){
      n=temp;
      temp=temp->parent;
    }
    return temp;
  }
  void insert_node(int key){
    node* n=new node;
    n->left=NULL;
    n->right=NULL;
    n->key=key;
    insert_node(n);
  }
  void insert_node(node* n){
    if(n==NULL){
      cout<<"Can't insert a NULL node!"<<endl;
      return ;
    }

    node* x=root;
    node* y=NULL;

    while(x!=NULL){
      y=x;
      if(n->key<x->key)
        x=x->left;
      else if(n->key>x->key)
        x=x->right;
      else{
        cout<<"Duplicated keys!"<<endl;
        return ;
      }
    }

    n->parent=y;
    if(y==NULL)
      root=n;
    else if(n->key<y->key)
      y->left=n;
    else if(n->key>y->key)
      y->right=n;
    else
      cout<<"Duplicated keys!"<<endl;
  }

  void delete_node(node* n){
    if(n==NULL){
        cout<<"Delete an empty node!"<<endl;
        return;
    }
    node* y;
    node* x;
    if(n->left==NULL || n->right==NULL)
      y=n;//only having one or no child
    else
      y=successor(n);//having two children

    if(y->left!=NULL)
      x=y->left;
    else
      x=y->right;

    if(x!=NULL)
      x->parent=y->parent;
    if(y->parent==NULL)
      root=x;
    else if(y==y->parent->left)
      y->parent->left=x;
    else
      y->parent->right=x;

    if(y!=n){
      n->key=y->key;
      delete y;
    }

  }
private:
  node* root;
};
int main(int argc, char** argv){
  if(argc!=2){
    cout<<"Wrong parameters!"<<endl;
    return -1;
  }
  Binary_Tree b;
  fstream file;
  file.open(argv[1],ios::in);
  if(!file){
    cout<<"Can not open input file!"<<endl;
    exit(1);
  }
  string input;
	file>>input;
  int size = stoi(input);
  node* a=NULL;
  for(int i=0;i<size;++i){
    file>>input;
    if(input=="traverse"){
      cout<<"Inorder traversing result: ";
      b.inorder_traverse(b.root_node());
      cout<<endl;
    }
    else if(input=="search"){
      file>>input;
      cout<<"Search "<<input<<" : ";
      if(b.search(stoi(input)))
        cout<<"found"<<endl;
      else
        cout<<"not found"<<endl;
    }
    else if(input=="max"){
      a=b.max(b.root_node());
      if(a){
        cout<<"Max: "<<a->key<<endl;
      }
      else{
        cout<<"Empty binary search tree"<<endl;
      }
    }
    else if(input=="min"){
      a=b.min(b.root_node());
      if(a){
        cout<<"Min: "<<a->key<<endl;
      }
      else{
        cout<<"Empty binary search tree"<<endl;
      }
    }
    else if(input=="predecessor"){
      file>>input;
      int number = stoi(input);
      a=b.predecessor(b.search(number));
      if(a)
        cout<<"Predecessor of "<<number<<" : "<<a->key<<endl;
      else
        cout<<"Don't have predecessor!"<<endl;
    }
    else if(input=="successor"){
      file>>input;
      int number = stoi(input);
      a=b.successor(b.search(number));
      if(a)
        cout<<"Successor of "<<number<<" : "<<a->key<<endl;
      else
        cout<<"Don't have successor!"<<endl;
    }
    else if(input=="insert"){
      file>>input;
      int number = stoi(input);
      b.insert_node(number);
      cout<<"Insert "<<number<<endl;
    }
    else if(input=="delete"){
      file>>input;
      int number = stoi(input);
      a=b.search(number);
      if(a){
        b.delete_node(a);
        cout<<"Delete "<<number<<endl;
      }
      else{
        cout<<"Can't find the element!"<<endl;
      }
    }
    else{
      cout<<"Wrong command!"<<endl;
      break;
    }

  }
  /*
  switch(input){
    case "traverse":

      break;
    case "search":

      break;
    case "max":

      break;
    case "min":

      break;
    case "predecessor":

      break;
    case "successor":

      break;
    case "insert":

      break;
    case "delete":

      break;
  }
  b.insert_node(3);
  b.insert_node(2);
  b.insert_node(1);
  b.insert_node(8);
  b.insert_node(7);
  cout<<"Inorder traversing result:"<<endl;
  b.inorder_traverse(b.root_node());
  b.delete_node(b.search(3));
  b.delete_node(b.search(8));
  cout<<"Inorder traversing result:"<<endl;
  b.inorder_traverse(b.root_node());*/
  return 0;
}

#include <iostream>
#include <utility>
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
      cout<<n->key<<endl;
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
  node* max(node* n){
    while(n->left!=NULL){
      n=n->left;
    }
    return n;
  }
  node* min(node* n){
    while(n->right!=NULL){
      n=n->right;
    }
    return n;
  }
  node* successor(const node* n){
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
    node* temp;
    if(n->left==NULL || n->right==NULL)
      temp=n;

    else
      temp=successor(n);

    if(temp->left!=NULL)
      n=temp->left;
    else
      n=temp->right;

    if(n!=NULL)
      n->parent=temp->parent;
    if(temp->parent==NULL)
      root=n;
    else if(temp==temp->parent->left)
      temp->parent->left=n;
    else
      temp->parent->right=n;

    if(temp!=n)
      n=move(temp);
  }
private:
  node* root;
};
int main(){
  Binary_Tree b;
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
  b.inorder_traverse(b.root_node());
  return 0;
}

#include <iostream>
using namespace std;

struct Node { int data; Node *l,*r; };
Node* newNode(int x){ return new Node{x,NULL,NULL}; }

void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->l);
    preorder(root->r);
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->l);
    cout<<root->data<<" ";
    inorder(root->r);
}
void postorder(Node* root){
    if(!root) return;
    postorder(root->l);
    postorder(root->r);
    cout<<root->data<<" ";
}

int main(){
    Node *root=newNode(1);
    root->l=newNode(2);
    root->r=newNode(3);
    root->l->l=newNode(4);
    root->l->r=newNode(5);
    preorder(root); cout<<endl;
    inorder(root); cout<<endl;
    postorder(root);
}

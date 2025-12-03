#include <iostream>
using namespace std;

struct Node{ int data; Node* l,*r; };
Node* newNode(int x){ return new Node{x,NULL,NULL}; }

bool isBST(Node* r,int mn,int mx){
    if(!r) return true;
    if(r->data<=mn || r->data>=mx) return false;
    return isBST(r->l,mn,r->data) && isBST(r->r,r->data,mx);
}

int main(){
    Node* root=newNode(8);
    root->l=newNode(3);
    root->r=newNode(10);
    root->l->l=newNode(1);
    root->l->r=newNode(6);
    cout<<isBST(root,-1e9,1e9);
}

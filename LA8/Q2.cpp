#include <iostream>
using namespace std;

struct Node { int data; Node *l,*r; };
Node* root=NULL;

Node* insert(Node* r,int x){
    if(!r) return new Node{x,NULL,NULL};
    if(x<r->data) r->l=insert(r->l,x);
    else r->r=insert(r->r,x);
    return r;
}

bool searchRec(Node* r,int x){
    if(!r) return false;
    if(r->data==x) return true;
    return x<r->data ? searchRec(r->l,x) : searchRec(r->r,x);
}
bool searchNonRec(Node* r,int x){
    while(r){
        if(r->data==x) return true;
        r = x<r->data ? r->l : r->r;
    }
    return false;
}

int maxNode(Node* r){
    while(r->r) r=r->r;
    return r->data;
}
int minNode(Node* r){
    while(r->l) r=r->l;
    return r->data;
}

Node* inorderSucc(Node* r,int x){
    Node* succ=NULL;
    while(r){
        if(x<r->data) succ=r, r=r->l;
        else r=r->r;
    }
    return succ;
}
Node* inorderPred(Node* r,int x){
    Node* pred=NULL;
    while(r){
        if(x>r->data) pred=r, r=r->r;
        else r=r->l;
    }
    return pred;
}

int main(){
    int a[]={50,30,70,20,40,60,80};
    for(int x:a) root=insert(root,x);
    cout<<searchRec(root,40)<<endl;
    cout<<searchNonRec(root,100)<<endl;
    cout<<maxNode(root)<<endl;
    cout<<minNode(root)<<endl;
    cout<<inorderSucc(root,60)->data<<endl;
    cout<<inorderPred(root,60)->data;
}

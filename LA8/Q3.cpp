#include <iostream>
using namespace std;

struct Node{ int data; Node* l,*r; };
Node* root=NULL;

Node* insert(Node* r,int x){
    if(!r) return new Node{x,NULL,NULL};
    if(x<r->data) r->l=insert(r->l,x);
    else if(x>r->data) r->r=insert(r->r,x);
    return r;
}

Node* getMin(Node* r){
    while(r->l) r=r->l;
    return r;
}

Node* del(Node* r,int x){
    if(!r) return r;
    if(x<r->data) r->l=del(r->l,x);
    else if(x>r->data) r->r=del(r->r,x);
    else{
        if(!r->l) return r->r;
        if(!r->r) return r->l;
        Node* m=getMin(r->r);
        r->data=m->data;
        r->r=del(r->r,m->data);
    }
    return r;
}

int maxDepth(Node* r){
    if(!r) return 0;
    return 1+max(maxDepth(r->l),maxDepth(r->r));
}
int minDepth(Node* r){
    if(!r) return 0;
    return 1+min(minDepth(r->l),minDepth(r->r));
}

int main(){
    int a[]={8,3,10,1,6,14,4,7,13};
    for(int x:a) root=insert(root,x);
    root=del(root,6);
    cout<<maxDepth(root)<<endl;
    cout<<minDepth(root);
}

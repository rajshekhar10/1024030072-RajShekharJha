#include <iostream>
using namespace std;

int h[100], sz=0;

void push(int x){
    int i=sz++;
    h[i]=x;
    while(i && h[(i-1)/2] < h[i]){
        swap(h[(i-1)/2],h[i]);
        i=(i-1)/2;
    }
}

int pop(){
    int r=h[0];
    h[0]=h[--sz];
    int i=0;
    while(true){
        int l=2*i+1,rn=2*i+2,m=i;
        if(l<sz && h[l]>h[m]) m=l;
        if(rn<sz && h[rn]>h[m]) m=rn;
        if(m==i) break;
        swap(h[i],h[m]);
        i=m;
    }
    return r;
}

int main(){
    push(40); push(10); push(50); push(30);
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    push(60);
    cout<<pop();
}

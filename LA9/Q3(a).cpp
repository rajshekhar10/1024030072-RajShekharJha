#include <bits/stdc++.h>
using namespace std;

int p[100];
int find(int x){ return p[x]==x ? x : p[x]=find(p[x]); }
void unite(int a, int b){ p[find(a)] = find(b); }

int main() {
    int n,e,u,v,w;
    cin>>n>>e;
    vector<tuple<int,int,int>> ed;
    while(e--) cin>>u>>v>>w, ed.push_back({w,u,v});
    sort(ed.begin(),ed.end());
    for(int i=0;i<n;i++) p[i]=i;
    for(auto &t:ed){
        tie(w,u,v)=t;
        if(find(u)!=find(v)){
            cout<<u<<" "<<v<<" "<<w<<"\n";
            unite(u,v);
        }
    }
}

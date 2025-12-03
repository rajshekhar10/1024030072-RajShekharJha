#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,e,u,v,w;
    cin>>n>>e;
    vector<pair<int,int>> g[n];
    while(e--) cin>>u>>v>>w, g[u].push_back({v,w}), g[v].push_back({u,w});
    vector<int> vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [wt,x]=pq.top(); pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        cout<<x<<" "<<wt<<"\n";
        for(auto &[y,c]:g[x])
            if(!vis[y]) pq.push({c,y});
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,e,u,v,w,s;
    cin>>n>>e;
    vector<pair<int,int>> g[n];
    while(e--) cin>>u>>v>>w, g[u].push_back({v,w});
    cin>>s;
    vector<int> d(n,1e9);
    d[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [dist,x] = pq.top(); pq.pop();
        if(dist != d[x]) continue;
        for(auto &[y,c]:g[x]){
            if(d[y] > dist + c){
                d[y] = dist + c;
                pq.push({d[y], y});
            }
        }
    }
    for(int i=0;i<n;i++) cout<<d[i]<<" ";
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e, u, v, s;
    cin >> n >> e;
    vector<int> g[n];
    while (e--) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> s;
    queue<int> q;
    vector<int> vis(n,0);
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        cout << x << " ";
        for (int i : g[x])
            if (!vis[i]) vis[i] = 1, q.push(i);
    }
}
